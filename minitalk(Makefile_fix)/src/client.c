/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:28:34 by brsantsc          #+#    #+#             */
/*   Updated: 2024/07/22 14:12:11 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	send_signal(int server_pid, char c)
{
	int		bits;

	bits = 0;
	while (bits < 8)
	{
			if ((c & (0x01 << bits)) != 0)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			usleep(250);
			bits++;
	}
}

int	main(int argc, char **argv)
{
	int		server_pid;
	int		i;

	i = 0;
	if (argc == 3)
	{
		server_pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			send_signal(server_pid, argv[2][i]);
			i++;
		}
//		send_signal(server_pid, '\n');
	}
	else
	{
		ft_printf("ERROR: INPUT NOT POSSIBLE\n");
		ft_printf("Command: ./client <PID> <string>");
		return (1);
	}
	send_signal(server_pid, '\0');
	return (0);
}
