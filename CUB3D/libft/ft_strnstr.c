/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:50:19 by quvan-de          #+#    #+#             */
/*   Updated: 2025/03/06 16:50:20 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] && k < len)
	{
		while (big[i] && big[i] == little[j] && (k + i) < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)big + i - j);
			j++;
			i++;
		}
		i = 0;
		j = 0;
		big++;
		k++;
	}
	return (NULL);
}
