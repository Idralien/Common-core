/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:57:19 by quvan-de          #+#    #+#             */
/*   Updated: 2025/03/10 13:33:07 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	find_max_width(char **lines)
{
	int	max_width;
	int	line_length;

	max_width = 0;
	while (*lines)
	{
		line_length = ft_strlen(*lines);
		if (line_length > max_width)
			max_width = line_length;
		lines++;
	}
	return (max_width);
}

char	*map_line_parse(char *str)
{
	char	*line;
	int		i;

	line = ft_strtrim(str, " ");
	if (!line)
		return (NULL);
	i = 0;
	while (line[i])
	{
		if (ft_isspace(line[i]))
			line[i] = '1';
		i++;
	}
	return (line);
}

static int	calculate_max_width(t_game *game)
{
	int	i;
	int	line_length;

	game->map.width = 0;
	i = 0;
	while (i < game->map.height)
	{
		line_length = ft_strlen(game->map.map[i]);
		if (line_length > game->map.width)
			game->map.width = line_length;
		i++;
	}
	return (1);
}

static int	pad_map_lines(t_game *game)
{
	int		i;
	int		line_length;
	char	*padded_line;

	i = 0;
	while (i < game->map.height)
	{
		line_length = ft_strlen(game->map.map[i]);
		if (line_length < game->map.width)
		{
			padded_line = malloc(game->map.width + 1);
			if (!padded_line)
				return (0);
			ft_strcpy(padded_line, game->map.map[i]);
			ft_memset(padded_line + line_length, '1', game->map.width
				- line_length);
			padded_line[game->map.width] = '\0';
			free(game->map.map[i]);
			game->map.map[i] = padded_line;
		}
		i++;
	}
	return (1);
}

int	finalize_map(t_game *game)
{
	if (!calculate_max_width(game))
		return (0);
	if (!pad_map_lines(game))
		return (0);
	return (1);
}
