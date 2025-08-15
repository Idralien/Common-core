#include "../../inc/commands/BaseCommand.hpp"

BaseCommand::BaseCommand(void) {}

BaseCommand::BaseCommand(std::string name) {
	this->_name = name;
	this->_aliases = std::deque<std::string>();
	this->_calledCommand = "";
	this->_user = NULL;
	this->_server = NULL;
}

BaseCommand::BaseCommand(BaseCommand const &origin) {
	*this = origin;
}

BaseCommand::~BaseCommand(void) {
	while (!this->_args.empty())
		this->_args.erase(this->_args.begin());
	while (!this->_aliases.empty())
		this->_aliases.erase(this->_aliases.begin());
	this->_args.clear();
	this->_aliases.clear();
}

std::string	BaseCommand::getName(void) const {
	return (this->_name);
}

std::string	BaseCommand::getCalledCommand(void) const {
	return (this->_calledCommand);
}

std::deque<std::string>	BaseCommand::getAliases(void) const {
	return (this->_aliases);
}

void	BaseCommand::setArgs(std::deque<std::string> args) {
	this->_args = args;
}

void	BaseCommand::setUser(IRCUser *user) {
	this->_user = user;
}

void	BaseCommand::setServer(IRCServer *server) {
	this->_server = server;
}

void	BaseCommand::setCalledCommand(std::string calledCommand) {
	this->_calledCommand = calledCommand;
}

void	BaseCommand::addAlias(std::string aliase) {
	this->_aliases.push_back(aliase);
}

bool	BaseCommand::hasAlias(std::string alias) const {
	if (std::find(this->_aliases.begin(), this->_aliases.end(), alias) == this->_aliases.end())
		return (false);
	return (true);
}

BaseCommand	&BaseCommand::operator=(BaseCommand const &origin) {
	this->_name = origin._name;
	this->_aliases = origin._aliases;
	this->_args = origin._args;
	this->_calledCommand = origin._calledCommand;
	this->_user = origin._user;
	this->_server = origin._server;
	return (*this);
}
