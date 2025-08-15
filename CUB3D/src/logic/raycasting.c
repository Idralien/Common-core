/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:56:44 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/10 13:23:34 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_ray(t_ray *ray, t_player *player, int screen_x, int win_width)
{
	ray->camera_x = 2 * screen_x / (double)win_width - 1;
	ray->ray_dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->ray_dir_y = player->dir_y + player->plane_y * ray->camera_x;
}

void	setup_ray(t_ray *ray, t_player *player)
{
	ray->map_x = (int)player->x;
	ray->map_y = (int)player->y;
	ray->delta_dist_x = fabs(1.0 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1.0 / ray->ray_dir_y);
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player->x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - player->y) * ray->delta_dist_y;
	}
}

int	run_dda(t_ray *ray, char **map)
{
	int	i;

	i = 0;
	while (i == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (map[ray->map_y][ray->map_x] == '1')
			i = 1;
	}
	return (i);
}

void	set_wall_properties(t_ray *ray, int win_height)
{
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_dist_y;
	if (ray->perp_wall_dist < 0.0001)
		ray->perp_wall_dist = 0.0001;
	ray->line_height = (int)(win_height / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + win_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + win_height / 2;
	if (ray->draw_end >= win_height)
		ray->draw_end = win_height - 1;
	ray->shade_factor = 1.0 / (1.0 + ray->perp_wall_dist * 0.1);
}

void	raycasting(t_game *game)
{
	int		x;
	t_ray	*ray;

	x = 0;
	while (x < WIN_WIDTH)
	{
		ray = &game->rays[x];
		init_ray(ray, &game->player, x, WIN_WIDTH);
		setup_ray(ray, &game->player);
		if (run_dda(ray, game->map.map))
			set_wall_properties(ray, WIN_HEIGHT);
		x++;
	}
}
