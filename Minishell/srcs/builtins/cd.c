/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:25:03 by quvan-de          #+#    #+#             */
/*   Updated: 2024/09/29 13:15:31 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* Retrieves the value of an environment variable by its name str from g_data.
*  Returns the value (back) associated with the environment variable (front).
*  If the variable is not found, returns NULL. */
static char	*ft_getenv(char *str, t_data	*g_data)
{
	t_env	*env;

	env = g_data->environmental;
	if (!str)
		return (NULL);
	while (env)
	{
		if (ft_strcmp(env->front, str) == 0)
			return (env->back);
		env = env->next;
	}
	return (NULL);
}

/* Determines the path for the `cd` command.
*  If no path is provided or if the argument is `~`, 
*  it retrieves the HOME directory from the environment.
*  Returns 0 if no valid path is found, otherwise returns 1. */
static int	get_cd_path(t_block *cmd, char **path, t_data *g_data)
{
	if (cmd->args[1] == NULL || ft_strcmp(cmd->args[1], "~") == 0)
	{
		*path = ft_getenv("HOME", g_data);
		if (*path == NULL)
			return (0);
	}
	else
		*path = cmd->args[1];
	return (1);
}

/* Implements the `cd` command.
*  Handles the case where too many arguments are provided, 
*  retrieves the correct path, and attempts to change to the given directory.
*  If changing directory fails, it prints an error message and returns 1; 
*  otherwise returns 0 on success. */
int	ft_cd(t_block *cmd, t_data *g_data)
{
	char	*path;

	if (cmd->args[1] && cmd->args[2])
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		return (-1);
	}
	if (get_cd_path(cmd, &path, g_data) == 0)
		return (0);
	if (chdir(path) == -1)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		return (1);
	}
	return (0);
}
