/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 01:21:48 by quvan-de          #+#    #+#             */
/*   Updated: 2024/09/29 17:44:24 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* This function is called when the user sends an interrupt signal.
 * It simulates pressing Enter,
 * allowing the shell to respond to the signal.*/
void	sig_int(int sig)
{
	(void)sig;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	rl_replace_line("", 0);
	rl_on_new_line();
}

/* Sets up signal handlers based on the provided flag.
 * flag: Determines which signals to set or ignore.
 * g_data: Global data structure that contains the shell's state. */
void	ft_signal(int flag, t_data *g_data)
{
	if (flag == 1)
	{
		signal(SIGINT, sig_int);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (flag == 3)
	{
		ft_exit("\b\bexit\n", 1, g_data);
	}
}
