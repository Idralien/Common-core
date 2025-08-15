#ifndef USERCOMMAND_HPP
# define USERCOMMAND_HPP

# include "../IRCDependencies.hpp"

class UserCommand : public BaseCommand {

	private:
		std::string	_extractRealname(std::deque<std::string> args) const;

	public:
		UserCommand(void);
		~UserCommand(void);

		void	execute(void) const;

};

#endif
