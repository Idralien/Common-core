#include "../inc/CommandExecutor.hpp"
#include "../inc/commands/PassCommand.hpp"
#include "../inc/commands/NickCommand.hpp"
#include "../inc/commands/UserCommand.hpp"
#include "../inc/commands/PingCommand.hpp"
#include "../inc/commands/CapCommand.hpp"
#include "../inc/commands/JoinCommand.hpp"
#include "../inc/commands/PrivmsgCommand.hpp"
#include "../inc/commands/KickCommand.hpp"
#include "../inc/commands/InviteCommand.hpp"
#include "../inc/commands/TopicCommand.hpp"
#include "../inc/commands/ModeCommand.hpp"
#include "../inc/commands/PartCommand.hpp"
#include "../inc/commands/QuitCommand.hpp"

CommandExecutor::CommandExecutor(void) {}

CommandExecutor::CommandExecutor(IRCServer *server) {
	this->_server = server;
	this->_registerCommands();
}

CommandExecutor::CommandExecutor(CommandExecutor const &origin) {
	*this = origin;
}

CommandExecutor::~CommandExecutor(void) {
	for (std::deque<BaseCommand*>::iterator it = this->_commands.begin(); it != this->_commands.end(); it++)
		delete *it;
	this->_commands.clear();
}

void	CommandExecutor::_registerCommands(void) {
	this->_commands.push_back(new PassCommand());
	this->_commands.push_back(new NickCommand());
	this->_commands.push_back(new UserCommand());
	this->_commands.push_back(new PingCommand());
	this->_commands.push_back(new CapCommand());
	this->_commands.push_back(new JoinCommand());
	this->_commands.push_back(new PrivmsgCommand());
	this->_commands.push_back(new KickCommand());
	this->_commands.push_back(new InviteCommand());
	this->_commands.push_back(new TopicCommand());
	this->_commands.push_back(new ModeCommand());
	this->_commands.push_back(new PartCommand());
	this->_commands.push_back(new QuitCommand());
}

bool	CommandExecutor::_isRegisteredCommand(std::string input) {
	for (std::deque<BaseCommand*>::iterator it = this->_commands.begin(); it != this->_commands.end(); it++) {
		BaseCommand	*command = *it;

		if (!command->getName().compare(input) || command->hasAlias(input))
			return (true);
	}
	return (false);
}

void	CommandExecutor::processCommand(IRCUser *user, std::deque<std::string> commandArgs) {
	std::string	commandName;

	if (commandArgs.empty() || !this->_isRegisteredCommand(commandArgs[0]))
		return ;
	commandName = commandArgs[0];
	for (std::deque<BaseCommand*>::iterator it = this->_commands.begin(); it != this->_commands.end(); it++) {
		BaseCommand	*command = *it;

		if (!command->getName().compare(commandName) || command->hasAlias(commandName)) {
			command->setServer(this->_server);
			command->setUser(user);
			command->setArgs(commandArgs);
			command->setCalledCommand(commandName);
			try {
				command->execute();
			} catch (std::string message) {
				user->addSendBuffer(message);
			} catch (char const* message) {
				user->addSendBuffer(message);
			}
			break ;
		}
	}
}

CommandExecutor	&CommandExecutor::operator=(CommandExecutor const &origin) {
	this->_server = origin._server;
	this->_commands = origin._commands;
	return (*this);
}
