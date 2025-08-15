/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:56:48 by quvan-de          #+#    #+#             */
/*   Updated: 2025/03/06 16:56:49 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

double	calc_wall_position(t_ray *ray, t_player *player)
{
	double	wall_pos;

	if (ray->side == 0)
		wall_pos = player->y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_pos = player->x + ray->perp_wall_dist * ray->ray_dir_x;
	if (wall_pos > 0)
		wall_pos = wall_pos - (int)wall_pos;
	return (wall_pos);
}

int	calc_texture(t_render *data)
{
	double	step;
	double	texture_pos;
	int		i;

	data->tex_x = (int)(data->wall_pos * data->texture->width);
	if (data->tex_x >= data->texture->width)
		data->tex_x = data->texture->width - 1;
	if (data->tex_x < 0)
		data->tex_x = 0;
	step = (double)data->texture->height / data->line_height;
	texture_pos = data->y_offset * step;
	data->tex_y = (int)texture_pos;
	if (data->tex_y >= data->texture->height)
		data->tex_y = data->texture->height - 1;
	if (data->tex_y < 0)
		data->tex_y = 0;
	i = data->tex_y * data->texture->line_length + data->tex_x
		* (data->texture->bits_per_pixel / 8);
	return (i);
}

int	texture_index(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x < 0)
			return (WEST);
		else
			return (EAST);
	}
	else
	{
		if (ray->ray_dir_y > 0)
			return (SOUTH);
		else
			return (NORTH);
	}
}

void	render_wall(t_game *game, int x)
{
	t_ray		*ray;
	t_render	data;
	int			y;
	int			color;

	ray = &game->rays[x];
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		data = prep_render(game, ray, y - (WIN_HEIGHT - ray->line_height) / 2);
		color = adjust_pixel(&data, ray->shade_factor);
		put_pixel(game, x, y, color);
		y++;
	}
}

void	render(t_game *game)
{
	int	x;

	set_colors(game);
	x = 0;
	while (x < WIN_WIDTH)
	{
		render_wall(game, x);
		x++;
	}
}
