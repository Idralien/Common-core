/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reserve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:03:31 by brsantsc          #+#    #+#             */
/*   Updated: 2025/02/07 12:22:21 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	initialize_game(t_game *game)
{
	// sample map setup
	int	sample_map[MAP_HEIGHT][MAP_WIDTH] = {
		{1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 1},
		{1, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1},
	};

	// Assign map to the game struct
	int y = 0;
	int x = 0;
	while (y < MAP_HEIGHT)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
			game->map[y][x] = sample_map[y][x];
			x++;
		}
		y++;
	}

	// Initialize player starting position and direction
	game->pos_x = 2.5; 		// X position in the map
	game->pos_y = 2.5; 		// Y position in the map
	game->dir_x = -1;	 		// Facing west initially
	game->dir_y = 0;   		// No vertical direction
	game->plane_x = 0; 		// Perpendicular camera plane
	game->plane_y = 0.66; // Adjusted for aspect ratio

	//Initialize MiniLibX
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		perror("Error\nFailed to initialize MiniLibX");
		exit(EXIT_FAILURE);
	}

	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
	if (!game->win)
	{
		perror("Error\nFailed to create window");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
	{
		fprintf(stderr, "Error\nUsage: ./cub3D <map.cub>\n");
		return (1);
	}
	// Initialise the game structure
	if (!parse_cub_file(&game, argv[1]))
	{
		fprintf(stderr, "Error\nFailed to parse .cub file\n");
			return (1);
	}
	// initialise MLX
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		fprintf(stderr, "Error\nFailed to initialise MLX\n");
		return (1);
	}
	game.win = mlx_new_window(game.mlx, 800, 600, "cub3D");
	if (!game.win)
	{
		fprintf(stderr, "Error\nFailed to create window\n");
		return (1);
	}
	// Render loop
//	init_game(&game, argv[1]);
	init_image(&game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_loop(game.mlx);
	cleanup_game(&game);
	return (0);
}

int main(void)
{
	void	*mlx = mlx_init();
	void	*win = mlx_new_window(mlx, 800, 600, "Test");
	(void)win;
	mlx_loop(mlx);
	return (0);
}

void	store_map_data(t_game *game, const char *line)
{
	if (!game->map)
	{
		game->map = malloc(sizeof(char *) * (game->map_height + 1));
		game->map[0] = strdup(line);
		game->map_height = 1;
	}
	else
	{
		game->map = malloc(sizeof(char *) * (game->map_height + 1));
		game->map[game->map_height] = strdup(line);
		game->map_height++;
	}
	game->map[game->map_height] = NULL;
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_with_error("Failed to initialise MinilibX");
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	if (!game->win)
		exit_with_error("Failed to create window");
	init_image(game);

	//Placeholder for initialising floor and ceiling colours
	game->floor_colour = 0x00FF00;
	game->ceiling_colour = 0x0000FF;
}

void	init_image(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!game->img.img)
		exit_with_error("Failed to create render image");
	game->img.data = (int *)mlx_get_data_addr(game->img.img, &game->img.bpp, &game->img_line_length, &game->img.endian);
}

void	render_frame(t_game *game)
{
	render_floor_and_ceiling(game);
	render_walls(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}
