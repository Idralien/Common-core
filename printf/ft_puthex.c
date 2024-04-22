/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 08:22:53 by brsantsc          #+#    #+#             */
/*   Updated: 2024/04/22 15:32:55 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_puthex(unsigned int n, int uppercase)
{
	char	hex_digits[17] = "0123456789abcdef";

//	hex_digits[] = "0123456789abcdef";
	if (n < 16)
	{
		if (uppercase)
			ft_putchar_fd(ft_toupper(hex_digits[n]), 1);
		else
			ft_putchar_fd(hex_digits[n], 1);
	}
	if (uppercase)
		ft_putchar_fd(ft_toupper(hex_digits[n % 16]), 1);
	else
		ft_putchar_fd(hex_digits[n % 16], 1);
}
