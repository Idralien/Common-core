/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:49:35 by quvan-de          #+#    #+#             */
/*   Updated: 2025/03/06 16:49:36 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int	words_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && is_charset(*s, c))
			s++;
		if (*s && !is_charset(*s, c))
		{
			count++;
			while (*s && !is_charset(*s, c))
				s++;
		}
	}
	return (count);
}

static char	*malloc_word(char const *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] && !is_charset(s[i], c))
		i++;
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] && !is_charset(s[i], c))
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		words;
	int		x;

	words = words_count(s, c);
	dest = malloc(sizeof(char *) * (words + 1));
	if (!dest)
		return (NULL);
	x = 0;
	while (*s)
	{
		while (*s && is_charset(*s, c))
			s++;
		if (*s && !is_charset(*s, c))
		{
			dest[x] = malloc_word(s, c);
			x++;
			while (*s && !is_charset(*s, c))
				s++;
		}
	}
	dest[x] = NULL;
	return (dest);
}
