/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 08:52:23 by brsantsc          #+#    #+#             */
/*   Updated: 2024/04/19 09:07:58 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsigned(unsigned int n)
{
	unsigned int	div;

	div = 1;
	while (n / div >= 10)
	{
		div = div * 10;
	}
	while (div != 0)
	{
		ft_putchar_fd((n / div) % 10 + '0', 1);
		div = div / 10;
	}
}
