/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:56:50 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/10 13:27:39 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	set_north_south_direction(t_player *player, char direction)
{
	if (direction == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	else if (direction == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
}

static void	set_east_west_direction(t_player *player, char direction)
{
	if (direction == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
	else if (direction == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
}

static void	set_player_direction(t_player *player, char direction)
{
	if (direction == 'N' || direction == 'S')
		set_north_south_direction(player, direction);
	else if (direction == 'E' || direction == 'W')
		set_east_west_direction(player, direction);
}

int	set_player_position(t_game *game, char direction, int x, int y)
{
	game->map_flags.player_count++;
	if (game->map_flags.player_count > 1)
		return (print_error("Error\nMultiple player"));
	game->player.x = x + 0.5;
	game->player.y = y + 0.5;
	set_player_direction(&game->player, direction);
	return (1);
}
