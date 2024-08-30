/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:37:42 by quvan-de          #+#    #+#             */
/*   Updated: 2024/08/27 11:28:54 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_err_msg(char *cmd, char *msg)
{
	cmd = ft_strjoin("\033[0;31md-sh: \033[0;0m", cmd);
	if (!cmd)
		return ;
	msg = ft_strjoin(cmd, msg);
	free(cmd);
	if (!msg)
		return ;
	ft_putstr_fd(msg, STDERR_FILENO);
	free(msg);
}

void	shlvl_warn_msg(int number)
{
	char	*first_part;
	char	*num;
	char	*first_num_part;
	char	*msg;

	first_part = "\033[0;31md-sh: \033[0;0mwarning: minishell level (";
	num = ft_itoa(number);
	if (!num)
		return ;
	first_num_part = ft_strjoin(first_part, num);
	free(num);
	if (!first_num_part)
		return ;
	msg = ft_strjoin(first_num_part, msg);
	free(first_num_part);
	if (!msg)
		return ;
	ft_putstr_fd(msg, STDERR_FILENO);
	free(msg);
}

void	perror_err_msg(char *cmd, char *arg)
{
	cmd = ft_strjoin("\033[0;31md-sh: \033[0;0m", cmd);
	if (!cmd)
		return ;
	arg = ft_strjoin(cmd, arg);
	free(cmd);
	if (!arg)
		return ;
	perror(arg);
	free(arg);
}

void	arg_err_msg(char *cmd, char *arg, char *msg)
{
	cmd = ft_strjoin("\033[0;31md-sh: \033[0;0m", cmd);
	if (!cmd)
		return ;
	arg = ft_strjoin(cmd, arg);
	free(cmd);
	if (!arg)
		return ;
	msg = ft_strjoin(arg, msg);
	free(arg);
	if (!msg)
		return ;
	ft_putstr_fd(msg, STDERR_FILENO);
	free(msg);
}

/* print syntax error in a string by indicating an unexpected token by identifying the type of token and
 * modifying the null term position of the string */

void	syntax_err_msg(char *str)
{
	int	i;

	i = 0;
	if (*str == NULL_TERM)
		str = "newline";
	else if (ft_strncmp("||", str, 2) == 0 || ft_strncmp("&&", str, 2) == 0
		|| ft_strncmp(">>", str, 2) == 0 || ft_strncmp("<<", str, 2) == 0)
		i = 2;
	else if (*str == PIPE || *str == O_ROUND || *str == C_ROUND
		|| *str == REDIR_L || *str == REDIR_R || *str == AND)
		i = 1;
	else if (ft_isalnum(*str) == 1 || *str == S_QUOTE || *str == D_QUOTE)
		while (ft_isalnum(*str) == 1 || *str == S_QUOTE || *str == D_QUOTE)
			i++;
	if (i != 0)
		str[i] = NULL_TERM;
	ft_putstr_fd("\033[0;31md-sh: \033[0;0msyntax error " "unexpected token '", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putendl_fd("'", STDERR_FILENO);
}

void	sig_err_msg(char *cmd)
{
	if (*cmd != SIGINT || *cmd != SIGQUIT || *cmd != SIGKILL)
		return ;
}
