/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:37:22 by quvan-de          #+#    #+#             */
/*   Updated: 2024/09/29 13:30:47 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* Handles the case where an argument is provided to `exit`.
*  If the arg is not numeric, it prints an error and exits with status 255.
*  else, it converts the argument to an integer and exits with that status. */
static void	ft_exit_ut(t_block *cmd)
{
	int	j;

	j = 0;
	if (!(cmd->args[1][0] == '+' && cmd->args[1][0] == '-')
			&& ft_isdigit(cmd->args[1][0]) == 0)
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(cmd->args[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		free_blocks(cmd);
		exit(255);
	}
	else
	{
		j = ft_atoi(cmd->args[1]);
		free_blocks(cmd);
		exit(j);
	}
}

/* Main `exit` function for the shell.
*  Frees all necessary resources, such as environment variables, pipes, 
*  and command blocks.
*  If no argument is provided, it exits with status 0.
*  If one argument is provided, it calls `ft_exit_ut` to handle the exit code.
*  If more than one argument is provided, 
*  it prints an error message for too many arguments. */
int	ft_exit_b(t_block *cmd, t_data	*g_data)
{
	int	i;

	i = 0;
	while (cmd->args[i])
		i++;
	free_string(g_data->default_prompt);
	free_env(g_data->environmental);
	free_matrix(g_data->env);
	free_exp(g_data->exp);
	free_pipes(g_data->fd_pipe, g_data->block_cnt);
	free(g_data);
	if (i == 1)
	{
		free_blocks(cmd);
		exit(0);
	}
	else if (i == 2)
		ft_exit_ut(cmd);
	else
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		free_blocks(cmd);
		exit(1);
	}
	return (0);
}
