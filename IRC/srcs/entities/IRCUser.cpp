#include "../../inc/entities/IRCUser.hpp"

/* Constructors & Destructors */
IRCUser::IRCUser(void) {}

IRCUser::IRCUser(std::string &host, int port, int socket) {
	this->_host = host;
	this->_nickname = "";
	this->_username = "";
	this->_realname = "";
	this->_readBuffer = "";
	this->_port = port;
	this->_socket = socket;
	this->_registered = false;
	this->_sentPassword = false;
}

IRCUser::IRCUser(IRCUser const &origin) {
	this->_host = origin.getHost();
	this->_nickname = origin.getNickname();
	this->_username = origin.getUsername();
	this->_realname = origin.getRealname();
	this->_readBuffer = origin.getReadBuffer();
	this->_port = origin.getPort();
	this->_socket = origin.getSocket();
	this->_registered = origin.isRegistered();
	this->_sentPassword = origin.hasSentPassword();
}

IRCUser::~IRCUser(void) {}

/* Functions */
void	IRCUser::tryRegister(IRCServer *server) {
	if (this->_registered)
		return ;
	if (!this->_sentPassword || this->_nickname.empty() || this->_username.empty() || this->_realname.empty())
		return ;
	std::string	userId = USER_IDENTIFIER(this->_nickname, this->_username);

	this->_registered = true;
	this->addSendBuffer(RPL_WELCOME(userId, this->_nickname));
	this->addSendBuffer(RPL_YOURHOST(userId, this->_nickname, SERVER_NAME, SERVER_VERSION));
	this->addSendBuffer(RPL_CREATED(userId, this->_nickname, server->getCreationDate()));
	(void) server; // voiding because compiler is dumb
}

void	IRCUser::sendBufferMessage(void) {
	std::istringstream	buffer(this->_sendBuffer);
	std::string			reply;
	std::string			debugLog;

	if (this->_sendBuffer.size() == 0)
		return ;
	if (send(this->_socket, this->_sendBuffer.c_str(), this->_sendBuffer.size(), 0) < 0)
		throw std::runtime_error("Cannot send bytes to user");
	/* Start of debug */
	debugLog.append(IRCUtilities::toString(USER_INFO) + "Sending " BCYN + IRCUtilities::toString(this->_sendBuffer.size()) + CRESET " bytes to " + IRCUtilities::toString(this->_socket) + "...\n");
	while (std::getline(buffer, reply))
	{
		std::string debugReply = IRCUtilities::removeEndOccurrence(reply, "\r\n");
		debugReply = IRCUtilities::removeEndOccurrence(debugReply, "\r");

		debugLog.append(" - SENT {" BCYN + debugReply + CRESET "}\n");
	}
	LogManager::getInstance()->queue(debugLog);
	/* End of debug */
	this->_sendBuffer.clear();
}

void	IRCUser::sendDirectMessage(std::string message) {
	std::string	debugLog;

	message = message.append("\r\n");
	if (send(this->_socket, message.c_str(), message.size(), 0) < 0)
		throw std::runtime_error("Cannot send bytes to user");
	/* Start of debug */
	debugLog.append(IRCUtilities::toString(USER_INFO) + BRED "[FORCE] " CRESET + "Sending " BCYN + IRCUtilities::toString(message.size()) + CRESET " bytes to " + IRCUtilities::toString(this->_socket) + "...\n");
	debugLog.append(" - SENT {" BCYN + IRCUtilities::removeEndOccurrence(message, "\r\n") + CRESET "}\n");
	LogManager::getInstance()->queue(debugLog);
	/* End of debug */
}

/* Getters & Setters */
std::string	IRCUser::getHost(void) const {
	return (this->_host);
}

std::string	IRCUser::getNickname(void) const {
	return (this->_nickname);
}

std::string	IRCUser::getUsername(void) const {
	return (this->_username);
}

std::string	IRCUser::getRealname(void) const {
	return (this->_realname);
}

std::string	IRCUser::getReadBuffer(void) const {
	return (this->_readBuffer);
}

std::string	IRCUser::getSendBuffer(void) const {
	return (this->_sendBuffer);
}

int	IRCUser::getPort(void) const {
	return (this->_port);
}

int	IRCUser::getSocket(void) const {
	return (this->_socket);
}

bool	IRCUser::isRegistered(void) const {
	return (this->_registered);
}

bool	IRCUser::hasSentPassword(void) const {
	return (this->_sentPassword);
}

void	IRCUser::setNickname(std::string const &nickname) {
	this->_nickname = nickname;
}

void	IRCUser::setUsername(std::string const &username) {
	this->_username = username;
}

void	IRCUser::setRealname(std::string const &realname) {
	this->_realname = realname;
}

void	IRCUser::setSentPassword(bool didSend) {
	this->_sentPassword = didSend;
}

void	IRCUser::setReadBuffer(std::string const &buffer) {
	this->_readBuffer = buffer;
}

void	IRCUser::setSendBuffer(std::string const &buffer) {
	this->_sendBuffer = buffer;
}

void	IRCUser::addSendBuffer(std::string buffer) {
	this->_sendBuffer += buffer;
}

/* Overloaded operators */
IRCUser	&IRCUser::operator=(IRCUser const &origin) {
	this->_host = origin.getHost();
	this->_nickname = origin.getNickname();
	this->_username = origin.getUsername();
	this->_realname = origin.getRealname();
	this->_readBuffer = origin.getReadBuffer();
	this->_port = origin.getPort();
	this->_socket = origin.getSocket();
	this->_registered = origin.isRegistered();
	this->_sentPassword = origin.hasSentPassword();
	return (*this);
}
