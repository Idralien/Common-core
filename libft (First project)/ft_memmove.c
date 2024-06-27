/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:49:14 by brsantsc          #+#    #+#             */
/*   Updated: 2024/04/04 11:49:19 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	char			j;
	unsigned char	*dst;
	unsigned char	*sc;

	i = 0;
	j = 1;
	dst = (unsigned char *)dest;
	sc = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		j = -1;
		dst = dst + n - 1;
		sc = sc + n - 1;
	}
	while (i < n)
	{
		*dst = *sc;
		dst = dst + j;
		sc = sc + j;
		i++;
	}
	return (dest);
}
