#include "../inc/IRCUtilities.hpp"

int	IRCUtilities::stoi(std::string &s) {
	int i;

	std::istringstream(s) >> i;
	return (i);
}

std::string	IRCUtilities::fixWidth(std::string str, int truncateAt) {
	if (static_cast<int>(str.length()) > truncateAt) {
		str = str.substr(0, 9);
		str.push_back('.');
	}
	return (str);
}

std::string	IRCUtilities::removeEndOccurrence(std::string str, std::string find) {
	while (!str.empty() && str.length() >= find.length()) {
		size_t pos = str.size() - find.size();
		if (str.substr(pos) != find)
			break;
		str.erase(pos, find.size());
	}
	return (str);
}

std::deque<std::string>	IRCUtilities::split(std::string message, std::string delimiters) {
	std::deque<std::string>		args;
	std::string					token;
	size_t						pos = 0;

	while ((pos = message.find_first_of(delimiters)) != std::string::npos) {
		token = message.substr(0, pos);

		if (!token.empty())
			args.push_back(token);
		message.erase(0, pos + 1);
	}
	if (!message.empty())
		args.push_back(message);
	return (args);
}
