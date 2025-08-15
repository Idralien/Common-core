#ifndef JOINCOMMAND_HPP
# define JOINCOMMAND_HPP

# include "../IRCDependencies.hpp"

class JoinCommand : public BaseCommand {

	private:
		std::string	_getStringifiedUsers(IRCChannel *channel) const;
		std::string	_getChannelMode(IRCChannel *channel) const;
		void		_leaveAllChannels(void) const;

	public:
		JoinCommand(void);
		~JoinCommand(void);

		void	execute(void) const;

};

#endif
