/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exite.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:35:14 by quvan-de          #+#    #+#             */
/*   Updated: 2024/09/29 17:31:45 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* Frees a single environment node.
 * This function deallocates memory for the 'front' and 'back' strings
 * and then frees the environment node itself. */
void	free_env_node(t_env *env)
{
	free_string(env->front);
	free_string(env->back);
	free(env);
}

/* Frees all nodes in the environment linked list.
 * This function traverses the entire list,
 * freeing each node and its associated strings. */
void	free_env(t_env *env)
{
	t_env	*tmp;

	if (!env)
		return ;
	while (env)
	{
		tmp = env;
		env = env->next;
		free_string(tmp->front);
		free_string(tmp->back);
		free(tmp);
	}
}

/* Handles program exit.
 * Frees allocated resources and prints a message before terminating the program.
 * str: Message to print before exiting.
 * status: Exit status code (0 for normal exit, non-zero for error).
 * g_data: Global data structure containing environmental variables. */
void	ft_exit(char *str, int status, t_data	*g_data)
{
	free_env(g_data->environmental);
	free_matrix(g_data->env);
	free(g_data);
	if (status == 0)
		ft_putstr_fd(str, 1);
	else if (status == 1)
		ft_putstr_fd(str, 1);
	exit(0);
}
