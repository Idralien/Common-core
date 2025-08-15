#ifndef KICKCOMMAND_HPP
# define KICKCOMMAND_HPP

# include "../IRCDependencies.hpp"

class KickCommand : public BaseCommand {

	public:
		KickCommand(void);
		~KickCommand(void);

		void	execute(void) const;

};

#endif
