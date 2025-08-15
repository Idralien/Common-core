#ifndef IRCCHANNEL_HPP
# define IRCCHANNEL_HPP

# include "../IRCDependencies.hpp"

class IRCUser;

class IRCChannel {

	private:
		/* Attributes */
		std::string					_name;
		std::string					_key;
		std::string					_topic;
		std::vector<char>			_modes;
		std::vector<IRCUser*>			_users;
		std::vector<IRCUser*>			_operators;
		std::vector<std::string>	_inviteList;
		std::vector<std::string>	_conversation;
		unsigned int				_limit;
		IRCUser						*_owner;

		/* Private constructors & destructors */
		IRCChannel(void);

	public:
		/* Constructors & Destructors */
		IRCChannel(std::string name);
		IRCChannel(IRCChannel const &origin);
		~IRCChannel(void);

		/* Functions */
		void	addMode(char mode);
		void	removeMode(char mode);
		void	addUser(IRCUser *user);
		void	removeUser(IRCUser *user);
		void	addOperator(IRCUser *user);
		void	removeOperator(IRCUser *user);
		void	addInvitation(IRCUser *user);
		void	removeInvitation(IRCUser *user);
		void	broadcast(std::string message);
		void	excludeBroadcast(std::string message, IRCUser *excluded);

		/* Getters */
		std::string					getName(void) const;
		std::string					getKey(void) const;
		std::string					getTopic(void) const;
		std::string					getModeString(void) const;
		std::vector<char>			getModes(void) const;
		std::vector<IRCUser*>			getUsers(void) const;
		std::vector<IRCUser*>			getOperators(void) const;
		std::vector<std::string>	getConversation(void) const;
		unsigned int				getLimit(void) const;
		IRCUser						*getOwner(void) const;
		bool						isOperator(IRCUser *user);
		bool						isInChannel(IRCUser *user);
		bool						isKeyProtected(void) const;
		bool						hasMode(char mode) const;
		bool						isInvited(IRCUser *user) const;

		/* Setters */
		void	setKey(std::string key);
		void	setTopic(std::string topic);
		void	setLimit(unsigned int limit);
		void	setOwner(IRCUser *owner);

		/* Overloaded operators */
		IRCChannel	&operator=(IRCChannel const &origin);

};

#endif
