/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:28:34 by brsantsc          #+#    #+#             */
/*   Updated: 2024/07/11 14:53:25 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/include/ft_printf.h"

void	send_signal(int server_pid, char *str, size_t len)
{
	int		bits;
	size_t	i;

	i = 0;
	while (i <= len)
	{
		bits = 0;
		while (bits < 7)
		{
			if ((str[i] >> bits) & 1)
				kill(server_pid, SIGUSR2);
			else
				kill(server_pid, SIGUSR1);
			bits++;
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		server_pid;
	char	*str;

	if (argc != 3)
	{
		server_pid = ft_atoi(argv[1]);
		str = argv[2];
		send_signal(server_pid, str, ft_strlen(str));
	}
	else
		ft_printf("ERROR: INPUT NOT POSSIBLE\n");
}
