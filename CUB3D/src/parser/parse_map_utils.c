/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:57:17 by quvan-de          #+#    #+#             */
/*   Updated: 2025/03/10 13:32:26 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	is_player_on_edge(t_map *map, t_player *player)
{
	int	x;
	int	y;

	x = (int)player->x;
	y = (int)player->y;
	if (x == 0 || x == map->width - 1 || y == 0 || y == map->height - 1)
		return (0);
	return (1);
}

static int	is_horizontal_wall(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map->width)
	{
		if (map->map[map->height - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_player_count(t_game *game)
{
	if (game->map_flags.player_count != 1)
		return (0);
	return (1);
}

static int	is_vertical_wall(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (map->map[i][0] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->map[i][map->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	validate_closed_map(t_map *map, t_game *game)
{
	if (!is_horizontal_wall(map) || !is_vertical_wall(map))
		return (0);
	if (!is_player_on_edge(map, &game->player))
		return (0);
	return (1);
}
