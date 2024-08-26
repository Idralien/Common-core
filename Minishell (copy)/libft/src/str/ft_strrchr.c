/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:53:02 by quvan-de          #+#    #+#             */
/*   Updated: 2024/07/11 12:53:07 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*t;

	i = 0;
	t = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			t = ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		t = ((char *)&s[i]);
	return (t);
}
