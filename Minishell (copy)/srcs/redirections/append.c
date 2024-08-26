/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:40:35 by quvan-de          #+#    #+#             */
/*   Updated: 2024/08/26 10:43:30 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* 0644 is a way of setting file perms, part of open() */

int	apply_append(char *redir, t_minishell *minish, int *out)
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
	fd = open(redir, O_CREAT | O_WRONLY | O_APPEND, 0644);
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
