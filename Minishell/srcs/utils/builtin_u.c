/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 21:59:52 by quvan-de          #+#    #+#             */
/*   Updated: 2024/09/29 19:51:52 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* Deletes an environment variable by name (str) 
   from the linked list in g_data. Frees the node 
   and updates the environment matrix. */
void	ft_delete_env(char *str, t_data	*g_data)
{
	t_env	*env;
	t_env	*prev;

	env = g_data->environmental;
	prev = NULL;
	while (env)
	{
		if (ft_strcmp(env->front, str) == 0)
		{
			if (prev == NULL)
				g_data->environmental = env->next;
			else
				prev->next = env->next;
			free_env_node(env);
			return ;
		}
		prev = env;
		env = env->next;
	}
	free_matrix(g_data->env);
	g_data->env = ft_env_to_matrix(g_data);
}

/* Creates a new environment variable from str 
   and adds it to the environmental list in g_data. 
   Returns a pointer to the new node. */
t_env	*ft_new_env(char *str, t_data	*g_data)
{
	t_env	*env;
	t_env	*new;

	env = g_data->environmental;
	new = (t_env *)malloc(sizeof(t_env));
	new->front = ft_substr(str, 0, ft_strchr(str, '=') - str);
	new->back = ft_substr(str, ft_strchr(str, '=') - str + 1, ft_strlen(str));
	new->next = NULL;
	if (env == NULL)
		g_data->environmental = new;
	else
	{
		while (env->next)
			env = env->next;
		env->next = new;
	}
	return (new);
}

/* Checks if an environment variable exists in g_data 
   by comparing the front part of each node. Returns 
   1 if it exists, otherwise 0. */
int	ft_is_valid_env(char *str, t_data	*g_data)
{
	t_env	*env;

	env = g_data->environmental;
	if (!str)
		return (0);
	while (env)
	{
		if (ft_strcmp(env->front, str) == 0)
			return (1);
		env = env->next;
	}
	return (0);
}

/* Changes the value of an existing environment variable 
   by freeing the old value (back) and replacing it with 
   new_value. */
void	ft_change_env(char *str, char *new_value, t_data	*g_data)
{
	t_env	*env;

	env = g_data->environmental;
	if (!str)
		return ;
	while (env)
	{
		if (ft_strcmp(env->front, str) == 0)
		{
			free(env->back);
			env->back = ft_strdup(new_value);
			return ;
		}
		env = env->next;
	}
}
