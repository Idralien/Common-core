/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_colours.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:03:50 by brsantsc          #+#    #+#             */
/*   Updated: 2025/02/07 11:26:53 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	draw_pixel(t_game *game, int x, int y, int colour)
{
	game->img.data[y * SCREEN_WIDTH + x] = colour;
}

int	get_texture_colour(t_texture *texture, int x, int y)
{
	return (texture->data[y * TEXTURE_WIDTH + x]);
}

void	load_textures(t_game *game, t_texture *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(game->mlx, path, &texture->width, &texture->height);
	if (!texture->img)
		exit_with_error("Failed to load texture");
	texture->data = (int *)mlx_get_data_addr(texture->img, &texture->bpp, &texture->line_length, &texture->endian);
}
