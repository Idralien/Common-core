#ifndef IRCUSER_HPP
# define IRCUSER_HPP

# include "../IRCDependencies.hpp"

/*
 * Soft-depending IRCServer class.
 */
class IRCServer;

class IRCUser {

	private:
		/* Attributes */
		std::string	_host;
		std::string	_nickname;
		std::string	_username;
		std::string	_realname;
		std::string	_readBuffer;
		std::string	_sendBuffer;
		int			_port;
		int			_socket;
		bool		_registered;
		bool		_sentPassword;

		/* Private constructor */
		IRCUser(void);

	public:
		/* Constructors & Destructors */
		IRCUser(std::string &host, int port, int socket);
		IRCUser(IRCUser const &origin);
		~IRCUser(void);

		/* Functions */
		void	tryRegister(IRCServer *server);
		void	sendBufferMessage(void);
		void	sendDirectMessage(std::string message);

		/* Getters & Setters */
		std::string	getHost(void) const;
		std::string	getNickname(void) const;
		std::string	getUsername(void) const;
		std::string	getRealname(void) const;
		std::string	getReadBuffer(void) const;
		std::string	getSendBuffer(void) const;
		int			getPort(void) const;
		int			getSocket(void) const;
		bool		isRegistered(void) const;
		bool		hasSentPassword(void) const;
		void		setNickname(std::string const &nickname);
		void		setUsername(std::string const &username);
		void		setRealname(std::string const &realname);
		void		setSentPassword(bool didSend);
		void		setReadBuffer(std::string const &buffer);
		void		setSendBuffer(std::string const &buffer);
		void		addSendBuffer(std::string buffer);

		/* Overloaded operators */
		IRCUser	&operator=(IRCUser const &origin);

};

#endif
