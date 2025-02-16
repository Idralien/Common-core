/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:00:34 by brsantsc          #+#    #+#             */
/*   Updated: 2025/02/16 23:48:39 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void draw_vertical_line(t_game *game, t_draw draw)
{
    printf("Drawing line at x = %d, start = %d, end = %d, color = %#08x\n",
           draw.x, draw.start, draw.end, draw.color);

    for (int y = draw.start; y <= draw.end; y++)
    {
        int pixel = (y * game->img.line_length / 4) + draw.x;
        ((int *)game->img.addr)[pixel] = draw.color;
    }
}

void fill_background(t_game *game)
{
    printf("Filling background...\n");
    int *pixels = (int *)game->img.addr;
    for (int y = 0; y < SCREEN_HEIGHT / 2; y++)
    {
        for (int x = 0; x < SCREEN_WIDTH; x++)
            pixels[y * (game->img.line_length / 4) + x] = game->ceiling_color;
    }
    for (int y = SCREEN_HEIGHT / 2; y < SCREEN_HEIGHT; y++)
    {
        for (int x = 0; x < SCREEN_WIDTH; x++)
            pixels[y * (game->img.line_length / 4) + x] = game->floor_color;
    }
}

void render_rays(t_game *game)
{
    printf("Rendering rays...\n");
    for (int x = 0; x < SCREEN_WIDTH; x++)
    {
        double camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
        double ray_dir_x = game->dir_x + game->plane_x * camera_x;
        double ray_dir_y = game->dir_y + game->plane_y * camera_x;

        int map_x = (int)game->player_x;
        int map_y = (int)game->player_y;

        double side_dist_x;
        double side_dist_y;

        double delta_dist_x = fabs(1 / ray_dir_x);
        double delta_dist_y = fabs(1 / ray_dir_y);
        double perp_wall_dist;

        int step_x;
        int step_y;
        int hit = 0;
        int side;

        if (ray_dir_x < 0)
        {
            step_x = -1;
            side_dist_x = (game->player_x - map_x) * delta_dist_x;
        }
        else
        {
            step_x = 1;
            side_dist_x = (map_x + 1.0 - game->player_x) * delta_dist_x;
        }
        if (ray_dir_y < 0)
        {
            step_y = -1;
            side_dist_y = (game->player_y - map_y) * delta_dist_y;
        }
        else
        {
            step_y = 1;
            side_dist_y = (map_y + 1.0 - game->player_y) * delta_dist_y;
        }

        while (hit == 0)
        {
            if (side_dist_x < side_dist_y)
            {
                side_dist_x += delta_dist_x;
                map_x += step_x;
                side = 0;
            }
            else
            {
                side_dist_y += delta_dist_y;
                map_y += step_y;
                side = 1;
            }
            if (game->map[map_y][map_x] == '1') hit = 1;
        }

        printf("Ray %d hit wall at (%d, %d)\n", x, map_x, map_y);
        if (side == 0) perp_wall_dist = (map_x - game->player_x + (1 - step_x) / 2) / ray_dir_x;
        else perp_wall_dist = (map_y - game->player_y + (1 - step_y) / 2) / ray_dir_y;

        int line_height = (int)(SCREEN_HEIGHT / perp_wall_dist);
        int draw_start = -line_height / 2 + SCREEN_HEIGHT / 2;
        if (draw_start < 0) draw_start = 0;
        int draw_end = line_height / 2 + SCREEN_HEIGHT / 2;
        if (draw_end >= SCREEN_HEIGHT) draw_end = SCREEN_HEIGHT - 1;

        int color = (side == 1) ? 0xAAAAAA : 0xFFFFFF;
        t_draw draw = {x, draw_start, draw_end, color};
        draw_vertical_line(game, draw);
    }
    printf("Rays rendered!\n");
}

void render_frame(t_game *game)
{
    printf("Rendering frame...\n");
    mlx_hook(game->win, 17, 0, close_window, &game); // Handle window close
    mlx_clear_window(game->mlx, game->win);
    fill_background(game);

    printf("Calling render_rays...\n");
    render_rays(game);
    printf("render_rays finished!\n");

    mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
    printf("Frame rendered!\n");
}
