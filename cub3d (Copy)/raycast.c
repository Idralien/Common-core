#include "cubed.h"

//Function to draw a vertical line on the screen
void	draw_line(t_game *game, int x, int start, int end, int colour)
{
	int y;

	y = start;
	while(y <= end)
	{
		mlx_pixel_put(game->mlx, game->win, x, y, colour);
		y++;
	}
}

void	render_frame(t_game *game)
{
	int	screen_width = 800; // hardcoded for now
	int	screen_height = 600; // hardcoded for now
	double	camera_x, ray_dir_x, ray_dir_y;
	int	map_x, map_y, step_x, step_y, hit, side;
	double	delta_dist_x, delta_dist_y, side_dist_x, side_dist_y, perp_wall_dist;
	int	line_height, draw_start, draw_end;
	int	x;
	int y;
	int	colour;
	double	wall_x; //Exact position where wall was hit
	int	tex_x, tex_y;
	double	tex_pos;
	double	step;

	x = 0;
	while (x < screen_width)
	{
		//Calcute where the wall was hit
		if (side == 0)
			wall_x = game->player.pos.y + perp_wall_dist * ray_dir_y;
		else
			wall_x = game->player.pos.x + perp_wall_dist * ray_dir_x;
		wall_x -= floor(wall_x);

		//Get the texture X coordinate
		tex_x = (int)(wall_x * (double)TEXTURE_WIDTH);
		if (side == 0 && ray_dir_x > 0) tex_x = TEXTURE_WIDTH - tex_x - 1;
		if (side == 1 && ray_dir_y < 0) tex_x = TEXTURE_WIDTH - tex_x - 1;

		//Calculate step for texture mapping and initial texture position
		step = 1.0 * TEXTURE_HEIGHT / line_height;
		tex_pos = (draw_start - screen_height / 2 + line_height / 2) * step;

		//Draw the textured wall slice
		y = draw_start;
		while (y < draw_end)
		{
			tex_y = (int)tex_pos & (TEXTURE_HEIGHT - 1);
			tex_pos += step;
			colour = get_texture_colour(game->textures[side], tex_x, tex_y);
			mlx_pixel_put(game->mlx, game->win, x, y, colour);
			y++;
		}
		x++;
	}

	x = 0;
	mlx_clear_window(game->mlx, game->win);
	while(x < screen_width)
	{
		// Step 1: Calculate ray position and direction
		camera_x = 2 * x / (double)screen_width - 1; // x-coordinate in camera space
		ray_dir_x = game->player.dir.x + game->player.plane.x * camera_x;
		ray_dir_y = game->player.dir.y + game->player.plane.y * camera_x;

		map_x = (int)game->player.pos.x;
		map_y = (int)game->player.pos.y;

		// Step 2: Calculate delta distances
		delta_dist_x = fabs(1 / ray_dir_x);
		delta_dist_y = fabs(1 / ray_dir_y);

		// Step 3: Calculate step and initial sideDist
		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (game->player.pos.x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - game->player.pos.x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (game->player.pos.y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - game->player.pos.y) * delta_dist_y;
		}

		// Step 4: perform DDA
		hit = 0;
		while(hit == 0)
		{
			// Jump to the next map square
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0; // Vertical wall
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1; // Horizontal wall
			}
			// Check if ray has hit a wall
			if (game->map[map_y][map_x] == '1')
				hit = 1;
		}

		// Step 5: Calculate distance to the wall
		if (side == 0)
			perp_wall_dist = (map_x - game->player.pos.x + (1 - step_x) / 2) / ray_dir_x;
		else
			perp_wall_dist = (map_y - game->player.pos.y + (1 - step_y) / 2) / ray_dir_y;

		// Step 6: Calculate line height and vertical start/end points
		line_height = (int)(screen_height / perp_wall_dist);
		draw_start = -line_height / 2 + screen_height / 2;
		if (draw_start < 0) draw_start = 0;
		draw_end = line_height / 2 + screen_height / 2;
		if (draw_end >= screen_height) draw_end = screen_height - 1;

		// Step 7: Choose wall colour based on side
		int	colour = (side == 0) ? 0xFF0000 : 0x00FF00; // Red vertical, Green horizontal
		// Step 8: Draw the wall slice
		draw_line(game, x, draw_start, draw_end, colour);
		x++;
	}
	tex_t = (int)(wall_hit_point * texture_width) % texture_width;
	y = draw_start;
	while (y < draw_end)
	{
		tex_y = (y * 2 - screen_height + line_height) * texture_height / (2 * line_height);
		colour = game->textures[wall_direction].data[tex_y * texture_width + tex_x];
		game->img.data[y * screen_width + x] = colour;
		y++;
	}
}

int	get_texture_colour(t_texture *texture, int x, int y)
{
	return (texture->data[y * TEXTURE_WIDTH + x]);
}

int	parse_colour(char *line)
{
	int	r, g, b;
	if (sscanf(line, "%d,%d,%d", &r, &g, &b) != 3)
		exit_with_error("Invalid colour format");
	return (r << 16 | g << 8 | b);
}
// Loading textures function
