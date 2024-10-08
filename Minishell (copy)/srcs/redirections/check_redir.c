/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 13:47:59 by quvan-de          #+#    #+#             */
/*   Updated: 2024/08/26 13:48:54 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// function to parse commands should be named "parse_cmd" so this function doesn't deprecate ty <3

int check_redir(char **redir, t_minishell *minish)
{
	int     status;
	char    **redr;

	status = parse_cmd(*redir, &redr, minish);
	if (status != 0)
		return (status);
	if (ft_arrlen((void **)redr) != 1)
	{
		status = 1;
		print_err_msg(*redir, ": No valid redirect\n");
		ft_free_2d_array(redr);
	}
	else
	{
		*redir = redr[0];
		free(redr);
	}
	return (status);
}
