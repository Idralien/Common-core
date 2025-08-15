#include "../../inc/commands/PingCommand.hpp"

PingCommand::PingCommand(void) : BaseCommand("PING") {}

PingCommand::~PingCommand(void) {}

void	PingCommand::execute(void) const {
	std::string	userId = USER_IDENTIFIER(this->_user->getNickname(), this->_user->getUsername());

	if (this->_args.size() < 1)
		throw ERR_NEEDMOREPARAMS(userId, this->_user->getNickname(), this->_name);

	std::string	response = userId + " PONG :" + this->_user->getNickname() + "\r\n";

	this->_user->addSendBuffer(response);
}
