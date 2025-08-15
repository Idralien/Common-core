#ifndef NICKCOMMAND_HPP
# define NICKCOMMAND_HPP

# include "../IRCDependencies.hpp"

class NickCommand : public BaseCommand {

	private:
		bool	_isValidCharacter(char c) const;
		bool	_isValidNickname(std::string nickname) const;

	public:
		NickCommand(void);
		~NickCommand(void);

		void	execute(void) const;

};

#endif
