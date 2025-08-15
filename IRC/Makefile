#==============================================================================
# IRC SERVER MAKEFILE
#==============================================================================

# Project information
VERSION         = 1.0.0
DATE            = $(shell date "+%Y-%m-%d %H:%M:%S")
AUTHOR          = "quvan-de"
NAME            = ircserv

#==============================================================================
# Terminal colors and formatting
#==============================================================================
# Basic colors
RESET           = \033[0m
BOLD            = \033[1m
BLACK           = \033[30m
RED             = \033[31m
GREEN           = \033[32m
YELLOW          = \033[33m
BLUE            = \033[34m
MAGENTA         = \033[35m
CYAN            = \033[36m
WHITE           = \033[37m

# Advanced colors
PURPLE          = \033[38;5;141m
LIME            = \033[38;5;46m
GREY            = \033[38;5;240m
ORANGE          = \033[38;5;208m

# Background colors
BG_BLACK        = \033[40m
BG_RED          = \033[41m
BG_GREEN        = \033[42m
BG_BLUE         = \033[44m
BG_PURPLE       = \033[45m

# Terminal control
CLEAR           = \r\033[K
CLEAR_ALL       = \033[2J\033[1;1H

#==============================================================================
# Compiler and flags
#==============================================================================
CC              = c++
CFLAGS          = -Wall -Wextra -Werror -std=c++98 -pedantic -ggdb3
ifdef DEBUG
    CFLAGS  += -fsanitize=leak
endif
INCLUDES        = -I./inc
RM              = rm -rf

#==============================================================================
# Source files and directories
#==============================================================================
SRC_DIR         = ./srcs/
OBJ_DIR         = ./objs/

# Entity source files
ENTITY_SRCS     = entities/IRCUser.cpp \
                  entities/IRCServer.cpp \
                  entities/IRCChannel.cpp

# Command source files
COMMAND_SRCS    = commands/BaseCommand.cpp \
                  commands/PassCommand.cpp \
                  commands/NickCommand.cpp \
                  commands/UserCommand.cpp \
                  commands/PingCommand.cpp \
                  commands/KickCommand.cpp \
                  commands/InviteCommand.cpp \
                  commands/TopicCommand.cpp \
                  commands/ModeCommand.cpp \
                  commands/CapCommand.cpp \
                  commands/JoinCommand.cpp \
                  commands/PrivmsgCommand.cpp \
                  commands/PartCommand.cpp \
                  commands/QuitCommand.cpp

# Core source files
CORE_SRCS       = CommandExecutor.cpp \
                  LogManager.cpp \
                  IRCUtilities.cpp \
                  main.cpp

# Combined sources
SRCS            = $(ENTITY_SRCS) $(COMMAND_SRCS) $(CORE_SRCS)

# Generate object file paths
OBJS            = $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))
DEPS            = $(OBJS:.o=.d)

# Object count for progress display
TOTAL_OBJS      = $(words $(SRCS))
CURRENT_OBJ     = 0

#==============================================================================
# Build configuration options
#==============================================================================
# Enable logging
ifdef LOGS
    CFLAGS      += -D LOGS=true
    BUILD_TYPE   = "Logging Enabled"
else ifdef DEBUG
    BUILD_TYPE   = "Debug Build"
else
    BUILD_TYPE   = "Release Build"
endif

# Dependency generation flag
CFLAGS          += -MMD -MP

#==============================================================================
# Build rules
#==============================================================================
# Default target
all: banner $(NAME)

# Print banner with build info
banner:
	@printf "${CLEAR_ALL}"
	@printf "${BLUE}╔══════════════════════════════════════════════════════════════════╗${RESET}\n"
	@printf "${BLUE}║ ${PURPLE}${BOLD}IRC SERVER${RESET}                                                       ${BLUE}║${RESET}\n"
	@printf "${BLUE}╟──────────────────────────────────────────────────────────────────╢${RESET}\n"
	@printf "${BLUE}║ ${RESET}Version: ${BOLD}$(VERSION)${RESET}						   ${BLUE}║${RESET}\n"
	@printf "${BLUE}║ ${RESET}Build: ${GREEN}%s${RESET}                               	  	   ${BLUE}║${RESET}\n" $(BUILD_TYPE)
	@printf "${BLUE}║ ${RESET}Date: ${BOLD}%s${RESET}                                        ${BLUE}║${RESET}\n" "$(DATE)"
	@printf "${BLUE}╚══════════════════════════════════════════════════════════════════╝${RESET}\n\n"

# Build the executable
$(NAME): $(OBJS)
	@printf "${CLEAR}${PURPLE}${BOLD}Linking:${RESET} $(NAME)...\n"
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)
	@printf "\n${BLUE}╔══════════════════════════════════════════════════════════════════╗${RESET}\n"
	@printf "${BLUE}║ ${GREEN}${BOLD}Build Completed Successfully!${RESET}                                    ${BLUE}║${RESET}\n"
	@printf "${BLUE}║ ${RESET}Executable: ${BOLD}./$(NAME)${RESET}                                            ${BLUE}║${RESET}\n"
	@printf "${BLUE}╚══════════════════════════════════════════════════════════════════╝${RESET}\n"

# Create object directories
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)/entities
	@mkdir -p $(OBJ_DIR)/commands

# Compile source files
$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp | $(OBJ_DIR)
	@$(eval CURRENT_OBJ=$(shell echo $$(($(CURRENT_OBJ) + 1))))
	@printf "${CLEAR}${BOLD}[%3d/%-3d] ${GREEN}Compiling:${RESET} %-40s " $(CURRENT_OBJ) $(TOTAL_OBJS) "$<"
	@printf " ${GREY}["
	@for i in $$(seq 1 25); do \
		if [ $$i -le $(shell echo $$(($(CURRENT_OBJ) * 25 / $(TOTAL_OBJS)))) ]; then \
			printf "${GREEN}#${GREY}"; \
		else \
			printf "."; \
		fi; \
	done
	@printf "]${RESET}"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

#==============================================================================
# Build variants
#==============================================================================
# Debug build with leak sanitizer
debug:
	@$(MAKE) DEBUG=1 re

# Build with logging enabled
logs:
	@$(MAKE) LOGS=1 re

# Build with optimizations
release:
	@$(MAKE) CFLAGS="$(filter-out -g -O0,$(CFLAGS)) -O3" re

#==============================================================================
# Cleaning targets
#==============================================================================
# Remove object files
clean:
	@printf "${CLEAR}${RED}Cleaning:${RESET} object files...\n"
	@$(RM) $(OBJ_DIR)
	@printf "${GREEN}√${RESET} Object files cleaned.\n"

# Remove everything
fclean: clean
	@printf "${CLEAR}${RED}Removing:${RESET} $(NAME)...\n"
	@$(RM) $(NAME)
	@printf "${GREEN}√${RESET} Project fully cleaned.\n"

# Rebuild everything
re: fclean all

#==============================================================================
# Additional utility targets
#==============================================================================
# Display help information
help:
	@printf "${BLUE}╔══════════════════════════════════════════════════════════════════╗${RESET}\n"
	@printf "${BLUE}║ ${PURPLE}${BOLD}IRC SERVER - Make Targets${RESET}                                   ${BLUE}║${RESET}\n"
	@printf "${BLUE}╟──────────────────────────────────────────────────────────────────╢${RESET}\n"
	@printf "${BLUE}║ ${BOLD}all${RESET}      : Build the default target                                ${BLUE}║${RESET}\n"
	@printf "${BLUE}║ ${BOLD}debug${RESET}    : Build with debug symbols and sanitizers                 ${BLUE}║${RESET}\n"
	@printf "${BLUE}║ ${BOLD}logs${RESET}     : Build with logging enabled                              ${BLUE}║${RESET}\n"
	@printf "${BLUE}║ ${BOLD}release${RESET}  : Build with optimizations                                ${BLUE}║${RESET}\n"
	@printf "${BLUE}║ ${BOLD}clean${RESET}    : Remove object files                                     ${BLUE}║${RESET}\n"
	@printf "${BLUE}║ ${BOLD}fclean${RESET}   : Remove object files and executable                      ${BLUE}║${RESET}\n"
	@printf "${BLUE}║ ${BOLD}re${RESET}       : Rebuild everything                                      ${BLUE}║${RESET}\n"
	@printf "${BLUE}║ ${BOLD}version${RESET}  : Display version information                             ${BLUE}║${RESET}\n"
	@printf "${BLUE}║ ${BOLD}sysinfo${RESET}  : Display system information                              ${BLUE}║${RESET}\n"
	@printf "${BLUE}║ ${BOLD}check${RESET}    : Check if the project compiles without building          ${BLUE}║${RESET}\n"
	@printf "${BLUE}║ ${BOLD}count${RESET}    : Count lines of code in the project                      ${BLUE}║${RESET}\n"
	@printf "${BLUE}║ ${BOLD}help${RESET}     : Display this help message                               ${BLUE}║${RESET}\n"
	@printf "${BLUE}╚══════════════════════════════════════════════════════════════════╝${RESET}\n"

# Display version information
version:
	@printf "${PURPLE}╔══════════════════════════════════════════════════════════════════╗${RESET}\n"
	@printf "${PURPLE}║ ${BOLD}IRC SERVER - Version Information${RESET}                                ${PURPLE}║${RESET}\n"
	@printf "${PURPLE}╟──────────────────────────────────────────────────────────────────╢${RESET}\n"
	@printf "${PURPLE}║ ${RESET}Project:  ${BOLD}IRC Server${RESET}                                         ${PURPLE}║${RESET}\n"
	@printf "${PURPLE}║ ${RESET}Version:  ${BOLD}$(VERSION)${RESET}                                           ${PURPLE}║${RESET}\n"
	@printf "${PURPLE}║ ${RESET}Authors:  ${BOLD}$(AUTHOR)${RESET}                                         ${PURPLE}║${RESET}\n"
	@printf "${PURPLE}║ ${RESET}Build:    ${BOLD}$(DATE)${RESET}                          ${PURPLE}║${RESET}\n"
	@printf "${PURPLE}╚══════════════════════════════════════════════════════════════════╝${RESET}\n"

# Display detailed system information
sysinfo:
	@printf "${CYAN}╔══════════════════════════════════════════════════════════════════╗${RESET}\n"
	@printf "${CYAN}║ ${BOLD}IRC SERVER - System Information${RESET}                                 ${CYAN}║${RESET}\n"
	@printf "${CYAN}╟──────────────────────────────────────────────────────────────────╢${RESET}\n"
	@printf "${CYAN}║ ${RESET}OS:         ${BOLD}$(UNAME_S)${RESET}                                           ${CYAN}║${RESET}\n"
	@printf "${CYAN}║ ${RESET}OS Info:    ${BOLD}$(OS_INFO)${RESET}                ${CYAN}║${RESET}\n"
	@printf "${CYAN}║ ${RESET}Kernel:     ${BOLD}$(UNAME_R)${RESET}                                  ${CYAN}║${RESET}\n"
	@printf "${CYAN}║ ${RESET}Architecture: ${BOLD}$(UNAME_M)${RESET}                                        ${CYAN}║${RESET}\n"
	@printf "${CYAN}║ ${RESET}Compiler:   ${BOLD}$(CC) $(shell $(CC) --version | head -n 1)${RESET}  ${CYAN}║${RESET}\n"
	@printf "${CYAN}║ ${RESET}C++ Standard: ${BOLD}C++98${RESET}                                         ${CYAN}║${RESET}\n"
	@printf "${CYAN}╚══════════════════════════════════════════════════════════════════╝${RESET}\n"

# Check if project compiles without building
check:
	@printf "${YELLOW}╔══════════════════════════════════════════════════════════════════╗${RESET}\n"
	@printf "${YELLOW}║ ${BOLD}Checking if IRC Server compiles...${RESET}                              ${YELLOW}║${RESET}\n"
	@printf "${YELLOW}╚══════════════════════════════════════════════════════════════════╝${RESET}\n"
	@$(MAKE) -n all > /dev/null 2>&1 && \
	printf "${GREEN}✓ Project compilation checks passed.${RESET}\n" || \
	(printf "${RED}✗ Project compilation checks failed.${RESET}\n"; exit 1)

# Count lines of code
count:
	@printf "${ORANGE}╔══════════════════════════════════════════════════════════════════╗${RESET}\n"
	@printf "${ORANGE}║ ${BOLD}IRC SERVER - Code Statistics${RESET}                                   ${ORANGE}║${RESET}\n"
	@printf "${ORANGE}╟──────────────────────────────────────────────────────────────────╢${RESET}\n"
	@printf "${ORANGE}║ ${RESET}Source files:   ${BOLD}$(words $(SRCS))${RESET}                                        ${ORANGE}║${RESET}\n"
	@printf "${ORANGE}║ ${RESET}Headers:        ${BOLD}$(shell find ./inc -name "*.hpp" | wc -l)${RESET}                                        ${ORANGE}║${RESET}\n"
	@printf "${ORANGE}╟──────────────────────────────────────────────────────────────────╢${RESET}\n"
	@printf "${ORANGE}║ ${RESET}${BOLD}Lines of Code:${RESET}                                                ${ORANGE}║${RESET}\n"
	@printf "${ORANGE}║ ${RESET}Source files:   ${BOLD}$(shell wc -l $(addprefix $(SRC_DIR), $(SRCS)) | tail -n 1 | awk '{print $$1}')${RESET}                                     ${ORANGE}║${RESET}\n"
	@printf "${ORANGE}║ ${RESET}Header files:   ${BOLD}$(shell find ./inc -name "*.hpp" -exec wc -l {} \; | awk '{sum += $$1} END {print sum}')${RESET}                                     ${ORANGE}║${RESET}\n"
	@printf "${ORANGE}║ ${RESET}Makefile:       ${BOLD}$(shell wc -l Makefile | awk '{print $$1}')${RESET}                                      ${ORANGE}║${RESET}\n"
	@printf "${ORANGE}║ ${RESET}Total:          ${BOLD}$(shell expr $(shell wc -l $(addprefix $(SRC_DIR), $(SRCS)) | tail -n 1 | awk '{print $$1}') + $(shell find ./inc -name "*.hpp" -exec wc -l {} \; | awk '{sum += $$1} END {print sum}') + $(shell wc -l Makefile | awk '{print $$1}'))${RESET}                                     ${ORANGE}║${RESET}\n"
	@printf "${ORANGE}╚══════════════════════════════════════════════════════════════════╝${RESET}\n"

#==============================================================================
# Include generated dependencies
#==============================================================================
-include $(DEPS)

#==============================================================================
# Special build targets
#==============================================================================
# Phony targets that don't produce files
.PHONY: all clean fclean re debug logs help version sysinfo check count release banner

# Silent operation by default (use VERBOSE=1 to override)
ifndef VERBOSE
.SILENT: all clean fclean re debug logs help version sysinfo check count release banner
endif
