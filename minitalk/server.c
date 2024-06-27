/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:12:18 by brsantsc          #+#    #+#             */
/*   Updated: 2024/06/27 12:46:23 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_buffer g_buffer = {0, 0}; //global buffer structure

void	handle_signal(int signal)
{
	if (signal == SIGUSR1)
	{
		g_buffer.char_buffer |= (1 << g_buffer.bit_count); //set corresponding bit to 1
	}
	g_buffer.bit_count++;

	if (g_buffer.bit_count == 8) //If 8 bits are received, you have a full character
	{
		if (g_buffer.char_buffer == '\0') //Null character indicates end of message
		{
			ft_printf("\n");
		}
		else
		{
			ft_putchar_fd(g_buffer.char_buffer);
			fflush(stdout);
		}
		g_buffer.char_buffer = 0; //Reset the character buffer for the next character
		g_buffer.bit_count = 0; //Reset the bit counter
	}
}

int	main(void)
{
	struct	sigaction sa;
	sa.sa_handler = handle_signal;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);

	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}

	ft_printf("Server PID: %d\n", getpid());

	while (1)
	{
		pause(); //wait for signals
	}
	return 0;
}
