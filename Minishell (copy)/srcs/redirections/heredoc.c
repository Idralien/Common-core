/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:15:12 by quvan-de          #+#    #+#             */
/*   Updated: 2024/08/21 12:42:57 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	apply_heredoc(char *heredoc, int *in)
{
	int	status;
	int	fd;

	status = 0;
	if (*in != -1)
		close (*in);
	fd = open(heredoc, O_RDONLY);
	if (unlink(heredoc) == -1)
		print_err_msg(heredoc, ": File failed to delete\n");
	if (fd != -1)
		*in = fd;
	else
	{
		status = GENERIC_ERROR;
		perror_err_msg(heredoc, "");
	}
	return (status != 0);
}
