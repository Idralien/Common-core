/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:51:47 by quvan-de          #+#    #+#             */
/*   Updated: 2024/07/11 12:51:49 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"
#include <stddef.h>
#include <stdlib.h>

static int	check_separator(char c, char sep)
{
	if (c == sep)
		return (1);
	if (c == 0)
		return (1);
	return (0);
}

static int	count_strings(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && check_separator(str[i], c))
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && !check_separator(str[i], c))
			i++;
	}
	return (count);
}

static int	ft_word_len(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && !check_separator(str[i], c))
		i++;
	return (i);
}

static char	*ft_word(char *str, char c)
{
	int		len_word;
	int		i;
	char	*word;

	i = 0;
	len_word = ft_word_len(str, c);
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	while (i < len_word)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(const char *str, char c)
{
	char	**strings;
	int		i;

	i = 0;
	strings = (char **)malloc(sizeof(char *) * (count_strings((char *)str, c)
				+ 1));
	if (!strings)
	{
		free(strings);
		return (NULL);
	}
	while (*str != '\0')
	{
		while (*str != '\0' && check_separator(*str, c))
			str++;
		if (*str != '\0')
		{
			strings[i] = ft_word((char *)str, c);
			i++;
		}
		while (*str && !check_separator(*str, c))
			str++;
	}
	strings[i] = 0;
	return (strings);
}
