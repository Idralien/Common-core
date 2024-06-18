/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:29:58 by quvan-de          #+#    #+#             */
/*   Updated: 2024/06/03 16:30:00 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*placeholder;

	placeholder = (char *)b;
	while (len > 0)
	{
		placeholder[len - 1] = c;
		len--;
	}
	return (b);
}
