/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:04:18 by brsantsc          #+#    #+#             */
/*   Updated: 2025/02/26 10:48:07 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	put_pixel(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	dst = game->img.addr + (y * game->img.line_length + x
			* (game->img.bpp / 8));
	*(unsigned int *)dst = color;
}

void	create_image(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!game->img.img)
	{
		perror("Error creating image");
		exit(EXIT_FAILURE);
	}
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp,
			&game->img.line_length, &game->img.endian);
}

void	update_frame(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}
