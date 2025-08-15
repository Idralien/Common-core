/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:49:53 by quvan-de          #+#    #+#             */
/*   Updated: 2025/03/06 16:49:55 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	comb_len;
	char	*r;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	comb_len = len_s1 + len_s2 + 1;
	r = malloc(sizeof(char) * comb_len);
	if (!r)
		return (NULL);
	ft_strlcpy(r, s1, comb_len);
	ft_strlcat(r, s2, comb_len);
	return (r);
}
