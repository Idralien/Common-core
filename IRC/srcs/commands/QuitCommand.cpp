#include "../../inc/commands/QuitCommand.hpp"

QuitCommand::QuitCommand(void) : BaseCommand("QUIT") {}

QuitCommand::~QuitCommand(void) {}

void	QuitCommand::execute(void) const {
	std::string	userId = USER_IDENTIFIER(this->_user->getNickname(), this->_user->getUsername());
	std::map<std::string, IRCChannel*>	channels = this->_server->getChannelsWhereUser(this->_user);

	if (channels.empty())
		return ;

	std::string	reason;
	for (size_t i = 1; i < this->_args.size(); i++) {
		if (!reason.empty())
			reason.append(" ");
		reason.append(this->_args[i]);
	}

	std::string	response = userId + " QUIT " + (reason.empty() ? ":Client Quit" : reason) + "\r\n";

	for (std::map<std::string, IRCChannel*>::iterator it = channels.begin(); it != channels.end(); it++) {
		IRCChannel	*channel = it->second;

		channel->broadcast(response);
	}
}
