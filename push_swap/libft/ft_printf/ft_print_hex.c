/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:35:56 by brsantsc          #+#    #+#             */
/*   Updated: 2024/05/02 08:26:03 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*make_string(unsigned int value, int *len)
{
	int				i;
	unsigned int	tmp;
	char			*str;

	i = 0;
	tmp = value;
	while (tmp != 0)
	{
		tmp = tmp / 16;
		i++;
	}
	str = ft_calloc(i + 1, sizeof(char));
	*len = i - 1;
	return (str);
}

int	ft_print_hex(unsigned int value, int ascii)
{
	unsigned int	tmp_value;
	char			*print;
	int				i;
	int				*iptr;

	iptr = &i;
	tmp_value = value;
	print = make_string(value, iptr);
	if (!print)
		return (0);
	while (tmp_value != 0)
	{
		if ((tmp_value % 16) < 10)
			print[i] = (tmp_value % 16) + 48;
		else
			print[i] = (tmp_value % 16) + ascii;
		tmp_value = tmp_value / 16;
		i--;
	}
	ft_putstr_fd(print, 1);
	i = ft_strlen(print);
	free(print);
	if (value == 0)
		i = i + ft_print_char('0');
	return (i);
}
