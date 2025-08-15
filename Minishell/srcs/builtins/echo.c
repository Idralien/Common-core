/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:51:00 by quvan-de          #+#    #+#             */
/*   Updated: 2024/09/30 14:14:37 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_str_only_contains(const char *str, char c);

/* Implements the `echo` command.
*  Handles the `-n` flag which suppresses the newline at the end of output.
*  Prints all arguments separated by spaces, 
*  and adds a newline unless `-n` is present. */
int	ft_echo(t_block *cmd)
{
	int	i;
	int	n_flag;

	i = 1;
	n_flag = 0;
	while (cmd->args[i] && cmd->args[i][0] == '-'
		&& ft_str_only_contains(cmd->args[i] + 1, 'n'))
	{
		n_flag = 1;
		i++;
	}
	while (cmd->args[i])
	{
		ft_putstr_fd(cmd->args[i], 1);
		if (cmd->args[i + 1])
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (n_flag == 0)
		ft_putstr_fd("\n", 1);
	return (0);
}

/* Checks if a string contains only the specified character */
static int	ft_str_only_contains(const char *str, char c)
{
	while (*str)
	{
		if (*str != c)
			return (0);
		str++;
	}
	return (1);
}
