/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:37:07 by brsantsc          #+#    #+#             */
/*   Updated: 2024/08/26 14:55:10 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void	handle_sigint(int sig)
{
	printf("\nCaught signal %d (SIGINT). Press Ctrl+\\ to quit.\n", sig);
}

void	handle_sigquit(int sig)
{
	printf("\nCaught signal %d (SIGQUIT). Exiting now.\n", sig);
	exit(0);
}

void	sig_handler(void)
{
	if (signal(SIGINT, handle_sigint) == SIG_ERR)
	{
		printf("Error setting up signal handler for SIGINT.\n");
		exit (1);
	}
	if (signal(SIGQUIT, handle_sigquit) == SIG_ERR)
	{
		printf("Error setting up signal handler for SIGQUIT.\n");
		exit (1);
	}

}
int	main(void)
{
	sig_handler();
	while (1)
	{
		//printf("Running... Press Ctrl+C or Ctrl+\\ to test signal handling.\n");
		//sleep(2);
	}
	return (0);
}
