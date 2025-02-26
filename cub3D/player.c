/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:04:05 by brsantsc          #+#    #+#             */
/*   Updated: 2025/02/25 17:20:35 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	rotate_player(t_game *game, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->dir_x;
	old_plane_x = game->plane_x;
	game->dir_x = game->dir_x * cos(angle) - game->dir_y * sin(angle);
	game->dir_y = old_dir_x * sin(angle) + game->dir_y * cos(angle);
	game->plane_x = game->plane_x * cos(angle) - game->plane_y * sin(angle);
	game->plane_y = old_plane_x * sin(angle) + game->plane_y * cos(angle);
	normalize_vector(&game->dir_x, &game->dir_y);
}

void	move_player(t_game *game, double speed)
{
	double	new_x;
	double	new_y;

	new_x = game->player_x + game->dir_x * speed;
	new_y = game->player_y + game->dir_y * speed;
	if (!is_collision(game, new_x, game->player_y))
		game->player_x = new_x;
	if (!is_collision(game, game->player_x, new_y))
		game->player_y = new_y;
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_window(game);
	if (keycode == KEY_W)
		move_player(game, MOVE_SPEED);
	if (keycode == KEY_S)
		move_player(game, -MOVE_SPEED);
	if (keycode == KEY_D)
		rotate_player(game, -ROTATE_SPEED);
	if (keycode == KEY_A)
		rotate_player(game, ROTATE_SPEED);
	render_frame(game);
	return (0);
}

void	draw_player(t_game *game)
{
	int	y;
	int	x;

	y = -5;
	while (y <= 5)
	{
		x = -5;
		while (x <= 5)
		{
			put_pixel(game, game->player_x + x, game->player_y + y, 0x0000FF00);
			x++;
		}
		y++;
	}
}

int	has_valid_start_position(char **map, t_player *player)
{
	int	x;
	int	y;
	int	found;

	found = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_strchr("NSEW", map[y][x]))
			{
				if (found)
					return (0);
				player->x = x + 0.5;
				player->y = y + 0.5;
				player->dir = map[y][x];
				found = 1;
			}
			x++;
		}
		y++;
	}
	return (found);
}
