#ifndef PASSCOMMAND_HPP
# define PASSCOMMAND_HPP

# include "../IRCDependencies.hpp"

class PassCommand : public BaseCommand {

	public:
		PassCommand(void);
		~PassCommand(void);

		void	execute(void) const;

};

#endif
