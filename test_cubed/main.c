/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:09:05 by brsantsc          #+#    #+#             */
/*   Updated: 2025/02/17 11:15:49 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int main(int argc, char **argv)
{
    t_game game;

    printf("Program started!\n");
    if(argc != 2)
    {
        printf("Usage: ./cub3D <map_file>\n");
        return (1);
    }
    printf("Opening file: %s\n", argv[1]);

    init_game(&game);
    render_frame(&game);

    setup_hooks(&game);
    mlx_loop(game.mlx);

    return (0);
}

