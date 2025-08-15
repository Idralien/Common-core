/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 22:20:43 by quvan-de          #+#    #+#             */
/*   Updated: 2024/09/26 22:35:46 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_word_count(char const *str, char c)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && (str[i] == c))
			i++;
		if (str[i] != '\0' && str[i] != c)
		{
			while (str[i] && str[i] != c)
				i++;
			res++;
		}
	}
	return (res);
}

static int	ft_word_len(char const *str, int i, char c)
{
	int	res;

	res = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		i++;
		res++;
	}
	return (res);
}

static int	is_this_char(const char *s, char c, int i)
{
	while (s[i] != '\0' && (s[i] == c))
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		ini_i;
	int		m_i;
	char	**res;

	i = 0;
	m_i = 0;
	res = malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!res)
		return (NULL);
	while (s[i] != '\0')
	{
		i = is_this_char(s, c, i);
		if (s[i] != '\0')
		{
			ini_i = 0;
			res[m_i] = malloc(sizeof(char) * (ft_word_len(s, i, c) + 1));
			while (s[i] != '\0' && s[i] != c)
				res[m_i][ini_i++] = s[i++];
			res[m_i++][ini_i] = '\0';
		}
	}
	res[m_i] = 0;
	return (res);
}

int	ft_isalnum(int c)
{
	if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))
		return (1);
	else if (c <= '9' && c >= '0')
		return (1);
	return (0);
}
