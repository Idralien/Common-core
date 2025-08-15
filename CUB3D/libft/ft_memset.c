/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:49:12 by quvan-de          #+#    #+#             */
/*   Updated: 2025/03/06 16:49:13 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*buc;

	i = 0;
	buc = (unsigned char *)s;
	while (i < n)
	{
		buc[i] = c;
		i++;
	}
	return (s = buc);
}
