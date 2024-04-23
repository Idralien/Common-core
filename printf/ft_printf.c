/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:06:08 by brsantsc          #+#    #+#             */
/*   Updated: 2024/04/23 13:34:24 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list			args;
	unsigned int	counter;
	unsigned int	result;

	counter = 0;
	result = 0;
	va_start(args, str);
	while (str[counter] != '\0')
	{
		if (str[counter] == '%')
		{
			counter++;
			ft_format(args, (char *)str);
		}
		else
			ft_printf_char(str[counter]);
		counter++;
	}
	va_end(args);
	return (counter);
}
