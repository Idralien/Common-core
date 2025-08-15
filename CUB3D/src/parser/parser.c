/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:57:25 by quvan-de          #+#    #+#             */
/*   Updated: 2025/03/10 13:44:26 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	count_lines(const char *file_name)
{
	int		fd;
	int		line_count;
	char	*line;

	fd = open(file_name, O_RDONLY);
	line_count = 0;
	if (fd < 0)
		return (print_error("Error\nUnable to open the file!"));
	line = get_next_line(fd);
	while ((line))
	{
		line_count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (line_count);
}

static int	allocate_map(t_map *map, int total_lines)
{
	map->map = malloc(sizeof(char *) * (total_lines + 1));
	if (!map->map)
		return (print_error("Error\nMemory allocation failed!"));
	map->height = 0;
	map->map[0] = NULL;
	return (1);
}

static int	read_map(int fd, t_game *game)
{
	char	*line;
	char	*trimmed_line;

	line = get_next_line(fd);
	while (line)
	{
		trimmed_line = trim_whitespace(line);
		free(line);
		if (trimmed_line && ft_strlen(trimmed_line) > 0)
		{
			if (!get_data(trimmed_line, game))
			{
				free(trimmed_line);
				return (0);
			}
		}
		if (trimmed_line)
			free(trimmed_line);
		line = get_next_line(fd);
	}
	if (!check_file_content(&game->map_flags))
		return (0);
	return (1);
}

int	parse_file(const char *file_name, t_game *game)
{
	int	fd;
	int	result;
	int	total_lines;

	total_lines = count_lines(file_name);
	if (!allocate_map(&game->map, total_lines))
		return (0);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (print_error("Error\nUnable to open the file!"));
	result = read_map(fd, game);
	close(fd);
	if (result && !parse_map(game))
		return (print_error("Error\nMap validation failed!"));
	return (result);
}
