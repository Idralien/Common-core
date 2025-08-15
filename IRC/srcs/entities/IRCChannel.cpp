#include "../../inc/entities/IRCChannel.hpp"

/* Constructors & Destructors */
IRCChannel::IRCChannel(void) {}

IRCChannel::IRCChannel(std::string name) {
	this->_name = name;
	this->_key = "";
	this->_limit = 0;
	this->addMode('n');
}

IRCChannel::IRCChannel(IRCChannel const &origin) {
	*this = origin;
}

IRCChannel::~IRCChannel(void) {
	this->_users.clear();
	this->_operators.clear();
	this->_modes.clear();
	this->_inviteList.clear();
	this->_conversation.clear();
}

/* Functions */
void	IRCChannel::addMode(char mode) {
	if (std::find(this->_modes.begin(), this->_modes.end(), mode) != this->_modes.end())
		return ;
	this->_modes.push_back(mode);
}

void	IRCChannel::removeMode(char mode) {
	if (std::find(this->_modes.begin(), this->_modes.end(), mode) == this->_modes.end())
		return ;
	for (std::vector<char>::iterator it = this->_modes.begin(); it != this->_modes.end(); it++) {
		if (*it == mode) {
			this->_modes.erase(it);
			return ;
		}
	}
}

void	IRCChannel::addUser(IRCUser *user) {
	if (std::find(this->_users.begin(), this->_users.end(), user) != this->_users.end())
		return ;
	this->_users.push_back(user);
}

void	IRCChannel::removeUser(IRCUser *user) {
	if (std::find(this->_users.begin(), this->_users.end(), user) == this->_users.end())
		return ;
	for (std::vector<IRCUser*>::iterator it = this->_users.begin(); it != this->_users.end(); it++) {
		if (*it == user) {
			this->_users.erase(it);
			return ;
		}
	}
}

void	IRCChannel::addOperator(IRCUser *user) {
	if (std::find(this->_operators.begin(), this->_operators.end(), user) != this->_operators.end())
		return ;
	this->_operators.push_back(user);
}

void	IRCChannel::removeOperator(IRCUser *user) {
	if (std::find(this->_operators.begin(), this->_operators.end(), user) == this->_operators.end())
		return ;
	for (std::vector<IRCUser*>::iterator it = this->_operators.begin(); it != this->_operators.end(); it++) {
		if (*it == user) {
			this->_operators.erase(it);
			return ;
		}
	}
}

void	IRCChannel::addInvitation(IRCUser *user) {
	if (std::find(this->_inviteList.begin(), this->_inviteList.end(), user->getNickname()) != this->_inviteList.end())
		return ;
	this->_inviteList.push_back(user->getNickname());
}

void	IRCChannel::removeInvitation(IRCUser *user) {
	std::vector<std::string>::iterator	it = std::find(this->_inviteList.begin(), this->_inviteList.end(), user->getNickname());

	if (it == this->_inviteList.end())
		return ;
	this->_inviteList.erase(it);
}

void	IRCChannel::broadcast(std::string message) {
	for (std::vector<IRCUser*>::iterator it = this->_users.begin(); it != this->_users.end(); it++) {
		IRCUser	*user = *it;

		// adding message to user send buffer
		user->addSendBuffer(message);
	}
}

void	IRCChannel::excludeBroadcast(std::string message, IRCUser *excluded) {
	for (std::vector<IRCUser*>::iterator it = this->_users.begin(); it != this->_users.end(); it++) {
		IRCUser	*user = *it;

		if (!user->getNickname().compare(excluded->getNickname()))
			continue ;
		// adding message to user send buffer
		user->addSendBuffer(message);
	}
}

/* Getters */
std::string	IRCChannel::getKey(void) const {
	return (this->_key);
}

std::string	IRCChannel::getName(void) const {
	return (this->_name);
}

std::string	IRCChannel::getTopic(void) const {
	return (this->_topic);
}

std::string	IRCChannel::getModeString(void) const {
	std::string modeString = "+";

	for (size_t i = 0; i < this->_modes.size(); i++)
		modeString.push_back(this->_modes.at(i));
	if (this->hasMode('k'))
		modeString.append(" " + this->_key);
	if (this->hasMode('l'))
		modeString.append(" " + IRCUtilities::toString(this->_limit));
	return (modeString);
}

std::vector<char>	IRCChannel::getModes(void) const {
	return (this->_modes);
}

std::vector<IRCUser*>	IRCChannel::getUsers(void) const {
	return (this->_users);
}

std::vector<IRCUser*>	IRCChannel::getOperators(void) const {
	return (this->_operators);
}

std::vector<std::string>	IRCChannel::getConversation(void) const {
	return (this->_conversation);
}

unsigned int	IRCChannel::getLimit() const {
	return (this->_limit);
}

IRCUser	*IRCChannel::getOwner(void) const {
	return (this->_owner);
}

bool	IRCChannel::isOperator(IRCUser *user) {
	if (std::find(this->_operators.begin(), this->_operators.end(), user) != this->_operators.end())
		return (true);
	return (false);
}

bool	IRCChannel::isInChannel(IRCUser *user) {
	if (std::find(this->_users.begin(), this->_users.end(), user) != this->_users.end())
		return (true);
	return (false);
}

bool	IRCChannel::isKeyProtected(void) const {
	return (!this->_key.empty());
}

bool	IRCChannel::hasMode(char mode) const {
	return (std::find(this->_modes.begin(), this->_modes.end(), mode) != this->_modes.end());
}

bool	IRCChannel::isInvited(IRCUser *user) const {
	return (std::find(this->_inviteList.begin(), this->_inviteList.end(), user->getNickname()) != this->_inviteList.end());
}

/* Setters */
void	IRCChannel::setKey(std::string key) {
	this->_key = key;
}

void	IRCChannel::setTopic(std::string topic) {
	this->_topic = topic;
}

void	IRCChannel::setLimit(unsigned int limit) {
	this->_limit = limit;
}

void	IRCChannel::setOwner(IRCUser *owner) {
	this->_owner = owner;
}

/* Overloaded operators */
IRCChannel	&IRCChannel::operator=(IRCChannel const &origin) {
	this->_name = origin._name;
	this->_topic = origin._topic;
	this->_modes = origin._modes;
	this->_users = origin._users;
	this->_operators = origin._operators;
	this->_conversation = origin._conversation;
	this->_limit = origin._limit;
	this->_owner = origin._owner;
	return (*this);
}
