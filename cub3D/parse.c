/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:03:45 by brsantsc          #+#    #+#             */
/*   Updated: 2025/02/06 12:03:15 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	parse_cub_file(t_game *game, const char *filename)
{
	int fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("ERROR opening map file");
		exit(EXIT_FAILURE);
	}

	char *line;
	while ((line = get_next_line(fd)))
	{
		if (strncmp(line, "NO ", 3) == 0)
			game->textures[0] = strdup(line + 3);
		else if (strncmp(line, "SO ", 3) == 0)
			game->textures[1] = strdup(line + 3);
		else if (strncmp(line, "WE ", 3) == 0)
			game->textures[2] = strdup(line + 3);
		else if (strncmp(line, "EA ", 3) == 0)
			game->textures[3] = strdup(line + 3);
		else if (strncmp(line, "F ", 2) == 0)
			game->floor_colour = parse_colour(line + 2);
		else if (strncmp(line, "C ", 2) == 0)
			game->ceiling_colour = parse_colour(line + 2);
		else if (strlen(line) > 0)
			store_map_data(game, line);
		free(line);
	}
	close(fd);
	validate_map(game);
}

int	parse_colour(char *line)
{
	int	r, g, b;
	if (sscanf(line, "%d,%d,%d", &r, &g, &b) != 3)
		exit_with_error("Invalid colour format");
	return (r << 16 | g << 8 | b);
}

void	validate_map(t_game *game)
{
	int player_count = 0;
	int y = 0;
	while (y < game->map_height)
	{
		int x = 0;
		while (x < game->map_width)
		{
			char tile = game->map[y][x];
			if (tile == 'N' || tile == 'S' || tile == 'E' || tile == 'W')
				player_count++;
			else if (tile != '0' && tile != '1' && tile != ' ')
			{
				fprintf(stderr, "Error: Invalid character in map\n");
				exit(EXIT_FAILURE);
			}
			x++;
		}
		y++;
	}
	if (player_count != 1)
	{
		fprintf(stderr, "Error: Map must have exactly one player start position\n");
		exit(EXIT_FAILURE);
	}
}
