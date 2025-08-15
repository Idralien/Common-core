/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:49:04 by quvan-de          #+#    #+#             */
/*   Updated: 2025/03/06 16:49:05 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char const	*str;

	str = (unsigned char const *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char const)c)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}
