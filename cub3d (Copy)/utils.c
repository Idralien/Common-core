#include "cubed.h"

void	cleanup_game(t_game *game)
{
	int	i;

	i = 0;
	// Free textures, map, and other resources
	if (game->map)
	{
		i = 0;
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		free(game->mlx);
}
