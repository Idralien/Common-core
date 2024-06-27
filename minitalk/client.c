/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:11:10 by brsantsc          #+#    #+#             */
/*   Updated: 2024/06/27 12:46:26 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(pid_t server_pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i)) //Check if the i-th bit is set
		{
			kill(server_pid, SIGUSR1);
		}
		else
		{
			kill(server_pid, SIGUSR2);
		}
		i++;
		usleep(100); //Small delay to ensure the server can process each signal
	}
}

void	send_string(pid_t server_pid, const char *str)
{
	while (*str)
	{
		send_char(server_pid, *str);
			str++;
	}
	send_char(server_pid, '\0'); //Send NULL terminator to indicate end of the message
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_printf(stderr, "Usage: %s <server_pid> <message>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	pid_t server_pid = (pid_t)ft_atoi(argv[1]);
	const char	*message = argv[2];
	send_string(server_pid, message);

	return 0;
}

