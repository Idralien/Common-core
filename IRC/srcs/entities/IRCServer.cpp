#include "../../inc/entities/IRCServer.hpp"
#include <cstdio>

/* Constructors & Destructors */
IRCServer::IRCServer(void) {}

IRCServer::IRCServer(const std::string &hostname, int port, const std::string &password) {
	this->_creationDate = _createTimestamp();
	this->_hostname = hostname;
	this->_port = port;
	this->_password = password;
	this->_polls.reserve(MAX_CONNECTIONS + 1);
	this->_listenerSocket = _createSocket();
	this->_lastLogin = "nobody";
	this->_lastLogout = "nobody";
	this->_executor = new CommandExecutor(this);
}

IRCServer::IRCServer(const IRCServer &origin) {
	*this = origin;
}

IRCServer::~IRCServer(void) {
	g_server_running = false;
	while (!this->_polls.empty())
		this->_polls.pop_back();
	while (!this->_users.empty())
		this->_users.erase(this->_users.begin());
	for (std::map<std::string, IRCChannel*>::iterator it = this->_channels.begin(); it != this->_channels.end(); it++)
		delete it->second;
	this->_polls.clear();
	this->_users.clear();
	this->_channels.clear();
	delete this->_executor;
}

/* Private functions */
std::string	IRCServer::_createTimestamp(void) {
	time_t		time = std::time(0);
	struct tm	*localTime = localtime(&time);
	char		buffer[80]; // format string

	strftime(buffer, 80, "%a %b %d, %H:%M:%S UTC", localTime);
	return (IRCUtilities::toString(buffer));
}

