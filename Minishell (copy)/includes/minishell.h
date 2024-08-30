/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 16:35:44 by quvan-de          #+#    #+#             */
/*   Updated: 2024/08/26 16:44:37 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <fcntl.h>
# include <unistd.h>
# include "./libft.h"
# include "./structs.h"
# include "./defines.h"

typedef struct	s_minishell
{
	char            **env;
	char            *pwd;
	char            *oldpwd;
	t_list          *history;
	char            *history_path;
	int             exit_status;
	t_node          *root;
	t_bool          is_parent;
	t_bool          is_oldpwd_unset;
}                   t_minishell;

/* REDIRECTS */
int	    apply_redirects(char **redirs, t_minishell *minish);
int	    check_redir(char **reedir, t_minishell *minish);
int	    apply_heredoc(char *limiter, int *in);
int	    apply_redir_in(char *str, t_minishell *minish, int *in);
int	    apply_append(char *redir, t_minishell *minish, int *out);
int	    apply_redir_out(char *redir, t_minishell *minish, int *out);
int	    prepare_redirects(char *redirects_line, int *hd_num,
					    char ***redirs, t_minishell *minish);
int	    prepare_heredoc(char **limiter, char *hd_name, t_minishell *minish);
void	remove_hd_dups(char ***redirs, char *hd_name, char hd_counter);

/* UTILS */
void	remove_quotes(char *str, int i, int j);
void    syntax_err_msg(char *str);
void    print_err_msg(char *cmd, char *msg);
void    perror_err_msg(char *cmd, char *arg);
void    arg_err_msg(char *cmd, char *arg, char *msg);
void    handle_ctl_d_error(char *msg);
int     handle_ctl_d(char *prompt);

/* SIGNALS */
void	handle_sigint(int sig);
void	handle_sigquit(int sig);
void	sig_hadler(int sig);
void	handle_other_signals(int sig);
void	sig_err_msg(int sig);

#endif
