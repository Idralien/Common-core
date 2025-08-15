#include "../../inc/commands/KickCommand.hpp"

KickCommand::KickCommand(void) : BaseCommand("KICK") {}

KickCommand::~KickCommand(void) {}

void	KickCommand::execute(void) const {
	std::string	userId = USER_IDENTIFIER(this->_user->getNickname(), this->_user->getUsername());

	if (this->_args.size() < 4)
		throw ERR_NEEDMOREPARAMS(userId, this->_user->getNickname(), this->_name);

	IRCChannel	*channel = this->_server->findChannelByName(this->_args[1]);

	if (!channel)
		throw ERR_NOSUCHCHANNEL(userId, this->_user->getNickname(), this->_args[1]);
	if (!channel->isOperator(this->_user))
		throw ERR_CHANOPRIVSNEEDED(userId, this->_user->getNickname(), channel->getName());

	std::string	target = this->_args[2];
	IRCUser	*targetUser = this->_server->findUserByName(target);

	if (!targetUser)
		throw ERR_NOSUCHNICK(userId, this->_user->getNickname(), target);
	if (!channel->isInChannel(targetUser))
		throw ERR_USERNOTINCHANNEL(userId, this->_user->getNickname(), channel->getName(), target);

	std::string response = userId + " KICK " + channel->getName() + " " + targetUser->getNickname() + " :" + this->_args[3] + "\r\n";

	channel->broadcast(response);
	channel->removeUser(targetUser);
}
