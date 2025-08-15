#ifndef COMMANDEXECUTOR_HPP
# define COMMANDEXECUTOR_HPP

# include "commands/BaseCommand.hpp"

class BaseCommand;

class CommandExecutor {

	private:
		IRCServer					*_server;
		std::deque<BaseCommand*>	_commands;

		CommandExecutor(void);

		void	_registerCommands(void);
		bool	_isRegisteredCommand(std::string command);

	public:
		CommandExecutor(IRCServer *server);
		CommandExecutor(CommandExecutor const &origin);
		~CommandExecutor(void);

		void	processCommand(IRCUser *user, std::deque<std::string> commandArgs);

		CommandExecutor	&operator=(CommandExecutor const &origin);

};

#endif
