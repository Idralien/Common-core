/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 08:24:15 by brsantsc          #+#    #+#             */
/*   Updated: 2024/04/19 08:24:31 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_format(const char *format, ...)
{
	int	i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				ft_putchar_fd(va_args(args, int));
			else if (format[i] == 's')
				ft_putstr_fd(va_args(args, char *));
			else if (format[i] == 'p')
				ft_puthex((unsigned int)va_args(args, void *), 0);
			else if (format[i] == 'd' || format[i] == 'i')
				ft_putnubr_fd(va_args(args, int));
			else if (format[i] == 'u')
				ft_putunsigned_fd(va_args(args, unsigned int));
			else if (format[i] == 'x')
				ft_puthex(va_args(args, unsigned int), 0);
			else if (format[i] == 'X')
				ft_puthex(va_args(args, unsigned int), 1);
			else if (format[i] == '%')
				ft_putchar_fd('%');
			else
			{
				ft_putchar_fd('%');
				ft_putstr_fd(format[i]);
			}
		}
		else
			ft_putstr_fd(format[i]);
	}
	i++;
}
