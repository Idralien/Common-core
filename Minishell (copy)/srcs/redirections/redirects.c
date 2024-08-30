/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 15:06:15 by quvan-de          #+#    #+#             */
/*   Updated: 2024/08/26 13:48:52 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	apply_redirect(char *redir, t_minishell *minish, int *in, int *out);
int	replace_fd(int in, int out);

int	apply_redirects(char **redirs, t_minishell *minish)
{
	int	i;
	int	status;
	int	in;
	int	out;

	in = 1;
	out = -1;
	status = 0;
	i = 0;
	while (redirs[i] && status == 0)
	{
		status = apply_redirect(redirs[i], minish, &in, &out);
		i++;
	}
	if (status == 0)
		status = replace_fd(in ,out);
	return (status);
}

/* applies the appropriate redirection to the given command sign,
 * it uses strncmp to compare between the redir (given sign) and the sign */

int apply_redirect(char *redir, t_minishell *minish, int *in, int *out)
{
	int status;

	status = 0;
	if (ft_strncmp(redir, "<<", 2) == 0)
		status = apply_heredoc(redir + 2, in);
	else if (ft_strncmp(redir, ">>", 2) == 0)
		status = apply_append(redir + 2, minish, out);
	else if (ft_strncmp(redir, "<", 1) == 0)
		status = apply_redir_in(redir + 1, minish, in);
	else if (ft_strncmp(redir, ">", 1) == 0)
		status = apply_redir_out(redir + 1, minish, out);
	return (status);
}


/* check if 'in' or 'out' are valid, duplicate them to stdin and stdout and closes original.
 * if faulty return DUP_FAILURE else 0 */

int replace_fd(int in, int out)
{
	int status;

	status = 0;
	if (in != -1)
	{
		if (dup2(in, STDIN_FILENO) == -1)
			status = DUP_FAILURE;
		close(in);
	}
	if (status == 0 && out != -1)
	{
		if (dup2(out, STDOUT_FILENO) == -1)
			status = DUP_FAILURE;
		close(out);
	}
	return (status);
}
