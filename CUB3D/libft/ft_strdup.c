/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:49:49 by quvan-de          #+#    #+#             */
/*   Updated: 2025/03/06 16:49:50 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*mem;
	int		i;

	len = ft_strlen(s) + 1;
	mem = (char *)malloc(sizeof(char) * len);
	if (!mem)
		return (NULL);
	i = 0;
	mem = ft_memcpy(mem, s, len);
	while (mem[i])
	{
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
