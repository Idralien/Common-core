#include "cubed.h"

void	render_frame(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);

	//TODO: Implement raycasting logic
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, "Rendering...");
}

void	init_image(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!game->img.img)
		exit_with_error("Failed to create render image");
	game->img.data = (int *)mlx_get_data_addr(game->img.img, &game->img.bpp, &game->img_line_length, &game->img.endian);
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

void	draw_pixel(t_game *game, int x, int y, int colour)
{
	game->img.data[y * SCREEN_WIDTH + x] = colour;
}
