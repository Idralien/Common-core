/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 11:53:34 by brsantsc          #+#    #+#             */
/*   Updated: 2024/04/04 11:53:47 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	ft_char_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	begin;
	size_t	end;

	i = 0;
	begin = 0;
	end = ft_strlen(s1);
	while (s1[begin] != '\0' && ft_char_set(s1[begin], set))
		begin++;
	while (end > begin && ft_char_set(s1[end - 1], set))
		end--;
	str = (char *)malloc(sizeof(*s1) * (end - begin + 1));
	if (!str || !s1)
		return (NULL);
	while (begin < end)
	{
		str[i] = s1[begin];
		i++;
		begin++;
	}
	str[i] = '\0';
	return (str);
}
