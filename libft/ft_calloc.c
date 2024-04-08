/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:46:38 by brsantsc          #+#    #+#             */
/*   Updated: 2024/04/04 11:46:50 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t counter, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(counter * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, counter * size);
	return (ptr);
}
