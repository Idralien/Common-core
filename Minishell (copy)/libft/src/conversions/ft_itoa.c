/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:45:59 by quvan-de          #+#    #+#             */
/*   Updated: 2024/07/11 12:46:00 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"
#include <stdlib.h>

static void	ft_len(int n, size_t *len, int *sign)
{
	*len = 0;
	*sign = 1;
	if (n < 0)
	{
		*len = 1;
		*sign = -1;
	}
	while (n / 10)
	{
		*len += 1;
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	size_t	len;
	int		sign;
	char	*str;

	ft_len(n, &len, &sign);
	str = (char *)malloc(sizeof(char) * (len + 2));
	if (!str)
		return (NULL);
	str[len + 1] = '\0';
	while (len > 0)
	{
		str[len] = (n % 10) * sign + '0';
		n /= 10;
		len--;
	}
	if (sign == -1)
		str[0] = '-';
	else
		str[0] = (n % 10) * sign + '0';
	return (str);
}
