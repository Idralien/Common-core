/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:01:15 by brsantsc          #+#    #+#             */
/*   Updated: 2024/04/23 13:32:46 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_nbr(int nbr, size_t *counter)
{
	if (nbr == -2147483648)
	{
		ft_printf_nbr((nbr / 10), counter);
		ft_printf_char('8', counter);
	}
	else if (nbr < 0)
	{
		ft_printf_nbr('-', counter);
		ft_printf_nbr(-nbr, counter);
	}
	else
	{
		if (nbr > 9)
			ft_printf_nbr((nbr / 10), counter);
		ft_printf_char(('0' + nbr % 10), counter);
	}
}
