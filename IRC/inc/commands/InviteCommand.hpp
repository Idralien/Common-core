#ifndef INVITECOMMAND_HPP
# define INVITECOMMAND_HPP

# include "../IRCDependencies.hpp"

class InviteCommand : public BaseCommand {

	public:
		InviteCommand(void);
		~InviteCommand(void);

		void	execute(void) const;

};

#endif
