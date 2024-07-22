/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:41:48 by brsantsc          #+#    #+#             */
/*   Updated: 2024/07/22 14:12:00 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	bits_handler(int signal)
{
	static int	bits;
	static char	i;

	if (signal == SIGUSR1)
		i |= (0x01 << bits);
	bits++;
	if (bits == 8)
	{
		ft_printf("%c", i);
		if (i == '\0')
			ft_printf("\n");
		bits = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int	server_pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("ERROR\n");
		ft_printf("Command: ./server\n");
		return (0);
	}
	server_pid = getpid();
	ft_printf("PID: %d\n", server_pid);
	ft_printf("Waiting...\n");
	while (argc == 1)
	{
		signal(SIGUSR1, bits_handler);
		signal(SIGUSR2, bits_handler);
		pause();
	}
	return (0);
}
