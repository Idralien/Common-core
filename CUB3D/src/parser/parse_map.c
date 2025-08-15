/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:57:13 by quvan-de          #+#    #+#             */
/*   Updated: 2025/03/10 13:29:40 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	validate_char(t_map *map, t_game *game)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			c = map->map[i][j];
			if (!is_map_char(c))
				return (print_error("Error\nInvalid character"));
			if ((c == 'N' || c == 'S' || c == 'E' || c == 'W')
				&& !set_player_position(game, c, j, i))
				return (0);
			j++;
		}
		i++;
	}
	if (game->map_flags.player_count != 1)
		return (print_error("Error\nMap must contain one player"));
	return (1);
}

int	parse_map(t_game *game)
{
	if (!finalize_map(game))
		return (print_error("Error\nFailed to finalize map padding"));
	if (!validate_char(&game->map, game))
		return (print_error("Error\nInvalid characters"));
	if (!validate_closed_map(&game->map, game))
		return (print_error("Error\nMap is not closed or player on edge"));
	return (1);
}
