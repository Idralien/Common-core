/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:06:08 by brsantsc          #+#    #+#             */
/*   Updated: 2024/04/18 14:41:17 by brsantsc         ###   ########.fr       */
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
		ft_putchar_fd(ft_toupper(hex_digits[n % 16]));
	else
		ft_putchar_fd(hex_digits[n % 16]);
}

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
