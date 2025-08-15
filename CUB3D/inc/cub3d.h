/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:28:44 by brsantsc          #+#    #+#             */
/*   Updated: 2025/03/10 12:57:44 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define MOVE_SPEED 0.1
# define ROT_SPEED 0.05
# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct s_map
{
	char		**map;
	char		char_start;
	int			width;
	int			height;
}				t_map;

typedef struct s_map_flags
{
	int			has_texture;
	int			has_color;
	int			player_count;
}				t_map_flags;

typedef struct s_player
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rot_speed;
	double		strafe_speed;
}				t_player;

typedef struct s_texture
{
	char		*path;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_texture;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_ray
{
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			side;
	int			tex_num;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		camera_x;
	double		shade_factor;
}				t_ray;

typedef struct s_render
{
	t_texture	*texture;
	double		wall_pos;
	int			y_offset;
	int			line_height;
	int			tex_x;
	int			tex_y;
}				t_render;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			current_line;
	t_map		map;
	t_player	player;
	t_texture	texture[5];
	t_img		img;
	t_color		floor_color;
	t_color		ceiling_color;
	t_map_flags	map_flags;
	t_ray		rays[WIN_WIDTH];
}				t_game;

int				init_game(t_game *game);
int				init_mlx(t_game *game);
int				init_img(t_game *game);
int				parse_rgb(char *line, t_color *color);
int				parse_color(char *line, t_game *game);
int				validate_texture(char *line, char **path, t_game *game);
int				check_texture_extension(char *path);
int				parse_texture(char *line, t_game *game);
int				is_map_char(char c);
int				is_map_line(const char *line);
int				validate_map(char *line, t_game *game);
int				check_file_content(t_map_flags *flags);
int				get_path(char *line, char **texture_path);
int				parse_file(const char *file_name, t_game *game);
int				get_data(char *line, t_game *game);
int				parse_map(t_game *game);
int				validate_char(t_map *map, t_game *game);
int				finalize_map(t_game *game);
int				find_max_width(char **lines);
int				validate_closed_map(t_map *map, t_game *game);
int				check_player_count(t_game *game);
int				print_error(char *error);
int				init_image(t_game *game);
int				set_player_position(t_game *game, char direction, int x, int y);
int				move_forward_backward(t_game *game, int direction);
int				update_player(t_game *game);
int				key_press(int key, t_game *game);
int				key_release(int key, t_game *game);
int				close_window(t_game *game);
int				update_frame(t_game *game);
int				adjust_color(int color, double factor);
int				adjust_pixel(t_render *data, double shade_factor);
int				texture_index(t_ray *ray);
int				calc_texture(t_render *data);
char			*trim_whitespace(char *str);
char			*map_line_parse(char *str);
void			load_textures(t_game *game);
void			put_pixel(t_game *game, int x, int y, int color);
void			set_floor(t_game *game);
void			set_ceiling(t_game *game);
void			set_colors(t_game *game);
void			raycasting(t_game *game);
void			render(t_game *game);
void			rotate_player(t_player *player, int direction);
void			move_left_right(t_player *player, char **map, int direction);
void			setup_input(t_game *game);
double			calc_wall_position(t_ray *ray, t_player *player);
t_render		prep_render(t_game *game, t_ray *ray, int y_offset);
int				process_map_line(char *line, t_game *game);
int				parse_textures_and_colors(char *line, t_game *game);
void			free_map(t_game *game);
void			free_textures(t_game *game);
void			free_images(t_game *game);
void			free_window(t_game *game);
void			free_mlx(t_game *game);
void			free_game(t_game *game);
void			cleanup_mlx(t_game *game);

#endif
