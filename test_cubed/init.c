/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 01:25:12 by brsantsc          #+#    #+#             */
/*   Updated: 2025/02/14 01:37:23 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void init_image(t_game *game)
{
    game->img.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
    game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp,
                                       &game->img.line_length, &game->img.endian);
}

void init_game(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
    {
        perror("Error initializing MLX");
        exit(EXIT_FAILURE);
    }

    game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
    if (!game->win)
    {
        perror("Error creating window");
        exit(EXIT_FAILURE);
    }

    init_image(game); // Initialize the image buffer

    // Set player start position and direction
    game->player_x = 2.0;
    game->player_y = 2.0;
    game->dir_x = -1;
    game->dir_y = 0;
    game->plane_x = 0;
    game->plane_y = 0.66;

    // Set colors (example: sky blue and ground brown)
    game->ceiling_color = 0x87CEEB;
    game->floor_color = 0x8B4513;

    // Define a simple test map (walls = '1', empty space = '0')
    static char *map[] = {
        "111111",
        "100001",
        "100001",
        "100001",
        "111111",
        NULL
    };
    game->map = map;
}
