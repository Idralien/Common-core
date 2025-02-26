/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:53:03 by brsantsc          #+#    #+#             */
/*   Updated: 2025/02/26 11:41:20 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H

# include "mlx.h"
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

//screen
# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 600
# define MOVE_SPEED 0.1
# define ROTATE_SPEED 0.05
# define MAP_WIDTH 10
# define MAP_HEIGHT 10

// Keys 
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307

// Structures
typedef struct s_player
{
	char	dir;
	double	x;
	double	y;
}	t_player;

typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
}	t_textures;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	double			player_x;
	double			player_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	int				ceiling_color;
	int				floor_color;
	char			**map;
	t_textures		textures;
	t_player		player;
	t_img			img;
}	t_game;

typedef struct s_draw
{
	int	x;
	int	start;
	int	end;
	int	color;
}	t_draw;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
}	t_ray;

//FUNCTIONS
//Cub_parse_file
char	*read_file_to_string(const char *filename);
void	parse_lines(char **lines, t_game *game);
void	parse_cub_file(char *filename, t_game *game);
void	parse_texture(char *line, t_game *game);
void	parse_color(char *line, t_game *game);
void	parse_map(char *line, t_game *game);
void	validate_map(t_game *game);
int		is_texture_line(char *line);
int		is_color_line(char *line);
int		is_map_line(char *line);
int		is_empty_line(char *line);
char	**append_to_map(char **map, char *line);
int		check_top_bottom_walls(char **map);
int		check_side_walls(char **map);
int		is_surrounded_by_walls(char **map, int i, int j);
int		check_map_validity(char **map);
int		is_map_closed(char **map);

//Image
void	put_pixel(t_game *game, int x, int y, int color);
void	create_image(t_game *game);
void	update_frame(t_game *game);
int		close_window(t_game *game);

//Init
void	init_image(t_game *game);
void	init_mlx(t_game *game);
void	init_player(t_game *game);
void	int_colors_and_map(t_game *game);
void	init_game(t_game *game);

//Keys
void	normalize_vector(double *x, double *y);
void	rotate_player(t_game *game, double angle);
int		is_collision(t_game *game, double x, double y);
void	move_player(t_game *game, double speed);
int		key_press(int keycode, t_game *game);
void	setup_hooks(t_game *game);

//Player
void	draw_player(t_game *game);
int		has_valid_start_position(char **map, t_player *player);

//Render 1
void	draw_vertical_line(t_game *game, t_draw draw);
void	fill_background(t_game *game);
void	fill_background_norm(t_game *game);
void	render_frame(t_game *game);
void	render_rays(t_game *game);

//Render 2
void	init_ray(t_game *game, int x, t_ray *ray);
void	calculate_step_and_side_dist(t_game *game, t_ray *ray);
void	perform_dda(t_game *game, t_ray *ray);
void	calculate_wall_distance(t_game *game, t_ray *ray);
void	draw_ray(t_game *game, int x, t_ray *ray);

//utils
void	error_exit(const char *message);
void	fsplit(char **array);

//Libft
int		ft_atoi(const char *str);
int		ft_strncmp(char const *s1, char const *s2, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);

//Main
int		main(int argc, char **argv);

#endif
