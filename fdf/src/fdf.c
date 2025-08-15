/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:27:18 by brsantsc          #+#    #+#             */
/*   Updated: 2024/08/22 14:27:39 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	destroy(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx_ptr, fdf->img.img);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	exit(0);
}

int	main(int argc, char **argv)

{
	t_fdf	fdf;

	if (input_check(argc, argv[1]))
		return (1);
	read_file(&fdf, argv[1]);
	minilibx_init(&fdf, argv[1]);
	fdf_init(&fdf);
	image_init(&fdf);
	mlx_hook(fdf.win_ptr, 2, 1l, key_hook, &fdf);
	mlx_hook(fdf.win_ptr, 17, 1l << 15, destroy, &fdf);
	mlx_loop(fdf.mlx_ptr);
}
