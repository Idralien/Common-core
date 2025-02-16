/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:26:07 by brsantsc          #+#    #+#             */
/*   Updated: 2025/02/14 11:21:45 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int key_press(int keycode, t_game *game)
{
    if (keycode == KEY_ESC)
    {
        close_window(game);
    }
    if (keycode == KEY_W)
    {
        game->player_x += game->dir_x * MOVE_SPEED;
        game->player_y += game->dir_y * MOVE_SPEED;
    }
    if (keycode == KEY_S)
    {
        game->player_x -= game->dir_x * MOVE_SPEED;
        game->player_y -= game->dir_y * MOVE_SPEED;
    }
    if (keycode == KEY_A)
    {
        double old_dir_x = game->dir_x;
        game->dir_x = game->dir_x * cos(-ROTATE_SPEED) - game->dir_y * sin(-ROTATE_SPEED);
        game->dir_y = old_dir_x * sin(-ROTATE_SPEED) + game->dir_y * cos(-ROTATE_SPEED);
    }
    if (keycode == KEY_D)
    {
        double old_dir_x = game->dir_x;
        game->dir_x = game->dir_x * cos(ROTATE_SPEED) - game->dir_y * sin(ROTATE_SPEED);
        game->dir_y = old_dir_x * sin(ROTATE_SPEED) + game->dir_y * cos(ROTATE_SPEED);
    }

    render_frame(game);
    return (0);
}

void setup_hooks(t_game *game)
{
    mlx_hook(game->win, 17, 0, close_window, game);  // Handle window close
    mlx_key_hook(game->win, key_press, game);      // Handle key press
}