int	IRCServer::_createSocket(void) {
	struct sockaddr_in	serverAddr; // using sockaddr_in for IPv4 only
	int					sock = socket(AF_INET, SOCK_STREAM, 0);

	if (sock < 0)
		throw std::runtime_error("Cannot open socket");
	memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = INADDR_ANY; // equivalent to 0.0.0.0
	serverAddr.sin_port = htons(this->_port);

	if (bind(sock, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0)
		throw std::runtime_error("Cannot bind socket");
	if (listen(sock, MAX_CONNECTIONS) < 0)
		throw std::runtime_error("Listen failed");
	return (sock);
}

bool	IRCServer::_createUserConnection(void) {
	struct sockaddr_in	userAddr;
	socklen_t			userAddrLen = sizeof(userAddr);
	int					userSocket = accept(this->_listenerSocket, (sockaddr *)&userAddr, &userAddrLen);

	if (userSocket < 0) {
		// Failure with accept() but still running server loop
		return (false);
	}
	if (this->_polls.size() - 1 >= MAX_CONNECTIONS) {
		// IRCServer is full
		std::string	message = std::string(SERVER_FULL_MSG);
		send(userSocket, message.c_str(), message.length(), 0);
		close(userSocket);
	} else {
		this->_addUser(userSocket, userAddr);
	}
	return (true);
}

bool	IRCServer::_handleUserConnection(std::vector<pollfd>::iterator &it) {
	static std::string	cachedBuffer;
	IRCUser				*user = findUserByFd(it->fd);
	std::string			message;
	char				buffer[4096];
	int					read;

	memset(buffer, 0, sizeof(buffer));
	read = recv(it->fd, buffer, 4096, 0);
	if (read < 0) {
		std::cerr << IRCUtilities::toString(SERVER_KO) << CRESET "An error occurred with recv(), ignoring..." CRESET << std::endl;
		this->_removeUser(it->fd, it);
		return (false);
	}
	if (read == 0) {
		// IRCUser disconnected
		this->_removeUser(it->fd, it);
		return (false);
	}
	message = IRCUtilities::toString(buffer);
	if (cachedBuffer.size() > 0)
		message = cachedBuffer.append(message);
	if (message.find('\n') == message.npos) {
		cachedBuffer = message;
		return (true);
	}
	// Should handle commands from here
	user->setReadBuffer(message);
	this->_parseReceived(it->fd, user->getReadBuffer()); // command handler inside this function
	cachedBuffer.clear();
	return (true);
}

void	IRCServer::_printServerInfos(void) {
    if (LOGS) return;
    
    // Clear screen and reset cursor
    std::cout << "\033[2J\033[H";
    
    // Professional header
    std::cout << BWHT << SERVER_NAME << " Server Monitor" << CRESET << "\n";
    std::cout << std::string(50, '-') << "\n\n";
    
    // Server info section with clean alignment
    printf("%-12s %s v%s\n", "Server:", SERVER_NAME, SERVER_VERSION);
    printf("%-12s %s:%d\n", "Address:", this->_hostname.c_str(), this->_port);
    printf("%-12s %s\n", "Started:", this->_creationDate.c_str());
    std::cout << std::string(50, ' ') << "\n";  // Add spacing
    printf("%-12s %s%lu/%d%s\n", "Users:", BCYN, this->_users.size(), MAX_CONNECTIONS, CRESET);
    printf("%-12s %s%lu%s\n\n", "Channels:", BCYN, this->_channels.size(), CRESET);
    
    // Connected users section with better spacing
    if (!this->_users.empty()) {
        std::cout << BWHT << "Active Connections" << CRESET << "\n";
        std::cout << std::string(50, '-') << "\n";
        
        // Clean table headers
        printf("%-5s  %-15s  %-15s  %s\n", "FD", "NICKNAME", "HOST", "STATUS");
        std::cout << std::string(50, '.') << "\n";
        
        // User list with improved formatting
        for (std::map<int, IRCUser>::iterator it = this->_users.begin(); it != this->_users.end(); ++it) {
            std::string status = it->second.isRegistered() ? BGRN "Connected" CRESET : BYEL "Connecting" CRESET;
            printf("%-5d  %-15s  %-15s  %s\n", 
                it->first,
                (it->second.getNickname().empty() ? "-" : it->second.getNickname().c_str()),
                it->second.getHost().c_str(),
                status.c_str());
        }
    }
    std::cout << std::endl;
}

bool	IRCServer::_handlePollOut(std::vector<pollfd>::iterator &it) {
	IRCUser	*user = findUserByFd(it->fd);

	if (!user) // no connection established, skipping
		return (true);
	if (!user->getSendBuffer().empty())
		this->_printServerInfos();
	user->sendBufferMessage();
	return (true);
}

void	IRCServer::_addUser(int fd, struct sockaddr_in userAddr) {
	pollfd		userPoll;
	std::string	userHost = IRCUtilities::toString(inet_ntoa(userAddr.sin_addr));
	IRCUser		userObj(userHost, ntohs(userAddr.sin_port), fd);

	userPoll.fd = fd;
	userPoll.events = POLLIN | POLLOUT;
	userPoll.revents = 0;
	this->_polls.push_back(userPoll);
	this->_users.insert(std::pair<int, IRCUser>(fd, userObj));
	/* Start of debug */
	LogManager::getInstance()->queue(IRCUtilities::toString(SERVER_INFO) + "Client " BCYN + IRCUtilities::toString(fd) + CRESET " connected.\n");
	/* End of debug */
	this->_lastLogin = IRCUtilities::toString(fd);
	this->_printServerInfos();
}

void	IRCServer::_removeUser(int fd, std::vector<pollfd>::iterator &it) {
	if (close(fd) < 0)
		std::cerr << IRCUtilities::toString(SERVER_KO) << BRED "close() error when removing user, continue..." CRESET << std::endl;
	this->_removeUserFromChannels(fd);
	this->_users.erase(fd);
	this->_polls.erase(it);
	/* Start of debug*/
	LogManager::getInstance()->queue(IRCUtilities::toString(SERVER_INFO) + "Client " BCYN + IRCUtilities::toString(fd) + CRESET " disconnected.\n");
	/* End of debug */
	this->_lastLogout = IRCUtilities::toString(fd);
	this->_printServerInfos();
}

void	IRCServer::_removeUserFromChannels(int fd) {
	IRCUser	*user = findUserByFd(fd);

	if (!user)
		return ;
	for (std::map<std::string, IRCChannel*>::iterator it = this->_channels.begin(); it != this->_channels.end(); it++) {
		IRCChannel	*channel = it->second;

		if (channel->isInChannel(user))
			channel->removeUser(user);
	}
}

void	IRCServer::_removeEmptyChannels(void) {
	std::map<std::string, IRCChannel*>::iterator	currentIt = this->_channels.begin();
	std::map<std::string, IRCChannel*>::iterator	nextIt;
	std::string									debugLog;
	int											removedChannels = 0;

	while (currentIt != this->_channels.end()) {
		nextIt = currentIt;
		++nextIt;

		IRCChannel *channel = currentIt->second;

		if (channel->getUsers().size() == 0) {
			delete channel;
			this->_channels.erase(currentIt++);
			removedChannels++;
		} else {
			currentIt = nextIt;
		}
	}
	if (removedChannels == 0)
		return ;
	/* Start of debug */
	debugLog.append(IRCUtilities::toString(SERVER_INFO) + "Removed " BCYN + IRCUtilities::toString(removedChannels) + CRESET " empty channel(s).\n");
	LogManager::getInstance()->queue(debugLog);
	/* End of debug */
	this->_printServerInfos();
}

void	IRCServer::_parseReceived(int fd, std::string message) {
	std::string				debugLog;
	std::deque<std::string>	commands;
	std::deque<std::string>	commandArgs;
	IRCUser					*user = findUserByFd(fd);

	commands = IRCUtilities::split(message, "\n\v");
	/* Start of debug*/
	debugLog.append(IRCUtilities::toString(SERVER_INFO) + "Handling " BCYN + IRCUtilities::toString(commands.size()) + CRESET " command(s) from " + IRCUtilities::toString(fd) + "...\n");
	/* End of debug */
	for (size_t i = 0; i < commands.size(); i++) {
		commandArgs = IRCUtilities::split(commands[i], " \t\r");
		/* Start of debug */
		debugLog.append(" - ARGS {");
		for (size_t i = 0; i < commandArgs.size(); i++)
			debugLog.append(BCYN + commandArgs[i] + CRESET + (i < commandArgs.size() - 1 ? ", " : ""));
		debugLog.append("}\n");
		/* End of debug */
		this->_executor->processCommand(user, commandArgs);
		if (!user->isRegistered())
			user->tryRegister(this);
		commandArgs.clear();
	}
	commands.clear();
	user->getReadBuffer().clear();
	/* Start of debug */
	LogManager::getInstance()->queue(debugLog);
	/* End of debug */
}

/* Functions */
void	IRCServer::run(void) {
	pollfd	serverPoll = {
		this->_listenerSocket, // specifies the file descriptor to monitor
		POLLIN | POLLOUT, // Data available to read & Writing now will not block
		0 // indicate which of those events actually occurred
	};

	if (fcntl(this->_listenerSocket, F_SETFL, O_NONBLOCK) < 0) // non-blocking socket
		throw std::runtime_error("Cannot manipulate fd");
	this->_polls.push_back(serverPoll);
	g_server_running = true;
	std::cout << IRCUtilities::toString(SERVER_OK) << "Ready to welcome users!" << std::endl;
	while (g_server_running) {
		std::vector<pollfd>::iterator	it = this->_polls.begin();
		int pollCount = poll(&(*it), this->_polls.size(), -1);

		if (g_server_running && pollCount < 0)
			throw std::runtime_error("Impossible to wait for some event");
		while (it != this->_polls.end()) {
			if (it->revents & POLLIN) {
				if (it->fd == this->_listenerSocket) {
					if (!this->_createUserConnection())
						continue ; // skipping if accept() fails
				} else {
					if (!this->_handleUserConnection(it))
						break ;
				}
			}
			else if (it->revents & POLLOUT) {
				if (!this->_handlePollOut(it)) // sending buffer to each client without blocking
					break ;
			}
			++it;
		}
		this->_removeEmptyChannels();
		LogManager::getInstance()->printQueue(); // printing debug queue
	}
	this->broadcast("IRCServer closed");
	std::cout << IRCUtilities::toString(SERVER_KO) << "IRCServer has successfully closed..." << std::endl;
}

void	IRCServer::broadcast(std::string message) {
	message = message.append("\r\n");

	for (std::map<int, IRCUser>::iterator it = this->_users.begin(); it != this->_users.end(); it++) {
		IRCUser	user = it->second;

		user.addSendBuffer(message);
		user.sendBufferMessage(); // force send message
	}
}

void	IRCServer::addChannel(IRCChannel *channel) {
	if (this->_channels.find(channel->getName()) != this->_channels.end())
		return ;
	this->_channels[channel->getName()] = channel;
}

void	IRCServer::removeChannel(std::string channelName) {
	std::map<std::string, IRCChannel*>::iterator	it = this->_channels.find(channelName);

	if (it == this->_channels.end())
		return ;
	this->_channels.erase(it);
}

IRCUser	*IRCServer::findUserByFd(int fd) {
	std::map<int, IRCUser>::iterator	it = this->_users.find(fd);

	if (it == this->_users.end())
		return (NULL);
	return (&it->second);
}

IRCUser	*IRCServer::findUserByName(std::string name) {
	for (std::map<int, IRCUser>::iterator it = this->_users.begin(); it != this->_users.end(); it++) {
		IRCUser	*user = &it->second;

		if (!user->getNickname().compare(name))
			return (user);
	}
	return (NULL);
}

IRCChannel	*IRCServer::findChannelByName(std::string name) {
	std::map<std::string, IRCChannel*>::iterator	it = this->_channels.find(name);

	if (it == this->_channels.end())
		return (NULL);
	return (it->second);
}

bool	IRCServer::isNicknameAvailable(std::string nickname) {
	for (std::map<int, IRCUser>::iterator it = this->_users.begin(); it != this->_users.end(); it++) {
		IRCUser	user = it->second;

		if (!user.getNickname().compare(nickname))
			return (false);
	}
	return (true);
}

std::map<std::string, IRCChannel*>	IRCServer::getChannelsWhereUser(IRCUser *user) {
	std::map<std::string, IRCChannel*>	channels;

	for (std::map<std::string, IRCChannel*>::iterator it = this->_channels.begin(); it != this->_channels.end(); it++) {
		IRCChannel	*channel = it->second;

		if (!channel->isInChannel(user))
			continue ;
		channels[channel->getName()] = channel;
	}
	return (channels);
}

/* Getters & Setters */
std::string	IRCServer::getCreationDate(void) const {
	return (this->_creationDate);
}

std::string	IRCServer::getHostname(void) const {
	return (this->_hostname);
}

std::string	IRCServer::getPassword(void) const {
	return (this->_password);
}

int	IRCServer::getPort(void) const {
	return (this->_port);
}

int	IRCServer::getListenerSocket(void) const {
	return (this->_listenerSocket);
}

/* Overloaded operators */
IRCServer	&IRCServer::operator=(const IRCServer &origin) {
	this->_polls = origin._polls;
	this->_users = origin._users;
	this->_channels = origin._channels;
	this->_creationDate = origin._creationDate;
	this->_hostname = origin._hostname;
	this->_password = origin._password;
	this->_port = origin._port;
	this->_lastLogin = origin._lastLogin;
	this->_lastLogout = origin._lastLogout;
	this->_listenerSocket = origin._listenerSocket;
	return (*this);
}
