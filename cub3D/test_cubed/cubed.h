/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:53:03 by brsantsc          #+#    #+#             */
/*   Updated: 2025/02/14 11:23:01 by brsantsc         ###   ########.fr       */
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

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define MOVE_SPEED 0.1
#define ROTATE_SPEED 0.05
#define MAP_WIDTH 10
#define MAP_HEIGHT 10

#define KEY_ESC 65307  // MacOS: 53, Linux: 65307
#define KEY_W 119    // MacOS: 13, Linux: 119
#define KEY_A 97     // MacOS: 0, Linux: 97
#define KEY_S 115    // MacOS: 1, Linux: 115
#define KEY_D 100     // MacOS: 2, Linux: 100
#define KEY_LEFT 65361  // MacOS: 123, Linux: 65361
#define KEY_RIGHT 65363 // MacOS: 124, Linux: 65363

typedef struct s_img
{
    void    *img;
    char    *addr;
    int     bpp;
    int     line_length;
    int     endian;
} t_img;

typedef struct s_game
{
    void    *mlx;
    void    *win;
    t_img   img;

    double  player_x;
    double  player_y;
    double  dir_x;
    double  dir_y;
    double  plane_x;
    double  plane_y;

    int     ceiling_color;
    int     floor_color;
    char    **map; 
} t_game;

typedef struct s_draw
{
    int x;
    int start;
    int end;
    int color;
} t_draw;


void	put_pixel(t_game *game, int x, int y, int colour);
void	create_image(t_game *game);

int key_press(int keycode, t_game *game);
int close_window(t_game *game);
void    setup_hooks(t_game *game);

void    update_frame(t_game *game);
void    draw_player(t_game *game);

void draw_vertical_line(t_game *game, t_draw draw);
void fill_background(t_game *game);
void render_rays(t_game *game);
void render_frame(t_game *game);

void    init_image(t_game *game);
void    init_game(t_game *game);

#endif
