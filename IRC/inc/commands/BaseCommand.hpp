#ifndef BASECOMMAND_HPP
# define BASECOMMAND_HPP

# include "../IRCDependencies.hpp"

class BaseCommand {

	protected:
		std::string					_name;
		std::deque<std::string>		_aliases;
		std::deque<std::string>		_args;
		std::string					_calledCommand;
		IRCUser						*_user;
		IRCServer						*_server;

		BaseCommand(void);

	public:
		BaseCommand(std::string name);
		BaseCommand(BaseCommand const &origin);
		virtual ~BaseCommand(void);

		std::string				getName(void) const;
		std::string				getCalledCommand(void) const;
		std::deque<std::string>	getAliases(void) const;

		void	setArgs(std::deque<std::string> args);
		void	setUser(IRCUser *user);
		void	setServer(IRCServer *server);
		void	setCalledCommand(std::string calledCommand);
		void	addAlias(std::string alias);

		bool	hasAlias(std::string alias) const;

		virtual void	execute(void) const = 0;

		BaseCommand	&operator=(BaseCommand const &origin);

};

#endif
