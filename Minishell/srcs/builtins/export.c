/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:47:35 by quvan-de          #+#    #+#             */
/*   Updated: 2024/09/29 13:32:29 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* Sorts the environment variables alphabetically.
*  It compares each string and swaps them if necessary.
*  Returns the sorted environment variable array. */
static char	**ft_sort_env(char **tmp_env)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (tmp_env[i])
	{
		j = i + 1;
		while (tmp_env[j])
		{
			if (ft_strcmp(tmp_env[i], tmp_env[j]) > 0)
			{
				tmp = tmp_env[i];
				tmp_env[i] = tmp_env[j];
				tmp_env[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tmp_env);
}

/* Returns the size of a given matrix (2D array of strings).
*  It counts the number of non-null entries in the array. */
static int	ft_matrix_size(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/* Copies the current environment variables from `g_data` into a new array.
*  Allocates memory for the new array and duplicates each string. */
static char	**ft_copy_env(t_data *g_data)
{
	char	**env;
	char	**new;
	int		i;
	int		len;

	i = -1;
	len = ft_matrix_size(g_data->env);
	env = g_data->env;
	new = (char **)malloc(sizeof(char *) * (len + 1));
	while (env[++i])
		new[i] = ft_strdup(env[i]);
	new[i] = NULL;
	return (new);
}

/* Handles the `export` command without arguments.
*  It prints all environment variables sorted and prefixed with "declare -x".
*  This is used when the user runs `export` with no additional arguments. */
static void	ft_only_export(t_data *g_data)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = ft_copy_env(g_data);
	if (tmp == NULL)
		return ;
	tmp = ft_sort_env(tmp);
	while (tmp[++i])
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(tmp[i], 1);
		ft_putstr_fd("\n", 1);
	}
	free_matrix(tmp);
}

/* Handles the `export` command with arguments.
*  It adds or modifies environment variables based on the input.
*  If no arguments are given, it calls `ft_only_export` 
*  to print all environment variables. */
int	ft_export(t_block *cmd, t_data	*g_data)
{
	char	**splitted_input;
	char	*tmp;

	if (cmd->args[1] == NULL)
	{
		ft_only_export(g_data);
		return (0);
	}
	tmp = ft_strstr(cmd->args[1], "=");
	if (!tmp)
		return (0);
	if (!tmp || *tmp == cmd->args[1][0] || ft_strcmp(cmd->args[1], "=") == 0)
	{
		ft_error('e', cmd);
		return (-1);
	}
	splitted_input = ft_split(cmd->args[1], '=');
	if (ft_is_valid_env(splitted_input[0], g_data))
		ft_change_env(splitted_input[0], splitted_input[1], g_data);
	else
		ft_new_env(cmd->args[1], g_data);
	free_matrix(splitted_input);
	free_matrix(g_data->env);
	g_data->env = ft_env_to_matrix(g_data);
	return (0);
}
