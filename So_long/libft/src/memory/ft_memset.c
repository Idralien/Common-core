/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:49:32 by brsantsc          #+#    #+#             */
/*   Updated: 2024/04/04 14:42:07 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*buffer;

	buffer = (unsigned char *) s;
	while (n > 0)
	{
		*buffer = (unsigned char) c;
		buffer++;
		n--;
	}
	return (s);
}
