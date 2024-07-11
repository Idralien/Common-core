/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:50:14 by brsantsc          #+#    #+#             */
/*   Updated: 2024/07/09 16:47:53 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_nbr(int nbr, int *len)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*len) += 11;
		return ;
	}
	if (nbr < 0)
	{
		nbr *= -1;
		(*len) += write(1, "-", 1);
	}
	else
	{
		if (nbr > 9)
			ft_nbr((nbr / 10), len);
		ft_print_char((nbr % 10 + '0'), len);
	}
}

void	ft_ptr(size_t	ptr, int *len)
{
	char	str[25];
	int		i;
	char	*base;

	base = "0123456789abcdef";
	i = 0;
	write(1, "0x", 2);
	(*len) += 2;
	if (ptr == 0)
	{
		write(1, "0", 1);
		return ;
	}
	while (ptr != 0)
	{
		str[i] = base[ptr % 16];
		ptr = ptr / 16;
		i++;
	}
	while (i--)
		ft_print_char(str[i], len);
}

void	ft_hex(unsigned int x, int *len, char hex)
{
	char	str[25];
	int		i;
	char	*base;

	if (hex == 'X')
		base = "0123456789ABCDEF";
	else if (hex == 'x')
		base = "0123456789abcdef";
	i = 0;
	if (x == 0)
	{
		ft_print_char('0', len);
		return ;
	}
	while (x != 0)
	{
		str[i] = base[x % 16];
		x = x / 16;
		i++;
	}
	while (i--)
		ft_print_char(str[i], len);
}
void	ft_unsigned(unsigned int i, int *len)
{
	if (i >= 10)
		ft_unsigned((i / 10), len);
	ft_print_char((i % 10 + '0'), len);
}
