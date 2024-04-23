/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 08:24:15 by brsantsc          #+#    #+#             */
/*   Updated: 2024/04/23 12:35:17 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(va_list args, const char *format)
{
	int	i;

	i = 0;
	if (format[i] == 'c')
		ft_printf_char(va_arg(args, int));
	else if (format[i] == 's')
		ft_printf_str(va_arg(args, char *));
	else if (format[i] == 'p')
		ft_printhex((unsigned long)va_arg(args, void *), 1);
	else if (format[i] == 'd' || format[i] == 'i')
		ft_printf_nbr(va_arg(args, int));
	else if (format[i] == 'u')
		ft_putunsigned(va_arg(args, unsigned int));
	else if (format[i] == 'x')
		ft_printhex(va_arg(args, unsigned int), 0);
	else if (format[i] == 'X')
		ft_printhex(va_arg(args, unsigned int), 1);
	else if (format[i] == '%')
	{
		ft_printf_char('%');
	}
}
