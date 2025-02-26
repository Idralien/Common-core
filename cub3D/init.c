/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:04:08 by brsantsc          #+#    #+#             */
/*   Updated: 2025/02/26 11:45:41 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	init_image(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp,
			&game->img.line_length, &game->img.endian);
}

void	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		perror("Error initializing mlx");
		exit(EXIT_FAILURE);
	}
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	if (!game->win)
	{
		perror("Error creating window");
		exit(EXIT_FAILURE);
	}
	init_image(game);
}

void	init_player(t_game *game)
{
	game->player_x = 2.0;
	game->player_y = 2.0;
	game->dir_x = -1;
	game->dir_y = 0;
	game->plane_x = 0;
	game->plane_y = 0.66;
}

void	init_colors_and_map(t_game *game)
{
	static char	*map[] = {
		"11111111",
		"10000001",
		"10000001",
		"10000001",
		"100000N1",
		"11111111",
		NULL
	};

	game->ceiling_color = 0x87CEEB;
	game->floor_color = 0x8B4513;
	game->map = map;
}

void	init_game(t_game *game)
{
	init_mlx(game);
	init_player(game);
	init_colors_and_map(game);
}
