/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:09:05 by brsantsc          #+#    #+#             */
/*   Updated: 2025/02/14 11:24:49 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int main(void)
{
    t_game game;

    init_game(&game);
    render_frame(&game);

    setup_hooks(&game);
    mlx_loop(game.mlx);

    return (0);
}

