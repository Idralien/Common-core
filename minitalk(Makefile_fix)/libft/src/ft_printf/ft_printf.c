/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:35:40 by brsantsc          #+#    #+#             */
/*   Updated: 2024/07/09 16:34:21 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	ft_format(const char format, va_list *args, int *len, int *i)
{
	if (format == 'c')
		ft_print_char(va_arg(*args, int), len);
	else if (format == 's')
		ft_print_string(va_arg(*args, char *), len);
	else if (format == 'p')
		ft_ptr(va_arg(*args, size_t), len);
	else if (format == 'd' || format == 'i')
		ft_nbr(va_arg(*args, int), len);
	else if (format == 'u')
		ft_unsigned(va_arg(*args, unsigned int), len);
	else if (format == 'x' || format == 'X')
	{
		if (format == 'x')
			ft_hex(va_arg(*args, unsigned int), len, 'x');
		else if (format == 'X')
			ft_hex(va_arg(*args, unsigned int), len, 'X');
	}
	else if (format == '%')
		ft_print_char('%', len);
	else
		(*i)--;
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			len;
	int			i;

	i = 0;
	len = 0;
	va_start(args, str);
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			ft_format(str[i], &args, &len, &i);
			i++;
		}
		else
		{
			ft_print_char((char)str[i], &len);
			i++;
		}
	}
	return (va_end(args), len);
}
/*int main(void)
{
	ft_printf("Test 1: %p\n", (void *)-1);
	ft_printf("Test 2: %p\n", (void *)15);
	ft_printf("Test 9: %p\n", (void *)0);
	return (0);
}*/
