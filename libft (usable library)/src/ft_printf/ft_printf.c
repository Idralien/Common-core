/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:35:40 by brsantsc          #+#    #+#             */
/*   Updated: 2024/04/30 15:21:13 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int	ft_format(const char *format, void *arg)
{
	int	store;

	store = 0;
	if (*format == 0)
		return (0);
	else if (*format == 'c')
		store = store + ft_print_char((long)arg);
	else if (*format == 's')
		store = store + ft_print_str((char *)arg);
	else if (*format == 'p')
		store = store + ft_print_ptr((unsigned long)arg, 87);
	else if (*format == 'd' || *format == 'i')
		store = store + ft_print_nbr((long)arg);
	else if (*format == 'u')
		store = store + ft_print_unsigned((unsigned long)arg);
	else if (*format == 'x' || *format == 'X')
	{
		if (*format == 'x')
			store = store + ft_print_hex((unsigned long)arg, 87);
		else if (*format == 'X')
			store = store + ft_print_hex((unsigned long)arg, 55);
	}
	return (store);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	size_t		store;

	store = 0;
	va_start(args, str);
	if (!str)
		return (-1);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			if (ft_strchr("cspdiuxX", *str))
				store = store + ft_format(str, va_arg(args, void *));
			else if (*str == '%')
				store = store + ft_print_char('%');
		}
		else
			store = store + ft_print_char(*str);
		str++;
	}
	va_end(args);
	return (store);
}
/*int main(void)
{
	ft_printf("Test 1: %p\n", (void *)-1);
	ft_printf("Test 2: %p\n", (void *)15);
	ft_printf("Test 9: %p\n", (void *)0);
	return (0);
}*/
