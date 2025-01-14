#include "cubed.h"

int	close_window(t_game *game)
{
	cleanup_game(game);
	exit(0);
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

/*int main(void)
{
	void	*mlx = mlx_init();
	void	*win = mlx_new_window(mlx, 800, 600, "Test");
	(void)win;
	mlx_loop(mlx);
	return (0);
}*/
