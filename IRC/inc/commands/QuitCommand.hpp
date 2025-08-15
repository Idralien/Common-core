#ifndef QUITCOMMAND_HPP
# define QUITCOMMAND_HPP

# include "../IRCDependencies.hpp"

class QuitCommand : public BaseCommand {

	public:
		QuitCommand(void);
		~QuitCommand(void);

		void	execute(void) const;

};

#endif
