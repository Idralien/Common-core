/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:06:08 by brsantsc          #+#    #+#             */
/*   Updated: 2024/04/19 10:06:41 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	va_start(args, str);
	ft_format(str, ...);
	va_end(str);
	return (0);
}

/*      char    array[500];
        int     rry;
        int     i;

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
        }*/

int	main(void)
{
	ft_printf("Hello %s, My age is %d, pointer is %p, Hex value is %x\n", "Brent", 26, (void *)123, 255);
	return (0);
}
