/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:14:14 by brsantsc          #+#    #+#             */
/*   Updated: 2025/02/16 23:49:24 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"


void put_pixel(t_game *game, int x, int y, int color)
{
    if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
    {
        printf("Skipping out-of-bounds pixel (%d, %d)\n", x, y);
        return;
    }
    
    char *dst = game->img.addr + (y * game->img.line_length + x * (game->img.bpp / 8));
    *(unsigned int *)dst = color;

    printf("Pixel drawn at (%d, %d) with color %#08x\n", x, y, color);
}

void create_image(t_game *game)
{
    printf("Creating image...\n");
    game->img.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
    if (!game->img.img)
    {
        perror("Error creating image");
        exit(EXIT_FAILURE);
    }

    game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp, &game->img.line_length, &game->img.endian);
    printf("Image created successfully!\n");
}

void update_frame(t_game *game)
{
    mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}

int close_window(t_game *game)
{
    printf("Closing game...\n");
    mlx_destroy_window(game->mlx, game->win);
    exit(0);
    return (0);
}
