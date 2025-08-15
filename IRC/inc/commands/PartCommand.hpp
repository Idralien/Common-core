#ifndef PARTCOMMAND_HPP
# define PARTCOMMAND_HPP

# include "../IRCDependencies.hpp"

class PartCommand : public BaseCommand {

	public:
		PartCommand(void);
		~PartCommand(void);

		void	execute(void) const;

};

#endif
