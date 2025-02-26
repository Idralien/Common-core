/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:03:59 by brsantsc          #+#    #+#             */
/*   Updated: 2025/02/25 15:44:54 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	draw_vertical_line(t_game *game, t_draw draw)
{
	int	y;
	int	pixel;

	y = draw.start;
	while (y <= draw.end)
	{
		pixel = (y * game->img.line_length / 4) + draw.x;
		((int *)game->img.addr)[pixel] = draw.color;
		y++;
	}
}

void	fill_background(t_game *game)
{
	int	*pixels;
	int	y;
	int	x;

	pixels = (int *)game->img.addr;
	y = 0;
	while (y < SCREEN_HEIGHT / 2)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			pixels[y * (game->img.line_length / 4) + x] = game->ceiling_color;
			x++;
		}
		y++;
	}
	fill_background_norm(game);
}

void	fill_background_norm(t_game *game)
{
	int	*pixels;
	int	y;
	int	x;

	pixels = (int *)game->img.addr;
	y = SCREEN_HEIGHT / 2;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			pixels[y * (game->img.line_length / 4) + x] = game->floor_color;
			x++;
		}
		y++;
	}
}

void	render_frame(t_game *game)
{
	mlx_hook(game->win, 17, 0, close_window, &game);
	mlx_clear_window(game->mlx, game->win);
	fill_background(game);
	if (!game)
		error_exit("Error: game->map is NULL before rendering");
	render_rays(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}

void	render_rays(t_game *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		init_ray(game, x, &ray);
		calculate_step_and_side_dist(game, &ray);
		perform_dda(game, &ray);
		calculate_wall_distance(game, &ray);
		draw_ray(game, x, &ray);
		x++;
	}
}
