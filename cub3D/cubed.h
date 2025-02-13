/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:53:03 by brsantsc          #+#    #+#             */
/*   Updated: 2025/02/07 12:29:47 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
#define CUBED_H

# include "mlx.h"
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

//screen
# define	SCREEN_WIDTH 800
# define	SCREEN_HEIGHT 600

// Keys 
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307

// structs
typedef struct s_axis
{
	double	x;
	double	y;
} t_axis;

typedef struct s_player
{
	t_axis	pos;
	t_axis	dir;
	t_axis	plane; // camera plane
} t_player;

typedef struct	s_texture
{
	void	*img;
	int		*data;
	int		width;
	int		length;
} t_texture;

typedef struct s_img
{
	void	*img;						// Pointer to the MiniLibX image
	int		*data;					// Pointer to image pixel data
	int		width;					// Image width
	int		height;					// Image height
	int		bpp;						// Bits per pixel
	int		line_length;		// Bytes per row of image
	int		size_line;
	int		endian;					// Endianness (0: little, 1: big)
}	t_img;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_player	player;
	int				map_width;
	int				map_height;
	int				floor_colour;
	int				ceiling_colour;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		pos_x;
	double		pos_y;
	char			**map;
	t_texture	textures[4]; // NORTH, SOUTH, WEST, EAST
} t_game;

// Movement
void	move_player(t_game *game, int direction);
void	rotate_player(t_game *game, double angle);
void	strafe_player(t_game *game, int direction);

// Parsing
void	parse_cub_file(t_game *game, const char *filename);
void	validate_map(t_game *game);
void	store_map_data(t_game *game, const char *line);

// Raycasting
void	draw_line(t_game *game, int x, int start, int end, int colour);
void	render_frame(t_game *game);
void	render_walls(t_game *game);
void	render_floor_and_ceiling(t_game *game);
int		get_texture_colour(t_texture *texture, int x, int y);

// Render
void	render_frame(t_game *game);
void	init_image(t_game *game);
void	draw_pixel(t_game *game, int x, int y, int colour);

// Minimap
void	draw_minimap(t_game *game);

// Store data
void	store_map_data(t_game *game, char *line);

// Init
void	initialize_player(t_game *game);
void	init_game(t_game *game);
// Utils
void	cleanup_game(t_game *game);
int		close_window(t_game *game);

int	main(int argc, char **argv);


//Reserve
void	initialize_game(t_game *game);

#endif
