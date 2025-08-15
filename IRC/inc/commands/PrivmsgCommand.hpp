#ifndef PRIVMSGCOMMAND_HPP
# define PRIVMSGCOMMAND_HPP

# include "../IRCDependencies.hpp"

class PrivmsgCommand : public BaseCommand {

	private:
		bool		_sendChannelMessage(std::string channelName, std::string message) const;
		bool		_sendUserMessage(std::string nickName, std::string message) const;
		std::string	_getMessage(void) const;

	public:
		PrivmsgCommand(void);
		~PrivmsgCommand(void);

		void	execute(void) const;

};

#endif
