/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:06:08 by brsantsc          #+#    #+#             */
/*   Updated: 2024/04/17 14:07:41 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "libft.h"

void	ft_puthex(unsigned int n, int uppercase)
{
	char	hex_digits;

	hex_digits[] = "0123456789abcdef";
	if (n >= 16)
	{
		ft_puthex(n / 16, uppercase);
	}
	if (uppercase)
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	va_start(args, str);

	char	array[500];
	int	rry;
	int	i;

	rry = 0;
	i = 0;
	while (str[i] != '\0')
	{
		array[rry] = str[i];
		i++;
		rry++;
		if (str[i + 1] == '%' || str[i + 1] == '\0')
		{
			array[rry] = '\0';
			rry = 0;
			if (str[i] != '%')
			{
				ft_putstr_fd(str[i], i);
			}
		}
	}
	va_end(ptr);
	return (0);
}
