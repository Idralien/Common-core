#ifndef MODECOMMAND_HPP
# define MODECOMMAND_HPP

# include "../IRCDependencies.hpp"

class ModeCommand : public BaseCommand {

	private:
		bool		_addMode(IRCChannel *channel) const;
		bool		_removeMode(IRCChannel *channel) const;

	public:
		ModeCommand(void);
		~ModeCommand(void);

		void	execute(void) const;

};

#endif
