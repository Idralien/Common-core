#ifndef IRCDEPENDENCIES_HPP
# define IRCDEPENDENCIES_HPP

# include <iostream>
# include <sstream>
# include <iomanip>
# include <ctime>
# include <cstring>
# include <algorithm>
# include <map>
# include <vector>
# include <deque>
# include <list>
# include <sys/socket.h>
# include <sys/types.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <fcntl.h>
# include <poll.h>
# include <unistd.h>
# include <signal.h>
# include <stddef.h>

# include "NumericResponses.hpp"
# include "IRCUtilities.hpp"
# include "entities/IRCUser.hpp"
# include "entities/IRCChannel.hpp"
# include "entities/IRCServer.hpp"
# include "commands/BaseCommand.hpp"
# include "CommandExecutor.hpp"
# include "LogManager.hpp"

# define BRED	"\033[1;31m"
# define BGRN	"\033[1;32m"
# define BYEL	"\033[1;33m"
# define BBLU	"\033[1;34m"
# define BMAG	"\033[1;35m"
# define BCYN	"\033[1;36m"
# define BWHT	"\033[1;37m"
# define CRESET	"\033[0m"

# define MAX_CONNECTIONS    10
# define SERVER_NAME		"IRC s19"
# define SERVER_VERSION		"1.0"

# define SERVER_OK          BGRN "[IRC s19] " CRESET
# define SERVER_INFO        BYEL "[IRC s19] " CRESET
# define SERVER_KO          BRED "[IRC s19] " CRESET
# define USER_OK            BGRN "[User] " CRESET
# define USER_INFO          BYEL "[User] " CRESET
# define USER_KO            BRED "[User] " CRESET

# define ENTER_PASS_FIRST   BRED "Please enter the password first." CRESET
# define SERVER_FULL_MSG	BRED "Server is full!" CRESET

# ifndef LOGS
#  define LOGS false
# endif

#endif
