/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:04:05 by brsantsc          #+#    #+#             */
/*   Updated: 2025/02/25 17:10:02 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	normalize_vector(double *x, double *y)
{
	double	length;

	length = sqrt((*x) * (*x) + (*y) * (*y));
	if (length != 0)
	{
		*x /= length;
		*y /= length;
	}
}

int	is_collision(t_game *game, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_x >= MAP_WIDTH || map_y < 0 || map_y >= MAP_HEIGHT)
		return (1);
	if (game->map[map_y][map_x] == '1')
		return (1);
	return (0);
}

void	setup_hooks(t_game *game)
{
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_key_hook(game->win, key_press, game);
}
