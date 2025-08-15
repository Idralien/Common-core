#ifndef TOPICCOMMAND_HPP
# define TOPICCOMMAND_HPP

# include "../IRCDependencies.hpp"

class TopicCommand : public BaseCommand {

	public:
		TopicCommand(void);
		~TopicCommand(void);

		void	execute(void) const;

};

#endif
