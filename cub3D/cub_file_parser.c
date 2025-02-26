/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_file_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:03:45 by brsantsc          #+#    #+#             */
/*   Updated: 2025/02/26 00:23:03 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

char	*read_file_to_string(const char *filename)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*content;
	char	*temp;
	int		fd;
	int		bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit("Error: Could not open .cub file");
	content = NULL;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(content, buffer);
		free(content);
		content = temp;
	}
	close(fd);
	if (!content)
		error_exit("Error: File is empty or could not be read");
	return (content);
}

void	parse_lines(char **lines, t_game *game)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		if (is_texture_line(lines[i]))
			parse_texture(lines[i], game);
		else if (is_color_line(lines[i]))
			parse_color(lines[i], game);
		else if (is_map_line(lines[i]))
			parse_map(lines[i], game);
		else if (!is_empty_line(lines[i]))
			error_exit("Error: Invalid line in .cub file");
		free(lines[i]);
		i++;
	}
}

void	parse_cub_file(char *filename, t_game *game)
{
	char	*file_content;
	char	**lines;

	file_content = read_file_to_string(filename);
	lines = ft_split(file_content, '\n');
	free(file_content);
	if (!lines)
		error_exit("Error: Failed to split file content");
	if (!game->map || !game->map[0])
		error_exit("Error: Map is not initialized correctly");
	parse_lines(lines, game);
	free(lines);
	validate_map(game);
}

void	parse_texture(char *line, t_game *game)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split[1] || split[2])
		error_exit("Error: Invalid texture format");
	if (ft_strncmp(split[0], "NO", 2) == 0)
		game->textures.north = ft_strdup(split[1]);
	else if (ft_strncmp(split[0], "SO", 2) == 0)
		game->textures.south = ft_strdup(split[1]);
	else if (ft_strncmp(split[0], "WE", 2) == 0)
		game->textures.west = ft_strdup(split[1]);
	else if (ft_strncmp(split[0], "EA", 2) == 0)
		game->textures.east = ft_strdup(split[1]);
	else
		error_exit("Error: Invalid texture identifier");
	fsplit(split);
}

void	parse_color(char *line, t_game *game)
{
	char	**split;
	char	**rgb;
	int		r;
	int		g;
	int		b;

	split = ft_split(line, ' ');
	if (!split[1] || split[2])
		error_exit("Error: Invalid color format");
	rgb = ft_split(split[1], ',');
	if (!rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
		error_exit("Error: Invalid RGB format");
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		error_exit("Error: RGB values out of range");
	if (ft_strncmp(split[0], "F", 1) == 0)
		game->floor_color = (r << 16) | (g << 8) | b;
	else if (ft_strncmp(split[0], "C", 1) == 0)
		game->ceiling_color = (r << 16) | (g << 8) | b;
	else
		error_exit("Error: Invalid color identifier");
	fsplit(rgb);
	fsplit(split);
}
