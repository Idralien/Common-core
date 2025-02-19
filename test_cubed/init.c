/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 01:25:12 by brsantsc          #+#    #+#             */
/*   Updated: 2025/02/19 11:41:04 by brsantsc         ###   ########.fr       */
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
}
