/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:26:41 by brsantsc          #+#    #+#             */
/*   Updated: 2024/08/22 18:30:38 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

///////////////////////////////////////////////
// red=0x0000FF,green=0x00FF00,blue=0xFF0000 //
//////////////////////////////////////////////
uint64_t	interpolate(int color1, int color2, float fraction)
{
	t_rgb	rgb;

	rgb.r1 = (color1 >> 16) & 0xff;
	rgb.r2 = (color2 >> 16) & 0xff;
	rgb.g1 = (color1 >> 8) & 0xff;
	rgb.g2 = (color2 >> 8) & 0xff;
	rgb.b1 = color1 & 0xff;
	rgb.b2 = color2 & 0xff;
	return ((uint64_t)((rgb.r2 - rgb.r1) * fraction + rgb.r1) << 16 | \
	(uint64_t)((rgb.g2 - rgb.g1) * fraction + rgb.g1) << 8 | \
	(uint64_t)((rgb.b2 - rgb.b1) * fraction + rgb.b1));
}

void	picasso(t_fdf *fdf, t_coordinates *xyz)
{
	if (fdf->isometric_flag > 0)
	{
		if (fdf->colour_flag > 0)
			fdf->colour = interpolate(VIOLET, BLUE, ft_mod(xyz->y1 - xyz->y));
		else
			fdf->colour = interpolate(ROSE, VIOLET, ft_mod(xyz->y1 - xyz->y));
	}
	else
	{
		if (fdf->colour_flag > 0)
			fdf->colour = interpolate(VIOLET, GREEN, ft_mod(xyz->z1 - xyz->z));
		else
			fdf->colour = interpolate(ROSE, VIOLET, ft_mod(xyz->z1 - xyz->z));
	}
}
