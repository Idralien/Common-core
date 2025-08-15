#ifndef PINGCOMMAND_HPP
# define PINGCOMMAND_HPP

# include "../IRCDependencies.hpp"

class PingCommand : public BaseCommand {

	public:
		PingCommand(void);
		~PingCommand(void);

		void	execute(void) const;

};

#endif
