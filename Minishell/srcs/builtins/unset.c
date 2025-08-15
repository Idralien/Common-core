/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:25:23 by quvan-de          #+#    #+#             */
/*   Updated: 2024/09/29 13:35:03 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* Fills a matrix with environment variables from the linked list.
*  Allocs memo for each variable and populates it with the format "key=value".
*  Returns 1 on success, or 0 on failure (if memory allocation fails). */
static char	ft_ft(char **matrix, t_env *env, int i)
{
	while (env)
	{
		matrix[i] = (char *)malloc(sizeof(char)
				* (ft_strlen(env->front) + ft_strlen(env->back) + 2));
		if (!matrix)
		{
			free_matrix(matrix);
			return (0);
		}
		ft_strcpy(matrix[i], env->front);
		ft_strcat(matrix[i], "=");
		ft_strcat(matrix[i++], env->back);
		env = env->next;
	}
	matrix[i] = NULL;
	return (1);
}

/* Converts the linked list of environment variables into a matrix of strings.
*  Allocates memory for the matrix based on the number of environment variables.
*  Returns a pointer to the matrix, or NULL if memory allocation fails. */
char	**ft_env_to_matrix(t_data	*g_data)
{
	t_env	*env;
	char	**matrix;
	int		i;

	env = g_data->environmental;
	i = 0;
	while (env)
	{
		i++;
		env = env->next;
	}
	matrix = malloc(sizeof(char *) * (i + 1));
	if (!matrix)
		return (NULL);
	i = 0;
	env = g_data->environmental;
	if (!ft_ft(matrix, env, i))
		return (NULL);
	return (matrix);
}

/* Unsets environment variables specified in the command block.
*  Iterates over the arguments and deletes valid environment variables.
*  Updates the environment matrix after deletion. Returns 0 on success. */
int	ft_unset(t_block *cmd, t_data	*g_data)
{
	int	i;

	i = 1;
	while (cmd->args[i])
	{
		if (ft_is_valid_env(cmd->args[i], g_data))
		{
			ft_delete_env(cmd->args[i], g_data);
		}
		i++;
	}
	free_matrix(g_data->env);
	g_data->env = ft_env_to_matrix(g_data);
	if (!g_data->env)
		ft_error('m', 0);
	return (0);
}
