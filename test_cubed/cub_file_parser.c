/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_file_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:59:24 by brsantsc          #+#    #+#             */
/*   Updated: 2025/02/17 10:35:43 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

// Function to parse the .cub file
void parse_cub_file(char *filename, t_game *game)
{
    int fd;
    char *line;
    
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        error_exit("Error: Could not open .cub file");
    
    while ((line = get_next_line(fd)))
    {
        if (is_texture_line(line))
            parse_texture(line, game);
        else if (is_color_line(line))
            parse_color(line, game);
        else if (is_map_line(line))
            parse_map(line, game);
        else if (!is_empty_line(line))
            error_exit("Error: Invalid line in .cub file");
        free(line);
    }
    close(fd);
    validate_map(game);
}

// Function to parse texture paths
void parse_texture(char *line, t_game *game)
{
    char **split = ft_split(line, ' ');
    
    if (!split[1] || split[2])
        error_exit("Error: Invalid texture format");
    
    if (ft_strncmp(split[0], "NO", 2) == 0)
        game->textures.north = ft_strdup(split[1]);
    else if (ft_strncmp(split[0], "SO", 2) == 0)
        game->textures.south = ft_strdup(split[1]);
    else if (ft_strncmp(split[0], "WE", 2) == 0)
        game->textures.west = ft_strdup(split[1]);
    else if (ft_strncmp(split[0], "EA", 2) == 0)
        game->textures.east = ft_strdup(split[1]);
    else
        error_exit("Error: Invalid texture identifier");
    
    free_split(split);
}

// Function to parse floor and ceiling colors
void parse_color(char *line, t_game *game)
{
    char **split = ft_split(line, ' ');
    char **rgb;
    
    if (!split[1] || split[2])
        error_exit("Error: Invalid color format");
    
    rgb = ft_split(split[1], ',');
    if (!rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
        error_exit("Error: Invalid RGB format");
    
    int r = ft_atoi(rgb[0]);
    int g = ft_atoi(rgb[1]);
    int b = ft_atoi(rgb[2]);
    
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
        error_exit("Error: RGB values out of range");
    
    if (ft_strncmp(split[0], "F", 1) == 0)
        game->floor_color = (r << 16) | (g << 8) | b;
    else if (ft_strncmp(split[0], "C", 1) == 0)
        game->ceiling_color = (r << 16) | (g << 8) | b;
    else
        error_exit("Error: Invalid color identifier");
    
    free_split(rgb);
    free_split(split);
}

// Function to parse map
void parse_map(char *line, t_game *game)
{
    game->map = append_to_map(game->map, line);
}

// Function to validate the map
void validate_map(t_game *game)
{
    if (!is_map_closed(game->map))
        error_exit("Error: Map is not closed");
    if (!has_valid_start_position(game->map, &game->player))
        error_exit("Error: No valid player start position");
}

// Function to check if a line is a texture definition
int is_texture_line(char *line)
{
    return (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0 ||
            ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0);
}

// Function to check if a line is a color definition
int is_color_line(char *line)
{
    return (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0);
}

// Function to check if a line is part of the map
int is_map_line(char *line)
{
    while (*line)
    {
        if (*line != ' ' && *line != '0' && *line != '1' && *line != 'N' && *line != 'S' && *line != 'E' && *line != 'W')
            return 0;
        line++;
    }
    return 1;
}

// Function to check if a line is empty
int is_empty_line(char *line)
{
    while (*line)
    {
        if (*line != ' ' && *line != '\n')
            return 0;
        line++;
    }
    return 1;
}

