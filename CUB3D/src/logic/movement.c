/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:56:41 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/10 13:22:34 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	rotate_player(t_player *player, int direction)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot_angle;

	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	rot_angle = direction * ROT_SPEED;
	player->dir_x = player->dir_x * cos(rot_angle) - player->dir_y
		* sin(rot_angle);
	player->dir_y = old_dir_x * sin(rot_angle) + player->dir_y * cos(rot_angle);
	player->plane_x = player->plane_x * cos(rot_angle) - player->plane_y
		* sin(rot_angle);
	player->plane_y = old_plane_x * sin(rot_angle) + player->plane_y
		* cos(rot_angle);
}

int	move_forward_backward(t_game *game, int direction)
{
	t_player	*player;
	double		move_step;

	player = &game->player;
	move_step = direction * MOVE_SPEED;
	if (game->map.map[(int)(player->y)][(int)(player->x + player->dir_x
			* move_step)] != '1')
		player->x += player->dir_x * move_step;
	if (game->map.map[(int)(player->y + player->dir_y
			* move_step)][(int)(player->x)] != '1')
		player->y += player->dir_y * move_step;
	return (1);
}

void	move_left_right(t_player *player, char **map, int direction)
{
	double	move_step;

	move_step = direction * MOVE_SPEED;
	if (map[(int)(player->y)][(int)(player->x + player->plane_x
			* move_step)] != '1')
		player->x += player->plane_x * move_step;
	if (map[(int)(player->y + player->plane_y
			* move_step)][(int)(player->x)] != '1')
		player->y += player->plane_y * move_step;
}

int	update_player(t_game *game)
{
	int	i;

	i = 0;
	if (game->player.move_speed != 0)
	{
		if (game->player.move_speed > 0)
			i += move_forward_backward(game, 1);
		else
			i += move_forward_backward(game, -1);
	}
	if (game->player.strafe_speed != 0)
	{
		if (game->player.strafe_speed > 0)
			move_left_right(&game->player, game->map.map, 1);
		else
			move_left_right(&game->player, game->map.map, -1);
	}
	if (game->player.rot_speed != 0)
	{
		if (game->player.rot_speed > 0)
			rotate_player(&game->player, 1);
		else
			rotate_player(&game->player, -1);
	}
	return (i);
}
