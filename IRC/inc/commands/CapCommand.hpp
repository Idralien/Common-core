#ifndef CAPCOMMAND_HPP
# define CAPCOMMAND_HPP

# include "../IRCDependencies.hpp"

class CapCommand : public BaseCommand {

	public:
		CapCommand(void);
		~CapCommand(void);

		void	execute(void) const;

};

#endif
