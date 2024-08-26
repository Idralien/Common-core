/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:51:26 by quvan-de          #+#    #+#             */
/*   Updated: 2024/07/11 12:51:35 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

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
