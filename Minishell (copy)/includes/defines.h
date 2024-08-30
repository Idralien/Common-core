#ifndef DEFINES_H
# define DEFINES_H

enum    e_exit_status
{
	SUCCESS,
	GENERIC_ERROR,
	MALLOC_ERR = 200,
	FORK_FAILURE = 400,
	PIPE_FAILURE = 500,
	DUP_FAILURE = 600,
};

enum    e_characters
{
	NULL_TERM,
	SEPERATOR = 31,
	PIPE = 124,
	D_QUOTE = 34,
	S_QUOTE = 39,
	SPCE = 32,
	HT = 9,
	NL = 10,
	AND = 38,
	DASH = 45,
	DOT = 46,
	SLASH = 47,
	O_ROUND = 40,
	C_ROUND = 41,
	REDIR_L = 60,
	REDIR_R,
};

enum	e_signals_echo
{
	HEREDOC,
};

enum	e_signals_echo
{
	IMPLICIT,
	EXPLICIT,
};

# ifndef HEREDOC_NAME
#  define HEREDOC_NAME "<<.heredoc_"
# endif

# ifndef CHILD
#  define CHILD 0
# endif

#endif
