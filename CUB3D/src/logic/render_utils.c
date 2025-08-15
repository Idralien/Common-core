/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:56:46 by quvan-de          #+#    #+#             */
/*   Updated: 2025/03/10 13:23:41 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	adjust_color(int color, double factor)
{
	int	r;
	int	g;
	int	b;

	r = ((color >> 16) & 0xFF) * factor;
	g = ((color >> 8) & 0xFF) * factor;
	b = (color & 0xFF) * factor;
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	return ((r << 16) | (g << 8) | b);
}

int	adjust_pixel(t_render *data, double shade_factor)
{
	int	offset;
	int	color;
	int	i;

	offset = calc_texture(data);
	color = *(unsigned int *)(data->texture->addr + offset);
	i = adjust_color(color, shade_factor);
	return (i);
}

t_render	prep_render(t_game *game, t_ray *ray, int y_offset)
{
	int			i;
	t_render	data;

	i = texture_index(ray);
	data.texture = &game->texture[i];
	data.wall_pos = calc_wall_position(ray, &game->player);
	data.line_height = ray->line_height;
	data.y_offset = y_offset;
	data.tex_x = 0;
	data.tex_y = 0;
	return (data);
}
