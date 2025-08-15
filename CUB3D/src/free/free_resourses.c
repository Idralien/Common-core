/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resourses.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:52:38 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/10 13:30:46 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	free_images(t_game *game)
{
	if (game->img.img != NULL)
	{
		mlx_destroy_image(game->mlx, game->img.img);
		game->img.img = NULL;
	}
}

void	free_window(t_game *game)
{
	if (game->win != NULL)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
}

void	cleanup_mlx(t_game *game)
{
	if (game->img.img)
	{
		mlx_destroy_image(game->mlx, game->img.img);
		game->img.img = NULL;
	}
	if (game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
}

void	free_game(t_game *game)
{
	free_map(game);
	free_textures(game);
	free_images(game);
	free_window(game);
	cleanup_mlx(game);
}
