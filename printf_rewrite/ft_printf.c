/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:06:08 by brsantsc          #+#    #+#             */
/*   Updated: 2024/04/24 13:59:18 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(va_list args, const char *format, size_t *counter)
{
	int	i;

	i = 0;
	if (format[i] == 0)
		return ;
	else if (format[i] == 'c')
		ft_printf_char(va_arg((long)args, counter));
	else if (format[i] == 's')
		ft_printf_str(va_arg((char *)args, counter));
	else if (format[i] == 'p')
		ft_printhex((unsigned long)va_arg(args, 1));
	else if (format[i] == 'd' || format[i] == 'i')
		ft_printf_nbr(va_arg((long)args, counter));
	else if (format[i] == 'u')
		ft_putunsigned(va_arg((unsigned long)args));
	else if (format[i] == 'x')
		ft_printhex(va_arg((unsigned long)args, 0));
	else if (format[i] == 'X')
		ft_printhex(va_arg((unsigned long)args, 1));
	else if (format[i] == '%')
	{
		ft_printf_char(format[i], counter);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	size_t		counter;

	counter = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			ft_format(args, (char *)str, &counter);
		}
		else
			ft_printf_char(*str, &counter);
		str++;
	}
	va_end(args);
	return (counter);
}
