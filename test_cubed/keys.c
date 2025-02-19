/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:26:07 by brsantsc          #+#    #+#             */
/*   Updated: 2025/02/17 11:40:26 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void normalize_vector(double *x, double *y)
{
    double length = sqrt((*x) * (*x) + (*y) * (*y));
    if (length != 0)
    {
        *x /= length;
        *y /= length;
    }
}

void rotate_player(t_game *game, double angle)
{
    double old_dir_x = game->dir_x;
    double old_plane_x = game->plane_x;

    game->dir_x = game->dir_x * cos(angle) - game->dir_y * sin(angle);
    game->dir_y = old_dir_x * sin(angle) + game->dir_y * cos(angle);

    game->plane_x = game->plane_x * cos(angle) - game->plane_y * sin(angle);
    game->plane_y = old_plane_x * sin(angle) + game->plane_y * cos(angle);

    normalize_vector(&game->dir_x, &game->dir_y);
}

int is_collision(t_game *game, double x, double y)
{
    int map_x = (int)x;
    int map_y = (int)y;

    // Ensure the player stays within map bounds
    if (map_x < 0 || map_x >= MAP_WIDTH || map_y < 0 || map_y >= MAP_HEIGHT)
    {
        return 1; // Out-of-bounds is treated as a wall
    }

    if (game->map[map_y][map_x] == '1') // Use '1' instead of 1
    {
        return 1; // Collision detected
    }
    return 0; // No collision
}


void move_player(t_game *game, double speed)
{
    double new_x = game->player_x + game->dir_x * speed;
    double new_y = game->player_y + game->dir_y * speed;
    
    if (!is_collision(game, new_x, game->player_y)) // Check X-axis collision
    {
        game->player_x = new_x;
    }
    if (!is_collision(game, game->player_x, new_y)) // Check Y-axis collision
    {
        game->player_y = new_y;
    }
}

int key_press(int keycode, t_game *game)
{
    if (keycode == KEY_ESC)
    {
        close_window(game);
    }
    if (keycode == KEY_W)
    {
        move_player(game, MOVE_SPEED);
    }
    if (keycode == KEY_S)
    {
        move_player(game, -MOVE_SPEED);
    }
    if (keycode == KEY_D)
    {
        rotate_player(game, -ROTATE_SPEED);
    }
    if (keycode == KEY_A)
    {
        rotate_player(game, ROTATE_SPEED);
    }

    render_frame(game);
    return (0);
}

void setup_hooks(t_game *game)
{
    mlx_hook(game->win, 17, 0, close_window, game);
    mlx_key_hook(game->win, key_press, game);
}
