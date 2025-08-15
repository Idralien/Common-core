/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:57:07 by quvan-de          #+#    #+#             */
/*   Updated: 2025/03/10 13:29:31 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	process_map_line(char *line, t_game *game)
{
	char	**new_map;
	int		i;

	line = map_line_parse(line);
	new_map = (char **)malloc(sizeof(char *) * (game->map.height + 1));
	if (!new_map)
		return (print_error("Error\nMemory allocation failed for map!"));
	i = 0;
	while (i < game->map.height)
	{
		new_map[i] = game->map.map[i];
		i++;
	}
	new_map[game->map.height] = ft_strdup(line);
	if (!new_map[game->map.height])
	{
		free(new_map);
		return (print_error("Error\nMemory allocation failed for map row!"));
	}
	free(game->map.map);
	game->map.map = new_map;
	game->map.height++;
	free(line);
	return (1);
}

static int	check_and_init_flags(t_game *game, char *trimmed_line, bool *t_init,
		bool *c_init)
{
	if (parse_textures_and_colors(trimmed_line, game))
	{
		if (game->map_flags.has_texture == 4)
			*t_init = true;
		if (game->map_flags.has_color == 2)
			*c_init = true;
		return (1);
	}
	return (0);
}

static int	handle_empty_line(char *trimmed_line)
{
	if (trimmed_line == NULL || ft_strlen(trimmed_line) == 0)
	{
		free(trimmed_line);
		return (1);
	}
	return (0);
}

int	get_data(char *line, t_game *game)
{
	static bool	t_init;
	static bool	c_init;
	char		*trimmed_line;

	trimmed_line = trim_whitespace(line);
	if (handle_empty_line(trimmed_line))
		return (1);
	if (check_and_init_flags(game, trimmed_line, &t_init, &c_init))
	{
		free(trimmed_line);
		return (1);
	}
	if (is_map_line(trimmed_line))
	{
		if (!t_init || !c_init)
		{
			free(trimmed_line);
			return (print_error("Error\nMissing texture or color data"));
		}
		process_map_line(trimmed_line, game);
		free(trimmed_line);
		return (1);
	}
	free(trimmed_line);
	return (0);
}
