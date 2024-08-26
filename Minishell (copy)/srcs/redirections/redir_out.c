/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:17:08 by quvan-de          #+#    #+#             */
/*   Updated: 2024/08/21 13:21:23 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	apply_redir_out(char *redir, t_minishell *minish, int *out)
{
	int	status;
	int	fd;

	if (*out != -1)
		close(*out);
	while (ft_isspace(*redir))
		redir++;
	status = check_redir(&redir, minish);
	if (status != 0)
		return (status);
	fd = open(redir, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd != -1)
		*out = fd;
	else
	{
		status = GENERIC_ERROR;
		perror_err_msg(redir, "");
	}
	free(redir);
	return (status);
}
