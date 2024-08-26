/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:37:43 by quvan-de          #+#    #+#             */
/*   Updated: 2024/08/21 12:42:31 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	apply_redir_in(char *redir, t_minishell *minish, int *in)
{
	int	status;
	int	fd;

	if (*in != -1)
		close(*in);
	while (ft_isspace(*redir))
		redir++;
	status = check_redir(&redir, minish);
	if (status != 0)
		return (status);
	fd = open(redir, O_RDONLY);
	if (fd != -1)
		*in = fd;
	else
	{
		status = GENERIC_ERROR;
		perror_err_msg(redir, "");
	}
	free(redir);
	return (status);
}
