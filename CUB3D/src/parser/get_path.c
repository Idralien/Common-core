/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:57:09 by quvan-de          #+#    #+#             */
/*   Updated: 2025/03/10 13:32:15 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	file_exists(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd != -1)
	{
		close(fd);
		return (1);
	}
	return (0);
}

static int	check_extra_char(const char *path_start)
{
	int	i;

	i = 0;
	while (path_start[i] != '\0')
	{
		if (path_start[i] == ' ' || path_start[i] == '\t')
		{
			while (path_start[i] == ' ' || path_start[i] == '\t')
				i++;
			if (path_start[i] != '\0')
				print_error("Error\nExtra characters after texture path");
		}
		i++;
	}
	return (1);
}

int	get_path(char *line, char **texture_path)
{
	char	*path_start;

	path_start = line + 2;
	path_start = trim_whitespace(path_start);
	if (!path_start || *path_start == '\0')
		return (print_error("Error\nInvalid texture path"));
	*texture_path = ft_strdup(path_start);
	free(path_start);
	if (!*texture_path)
		return (print_error("Error\nMemory allocation failed"));
	if (!file_exists(*texture_path))
	{
		free(*texture_path);
		*texture_path = NULL;
		return (print_error("Error\nTexture file does not exist"));
	}
	if (!check_extra_char(*texture_path))
	{
		free(*texture_path);
		*texture_path = NULL;
		return (0);
	}
	return (1);
}

char	*trim_whitespace(char *str)
{
	int		start;
	int		end;
	char	*trimmed;

	start = 0;
	if (!str)
		return (NULL);
	end = ft_strlen(str) - 1;
	while (str[start] == ' ' || str[start] == '\t')
		start++;
	if (start > end)
		return (ft_strdup(""));
	while (end >= start && (str[end] == ' ' || str[end] == '\t'
			|| str[end] == '\n'))
		end--;
	trimmed = (char *)malloc(end - start + 2);
	if (!trimmed)
		return (NULL);
	ft_strncpy(trimmed, str + start, end - start + 1);
	trimmed[end - start + 1] = '\0';
	return (trimmed);
}
