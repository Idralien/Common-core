/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:03:09 by quvan-de          #+#    #+#             */
/*   Updated: 2024/09/29 13:25:39 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* Implements the `env` command.
*  Iterates through the environment variables in `g_data`.
*  Prints each environment variable in the format `front=back`,
*  followed by a newline. */
int	ft_env(t_data	*g_data)
{
	t_env	*env;

	env = g_data->environmental;
	while (env)
	{
		ft_putstr_fd(env->front, 1);
		ft_putstr_fd("=", 1);
		ft_putstr_fd(env->back, 1);
		ft_putstr_fd("\n", 1);
		env = env->next;
	}
	return (0);
}
