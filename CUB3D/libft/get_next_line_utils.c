/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:51:00 by quvan-de          #+#    #+#             */
/*   Updated: 2025/03/06 16:51:01 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_gnl(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (0);
}

char	*ft_strjoin_gnl(char *buffer, char *static_line)
{
	char	*new_string;
	int		i;
	int		j;

	if (!static_line)
	{
		static_line = (char *)malloc(sizeof(char) * 1);
		if (!static_line)
			return (NULL);
		static_line[0] = '\0';
	}
	new_string = (char *)malloc(sizeof(char) * (strlen_gnl(buffer)
				+ strlen_gnl(static_line) + 1));
	if (!new_string)
		return (NULL);
	i = -1;
	while (static_line[++i])
		new_string[i] = static_line[i];
	j = -1;
	while (buffer[++j])
		new_string[i + j] = buffer[j];
	new_string[i + j] = '\0';
	free(static_line);
	return (new_string);
}

size_t	strlen_gnl(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
