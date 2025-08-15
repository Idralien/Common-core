#ifndef IRCSERVER_HPP
# define IRCSERVER_HPP

# include "../IRCDependencies.hpp"

// Retreiving global variable from main
extern bool	g_server_running;

/*
 * Soft-depending
 */
class IRCUser;
class IRCChannel;
class CommandExecutor;

class IRCServer {

	private:
		/* Attributes */
		std::vector<pollfd>				_polls;
		std::map<int, IRCUser>				_users;
		std::map<std::string, IRCChannel*>	_channels;
		std::string						_creationDate;
		std::string						_hostname;
		std::string						_password;
		int								_port;
		int								_listenerSocket;
		std::string						_lastLogin;
		std::string						_lastLogout;
		CommandExecutor						*_executor;

		/* Private constructor */
		IRCServer(void);
		IRCServer(const IRCServer &origin);

		/* Private functions */
		std::string	_createTimestamp(void);
		int			_createSocket(void);
		bool		_createUserConnection(void);
		bool		_handleUserConnection(std::vector<pollfd>::iterator &it);
		bool		_handlePollOut(std::vector<pollfd>::iterator &it);
		void		_addUser(int fd, struct sockaddr_in userAddr);
		void		_removeUser(int fd, std::vector<pollfd>::iterator &it);
		void		_removeUserFromChannels(int fd);
		void		_removeEmptyChannels(void);
		void		_parseReceived(int fd, std::string message);
		void		_printServerInfos(void);

		/* Overloaded operators */
		IRCServer	&operator=(const IRCServer &origin);

	public:
		/* Constructors & Destructors */
		IRCServer(const std::string &hostname, int port, const std::string &password);
		~IRCServer(void);

		/* Functions */
		void							run(void);
		void							broadcast(std::string message);
		void							addChannel(IRCChannel *channel);
		void							removeChannel(std::string channelName);
		IRCUser							*findUserByFd(int fd);
		IRCUser							*findUserByName(std::string name);
		IRCChannel							*findChannelByName(std::string name);
		bool							isNicknameAvailable(std::string nickname);
		std::map<std::string, IRCChannel*>	getChannelsWhereUser(IRCUser *user);

		/* Getters & Setters */
		std::string	getCreationDate(void) const;
		std::string	getHostname(void) const;
		std::string	getPassword(void) const;
		int			getPort(void) const;
		int			getListenerSocket(void) const;

};

#endif
