/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:50:49 by quvan-de          #+#    #+#             */
/*   Updated: 2025/03/06 16:50:58 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_readline(int fd, char *static_line)
{
	char	*buffer;
	ssize_t	bytes_read;

	bytes_read = 1;
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr_gnl(static_line, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		static_line = ft_strjoin_gnl(buffer, static_line);
		if (!static_line)
			return (NULL);
	}
	free(buffer);
	return (static_line);
}

char	*ft_new_static(char *sl)
{
	char	*new_static;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (sl[i] != '\n' && sl[i])
		i++;
	if (sl[i] == '\0')
	{
		new_static = (char *)malloc(sizeof(char) * 1);
		if (!new_static)
			return (NULL);
	}
	else
	{
		new_static = (char *)malloc(sizeof(char) * (strlen_gnl(sl) - ++i + 1));
		if (!new_static)
			return (NULL);
		while (sl[i])
			new_static[j++] = sl[i++];
	}
	new_static[j] = '\0';
	free(sl);
	return (new_static);
}

char	*ft_find_line(char *static_line)
{
	size_t	i;
	size_t	j;
	char	*next_line;

	i = 0;
	if (static_line[i] == '\0')
		return (0);
	while (static_line[i] != '\n' && static_line[i])
		i++;
	if (static_line[i] == '\n')
		i++;
	next_line = (char *)malloc(sizeof(char) * i + 1);
	if (!next_line)
		return (NULL);
	j = 0;
	while (j != i)
	{
		next_line[j] = static_line[j];
		j++;
	}
	next_line[j] = '\0';
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*static_line[OPEN_MAX];
	char		*next_line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	static_line[fd] = ft_readline(fd, static_line[fd]);
	if (!static_line[fd])
		return (NULL);
	next_line = ft_find_line(static_line[fd]);
	static_line[fd] = ft_new_static(static_line[fd]);
	if (!static_line[fd])
		return (NULL);
	if (static_line[fd] && *static_line[fd] == 0)
	{
		free(static_line[fd]);
		static_line[fd] = NULL;
	}
	return (next_line);
}
