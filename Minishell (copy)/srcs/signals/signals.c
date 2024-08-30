/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 14:40:18 by brsantsc          #+#    #+#             */
/*   Updated: 2024/08/30 14:59:49 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "../../includes/minishell.h"*/
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
/*Signal handler functions*/
void	handle_sigint(int sig);
void	handle_sigquit(int sig);
void	handle_sigkill(int sig);

/*Function to set up signals using 'sigaction'*/
void	setup_signals(void);

/*Set up signal handling and waiting for signal
 * Main loop*/
int	main(void)
{
	setup_signals();
	while (1)
	{
		pause();
	}
	return (0);
}

/*Signal handler for SIGINT (ctrl-c)*/
void	handle_sigint(int sig)
{
	printf("Caught SIGINT (Ctrl+C). Exiting...\n");
	exit(0);
}

void	handle_sigquit(int sig)
{
	printf("Caught SIGQUIT (Ctrl+\\). Exiting...\n");
	exit(0);
}

void	handle_sigkill(int sig)
{
	printf("Caught SIGKILL (Ctrl+D). Exiting...\n");
	exit(0);
}

/*Function to setup signal handling
 *
 * Set up SIGINT handler
 * Set up SIGQUIT handler
 * Set up SIGKILL handler 
 **(Ctrl-D is not a signal so SIGUSR1 simulates handling it)*/
void	setup_signals(void)
{
	struct sigaction	sa;

	sa.sa_handler = handle_sigint;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
	sa.sa_handler = handle_sigquit;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGQUIT, &sa, NULL);
	sa.sa_handler = handle_sigkill;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
}
