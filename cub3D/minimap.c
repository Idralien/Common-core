/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:04:13 by brsantsc          #+#    #+#             */
/*   Updated: 2025/02/06 15:34:58 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	draw_minimap(t_game *game)
{
	int	scale = 5;
	int	start_x = 10;
	int	start_y = 10;
	int	y = 0;
	int	x = 0;
	int	i;
	int j;
	int colour;
	int px;
	int py;

	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			colour = (game->map[y][x] == '1') ? 0xFFFFFF : 0x000000;
			i = 0;
			while (i < scale)
			{
				j = 0;
				while (j < scale)
				{
					game->img.data[(start_y + y * scale + i) * SCREEN_WIDTH + (start_x + x * scale + j)] = colour;
				}
				i++;
			}
			x++;
		}
		y++;
	}
	px = start_x + (int)(game->pos_x * scale);
	py = start_y + (int)(game->pos_y * scale);
	i = -2;
	while (i <= 2)
	{
		j = -2;
		while (j <= 2)
		{
			game->img.data[(py + i) * SCREEN_WIDTH + (px + j)] = 0xFF0000;
			j++;
		}
		i++;
	}
}
