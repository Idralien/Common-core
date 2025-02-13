/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:03:59 by brsantsc          #+#    #+#             */
/*   Updated: 2025/02/07 11:20:19 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	render_walls(t_game *game);
void	render_floor_and_ceiling(t_game *game);


//Function to draw a vertical line on the screen
void	draw_line(t_game *game, int x, int start, int end, int colour)
{
	int y;

	y = start;
	while(y <= end)
	{
		int	pixel = (y * game->img.line_length / 4) + x;
		((int *)game->img.addr)[pixel] = colour;
		y++;
	}
}

void	render_frame(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	memset(game->img.addr, 0, SCREEN_HEIGHT * game->img.line_length);
	render_walls(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}

void	render_walls(t_game *game)
{
	int	x;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		double camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
		double ray_dir_x = game->dir_x + game->plane_x * camera_x;
		double ray_dir_y = game->dir_y + game->plane_y * camera_x;

		int map_x = (int)game->pos_x;
		int map_y = (int)game->pos_y;

		double delta_dist_x = fabs(1 / ray_dir_x);
		double delta_dist_y = fabs(1 / ray_dir_y);
		double side_dist_x, side_dist_y;
		double perp_wall_dist;
		int step_x, step_y;
		int hit = 0, side;

		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (game->pos_x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - game->pos_x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (game->pos_y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - game->pos_y) * delta_dist_y;
		}

		while (!hit)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			if (game->map[map_y][map_x] == '1')
				hit = 1;
		}
		if (side == 0)
			perp_wall_dist = (map_x - game->player.x + (1 - step_x) / 2) / ray_dir_x;
		else
			perp_wall_dist = (map_y - game->player.y + (1 - step_y) / 2) / ray_dir_y;

		int	line_height = (int)(SCREEN_HEIGHT / perp_wall_dist);
		int	draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;

		if (draw_start < 0) draw_start = 0;
		int draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
		if (draw_end >= SCREEN_HEIGHT) draw_end = SCREEN_HEIGHT - 1;
	
		int	colour = (side == 1) ? 0xAAAAAA : 0xFFFFFF;
		draw_line(game, x, draw_start, draw_end, colour);
		x++;
	}
}

void	render_floor_and_ceiling(t_game *game)
{
	int	y;
	int x;

	y = 0;
	x = 0;
	while (y < SCREEN_HEIGHT / 2)
	{
		while (x < SCREEN_WIDTH)
		{
			game->img.data[y * SCREEN_WIDTH + x] = game->ceiling_colour;
			game->img.data[(SCREEN_HEIGHT - y - 1) * SCREEN_WIDTH + x] = game->floor_colour;
			x++;
		}
		y++;
	}
}
