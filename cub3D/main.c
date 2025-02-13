/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:03:39 by brsantsc          #+#    #+#             */
/*   Updated: 2025/02/06 11:24:12 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_game game;

	initialize_game(&game);
	mlx_key_hook(game.win, key_press, &game);
	mlx_loop(game.mlx);
	return(0);
}
