/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:50:43 by quvan-de          #+#    #+#             */
/*   Updated: 2024/07/11 12:50:49 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char		*string;

	i = 0;
	string = (void *)s;
	while (i < n)
	{
		if (string[i] == (char)c)
			return (&string[i]);
		i++;
	}
	return (NULL);
}
