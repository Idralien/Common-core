/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:48:24 by quvan-de          #+#    #+#             */
/*   Updated: 2025/03/06 16:48:28 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(long nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	len;
	char	*dest;
	long	nb;

	nb = n;
	len = ft_nbrlen(nb);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	dest[len--] = '\0';
	if (nb < 0)
	{
		dest[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		dest[0] = '0';
	while (nb > 0)
	{
		dest[len--] = '0' + (nb % 10);
		nb /= 10;
	}
	return (dest);
}
