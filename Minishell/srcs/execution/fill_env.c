/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:14:14 by quvan-de          #+#    #+#             */
/*   Updated: 2024/09/29 17:07:45 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* Allocates memory for a new environment variable node and 
 * initializes its fields.
 * Returns a pointer to the newly created node. */
t_env	*ft_new_list(void)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	new->front = NULL;
	new->back = NULL;
	new->next = NULL;
	return (new);
}

/* Finds the index of the equal sign in the given string.
*  Returns the index of '=' or -1 if not found. */
int	ft_index_of_equal_sign(char *str)
{
	int	counter;

	counter = 0;
	while (*(str + counter))
	{
		if (*(str + counter) == '=')
			return (counter);
		counter++;
	}
	return (-1);
}

/* Adds a new environment variable node to the end of the linked list.
*  If the list is empty, the new node becomes the head. */
void	ft_add_tail(t_env *new_n, t_env **head)
{
	t_env	*temp;

	temp = *head;
	if (!(*head))
	{
		*head = new_n;
	}
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new_n;
	}
}

/* Fills the environment variable list from the provided array of 
 * environment strings. Parses each string to extract the variable name 
 * and value, then adds them to the list. */
void	ft_fill_env(char **env, t_data	*g_data)
{
	t_env	*temp;
	int		len;
	int		flag;
	int		i;

	flag = 0;
	i = 0;
	while (env[i])
	{
		len = ft_strlen(env[i]);
		temp = ft_new_list();
		if (!temp)
			return ;
		flag = ft_index_of_equal_sign(env[i]);
		if (flag == -1)
			ft_exit("Error: no equal sign in env variable.\n", 0, g_data);
		temp->front = ft_substr(env[i], 0, flag);
		temp->back = ft_substr(env[i], flag + 1, len);
		ft_add_tail(temp, &g_data->environmental);
		i++;
	}
}
