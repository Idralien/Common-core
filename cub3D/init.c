/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:04:08 by brsantsc          #+#    #+#             */
/*   Updated: 2025/02/07 11:12:46 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	initialize_player(t_game *game)
{
	int y;
	int x;
	char tile;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			tile = game->map[y][x];
			if (tile == 'N' || tile == 'S' || tile == 'E' || tile == 'W')
			{
				game->player.x = x + 0.5;
				game->player.y = y + 0.5;
				if (tile == 'N')
				{
					game->player.dir_x = 0;
					game->player.dir_y = -1;
				}
				if (tile == 'S')
				{
					game->player.dir_x = 0;
					game->player.dir_y = 1;
				}
				if (tile == 'E')
				{
					game->player.dir_x = 1;
					game->player.dir_y = 0;
				}
				if (tile == 'W')
				{
					game->player.dir_x = -1;
					game->player.dir_y = 0;
				}
				game->map[y][x] = '0';
				return;
			}
			x++;
		}
		y++;
	}
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		fprintf(stderr, "Error: Failed to Initialize MLX\n");
		exit(EXIT_FAILURE);
	}
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	if (!game->win)
	{
		fprintf(stderr, "Error: Failed to create image\n");
		exit(EXIT_FAILURE);
	}
	game->player.move_speed = 0.05;
	game->player.rot_speed = 0.05;
}

void	store_map_data(t_game *game, char *line)
{
	static int row = 0;
	if (row >= game->map_height)
	{
		fprintf(stderr, "Error: Map height exceeded");
		exit(EXIT_FAILURE);
	}
	game->map[row] = strdup(line);
	row++;
}
