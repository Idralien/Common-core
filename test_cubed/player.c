/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:39:47 by brsantsc          #+#    #+#             */
/*   Updated: 2025/02/17 16:43:27 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void draw_player(t_game *game)
{
    for (int y = -5; y <= 5; y++)
    {
        for (int x = -5; x <= 5; x++)
        {
            put_pixel(game, game->player_x + x, game->player_y + y, 0x0000FF00); // Green color
        }
    }
}

int has_valid_start_position(char **map, t_player *player)
{
    int x, y;
    int found = 0;

    for (y = 0; map[y]; y++)
    {
        for (x = 0; map[y][x]; x++)
        {
            if (ft_strchr("NSEW", map[y][x]))
            {
                if (found)  // More than one player start position found
                    return 0;
                player->x = x + 0.5; // Store player's position with offset
                player->y = y + 0.5;
                player->dir = map[y][x]; // Store player's direction
                found = 1;
            }
        }
    }
    return found;  // Return 1 if a valid position was found, otherwise 0
}
