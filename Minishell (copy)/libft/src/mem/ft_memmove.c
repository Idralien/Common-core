/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:51:16 by quvan-de          #+#    #+#             */
/*   Updated: 2024/07/11 12:51:24 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	len;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (src < dst)
	{
		len = n;
		while (len > 0)
		{
			len--;
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
		}
	}
	else
	{
		len = 0;
		while (len < n)
		{
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
			len++;
		}
	}
	return (dst);
}
