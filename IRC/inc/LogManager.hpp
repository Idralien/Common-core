#ifndef LOGMANAGER_HPP
# define LOGMANAGER_HPP

# include "IRCDependencies.hpp"

class LogManager {

	private:
		std::deque<std::string>	_queuedMessages;

		LogManager(void);
		LogManager(const LogManager &origin);

		LogManager	&operator=(const LogManager &origin);

	public:
		~LogManager(void);

		void	queue(std::string message);
		void	printQueue(void);
		void	destroy(void);

		static LogManager	*getInstance(void);

};

#endif
