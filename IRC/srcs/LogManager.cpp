#include "../inc/LogManager.hpp"

LogManager::LogManager(void) {}

LogManager::LogManager(const LogManager &origin) {
	*this = origin;
}

LogManager::~LogManager(void) {}

void	LogManager::queue(std::string message) {
	this->_queuedMessages.push_back(message);
}

void	LogManager::printQueue(void) {
	if (LOGS) {
		for (std::deque<std::string>::iterator it = this->_queuedMessages.begin(); it != this->_queuedMessages.end(); it++) {
			std::string	message = *it;
			std::cout << message;
		}
	}
	this->_queuedMessages.clear();
}

void	LogManager::destroy(void) {
	LogManager	*instance = getInstance();

	delete instance;
}

LogManager	&LogManager::operator=(const LogManager &origin) {
	this->_queuedMessages = origin._queuedMessages;
	return (*this);
}

LogManager	*LogManager::getInstance(void) {
	static LogManager	*instance = new LogManager();

	return (instance);
}
