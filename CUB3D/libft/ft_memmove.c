/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:49:10 by quvan-de          #+#    #+#             */
/*   Updated: 2025/03/06 16:49:11 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	if (!dst && !src)
		return (NULL);
	d = dst;
	s = src;
	if (!len)
		return (dst);
	if (dst <= src)
		return (ft_memcpy(dst, src, len));
	d += len;
	s += len;
	while (len--)
		*(--d) = *(--s);
	return (dst);
}
