/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:04:05 by brsantsc          #+#    #+#             */
/*   Updated: 2025/02/06 11:19:59 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	move_player(t_game *game, int direction)
{
	double	move_speed = 0.1;
	double	new_x;
	double	new_y;

	new_x = game->pos_x + direction * game->dir_x * move_speed;
	new_y = game->pos_y + direction * game->dir_y * move_speed;
	if (game->map[(int)new_y][(int)game->pos_x] == 0)
		game->pos_y = new_y; //Move vertically if no wall
	if (game->map[(int)game->pos_y][(int)new_x] == 0)
		game->pos_x = new_x; //Move horizontally if no wall
}

void	rotate_player(t_game *game, double angle)
{
	double	old_dir_x = game->dir_x;
	double	old_plane_x = game->plane_x;

		game->dir_x = game->dir_x * cos(angle) - game->dir_y * sin(angle);
		game->dir_y = old_dir_x * sin(angle) + game->dir_y * cos(angle);

		game->plane_x = game->plane_x * cos(angle) - game->plane_y * sin(angle);
		game->plane_y = old_plane_x * sin(angle) + game->plane_y * cos(angle);
}

void	strafe_player(t_game *game, int direction)
{
	double	strafe_speed = 0.1; //adjustable
	
	// Calculate potential new position (perpendicular to direction vector)
	double new_x;
	double new_y;

	new_x = game->pos_x + direction * game->plane_x * strafe_speed;
	new_y = game->pos_y + direction * game->plane_y * strafe_speed;

	//Check for collision with walls
	if (game->map[(int)new_y][(int)game->pos_x] == 0)
		game->pos_y = new_y;
	if (game->map[(int)game->pos_y][(int)new_x] == 0)
		game->pos_x = new_x;
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		move_player(game, 0.1);
	if (keycode == KEY_S)
		move_player(game, -0.1);
	if (keycode == KEY_A)
		strafe_player(game, -1);
	if (keycode == KEY_D)
		strafe_player(game, 1);
	if (keycode == KEY_LEFT)
		rotate_player(game, -0.05);
	if (keycode == KEY_RIGHT)
		rotate_player(game, 0.05);
	if (keycode == KEY_ESC)
	{
		exit_game(game);
	}
	//Placeholder for movement and rotation logic
	printf("Key pressed: %d\n", keycode);
	return (0);
}
