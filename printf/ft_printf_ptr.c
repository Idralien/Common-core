/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:37:18 by brsantsc          #+#    #+#             */
/*   Updated: 2024/04/22 13:50:56 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*make_str(unsigned int value, int *len)
{
	int			i;
	unsigned int	tmp;
	char		*str;

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

int	ft_printf_ptr(unsigned int value, int asc)
{
	unsigned int	tmp_val;
	char			*print;
	int				i;
	int				*iptr;

	iptr = &i;
	tmp_val = value;
	print = make_str(value, iptr);
	if (!print)
		return (NULL);
	while (tmp_val != 0 && i >= 0)
	{
		if ((tmp_val % 16) < 10)
			print[i + 1] = (tmp_val % 16) + 48;
		else
			print[i + 1] = (tmp_val % 16) + asc;
		tmp_val = tmp_val / 16;
		i--;
	}
	i = ft_strlen(print);
	i = i + printf_str("0x");
	ft_putstr_fd(print, 1);
	free(print);
	if (value == 0)
		i = i + printf_char('0');
	return (i);
}
