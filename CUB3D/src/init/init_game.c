/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:52:51 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/10 13:30:13 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_map_flags(t_game *game)
{
	game->map_flags.has_texture = 0;
	game->map_flags.has_color = 0;
	game->map_flags.player_count = 0;
}

void	init_map(t_game *game)
{
	game->map.map = NULL;
	game->map.height = 0;
	game->map.width = 0;
	game->map.char_start = '0';
}

void	init_player(t_game *game)
{
	game->player.x = 0.0;
	game->player.y = 0.0;
	game->player.dir_x = 0.0;
	game->player.dir_y = 0.0;
	game->player.plane_x = 0.0;
	game->player.plane_y = 0.0;
	game->player.move_speed = 0.0;
	game->player.strafe_speed = 0.0;
	game->player.rot_speed = 0.0;
}

void	init_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		game->texture[i].path = NULL;
		game->texture[i].img = NULL;
		game->texture[i].addr = NULL;
		game->texture[i].bits_per_pixel = 0;
		game->texture[i].line_length = 0;
		game->texture[i].endian = 0;
		game->texture[i].width = 0;
		game->texture[i].height = 0;
		i++;
	}
}

int	init_game(t_game *game)
{
	if (!init_mlx(game))
	{
		printf("Error\nFailed to initialize mlx\n");
		return (0);
	}
	init_map(game);
	init_player(game);
	init_textures(game);
	init_map_flags(game);
	if (!init_img(game))
	{
		printf("Error\nFailed to initialize image\n");
		return (0);
	}
	return (1);
}
