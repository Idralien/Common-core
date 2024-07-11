/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:41:48 by brsantsc          #+#    #+#             */
/*   Updated: 2024/07/11 14:43:49 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/include/ft_printf.h"

t_buffer send_message = {0, 0};

void	bits_handler(int bits)
{
	int	i;

	i = 0;
	send_message.c += ((bits & 1) << send_message.i);
	send_message.i++;
	if (send_message.i == 7)
	{
		ft_printf("%c", send_message.c);
		if (!send_message.c)
			ft_printf("\n");
		send_message.c = 0;
		send_message.i = 0;
	}
}

int	main(void)
{
	ft_printf("Server is succesful up and running");
	ft_printf("Server PID is: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR2, bits_handler);
		signal(SIGUSR1, bits_handler);
		pause();
	}
	return (0);
}
