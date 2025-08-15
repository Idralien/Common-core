#ifndef IRCUTILITIES_HPP
# define IRCUTILITIES_HPP

# include "IRCDependencies.hpp"

class IRCUtilities {

	private:

	public:
		static int								stoi(std::string &s);
		static std::string						fixWidth(std::string str, int truncateAt);
		static std::string						removeEndOccurrence(std::string str, std::string find);
		static std::deque<std::string>			split(std::string message, std::string delimiters);
		template <class T> static std::string	toString(const T &value) {
			std::ostringstream oss;

			oss << value;
			return (oss.str());
		}

};

#endif
