#include "cubed.h"

bool	parse_cub_file(t_game *game, const char *path)
{
	// Open the .cub file
	int	fd = open(path, O_RDONLY);
	if (fd < 0)
		return false;
	// TODO: Parse map, textures, and colours
	// for now, initialise hardcoded values
/*	game->map_width = 10;
	game->map_height = 10;
	game->floor_colour = 0x00FF00; //green
	game->ceiling_colour = 0x0000FF; //Blue */
	game->map = malloc(sizeof(char *) * 6);
	game->map[0] = strdup("111111");
	game->map[1] = strdup("100001");
	game->map[2] = strdup("101001");
	game->map[3] = strdup("1000N1");
	game->map[4] = strdup("111111");
	game->map[5] = NULL;
	game->player.pos.x = 3.5;
	game->player.pos.y = 3.5;
	game->player.dir.x = -1;
	game->player.dir.y = 0;
	game->player.plane.x = 0;
	game->player.plane.y = 0.66;
	load_texture(&game, &game.texture[0], "path_to_north_texture.xpm");
	load_texture(&game, &game.texture[1], "path_to_south_texture.xpm");
	load_texture(&game, &game.texture[2], "path_to_west_texture.xpm");
	load_texture(&game, &game.texture[3], "path_to_east_texture.xpm");
	close(fd);
	return true;
}

void	load_textures(t_game *game, t_texture *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(game->mlx, path, &texture->width, &texture->height);
	if (!texture->img)
		exit_with_error("Failed to load texture");
	texture->data = (int *)mlx_get_data_addr(texture->img, &texture->bpp, &texture->line_length, &texture->endian);
}
