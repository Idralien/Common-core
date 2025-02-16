/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:39:47 by brsantsc          #+#    #+#             */
/*   Updated: 2025/02/13 15:40:15 by brsantsc         ###   ########.fr       */
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

