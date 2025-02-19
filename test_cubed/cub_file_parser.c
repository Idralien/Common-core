/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_file_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 09:59:24 by brsantsc          #+#    #+#             */
/*   Updated: 2025/02/19 12:03:23 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

char *read_file_to_string(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd < 0)
        error_exit("Error: Could not open .cub file");

    char buffer[BUFFER_SIZE + 1];
    char *content = NULL;
    char *temp;
    int bytes_read;

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[bytes_read] = '\0';
        temp = ft_strjoin(content, buffer);  // Append new data
        free(content);
        content = temp;
    }
    close(fd);

    if (!content)
        error_exit("Error: File is empty or could not be read");

    return content;
}

// Parses the .cub file into the game struct
void parse_cub_file(char *filename, t_game *game)
{
    char *file_content = read_file_to_string(filename);
    char **lines = ft_split(file_content, '\n'); // Split into lines
    free(file_content); // Free the full file content after splitting

    if (!lines)
        error_exit("Error: Failed to split file content");

    if (!game->map || !game->map[0])
    error_exit("Error: Map is not initialized correctly");

    for (int i = 0; lines[i]; i++)
    {
        if (is_texture_line(lines[i]))
            parse_texture(lines[i], game);
        else if (is_color_line(lines[i]))
            parse_color(lines[i], game);
        else if (is_map_line(lines[i]))
            parse_map(lines[i], game);
        else if (!is_empty_line(lines[i]))
            error_exit("Error: Invalid line in .cub file");

        free(lines[i]); // Free each line after processing
    }
    free(lines); // Free the array of lines

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
    
    fsplit(split);
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
    
    fsplit(rgb);
    fsplit(split);
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

char **append_to_map(char **map, char *line)
{
    int i = 0;

    if (!game->map || !game->map[0])
        error_exit("Error: Map is not initialized correctly");
    while (map && map[i])
        i++;

    char **new_map = malloc(sizeof(char *) * (i + 2)); // Extra space for new line + NULL
    if (!new_map)
        error_exit("Error: Memory allocation failed");

    for (int j = 0; j < i; j++)
        new_map[j] = map[j]; // Copy old map

    new_map[i] = ft_strdup(line); // Add new line
    new_map[i + 1] = NULL; // Null-terminate the array

    free(map); // Free old map
    return new_map;
}

int is_map_closed(char **map)
{
    int i, j;

    if (!map)
        return (0);

    for (i = 0; map[i]; i++)
        ;
    // Check first and last row for any gaps
    for (j = 0; map[0][j]; j++)
        if (map[0][j] != '1' && map[0][j] != ' ')
            return (0);
    for (j = 0; map[i - 1][j]; j++)
        if (map[i - 1][j] != '1' && map[i - 1][j] != ' ')
            return (0);

    // Check first and last column, and ensure walls enclose open spaces
    for (i = 0; map[i]; i++)
    {
        if (map[i][0] != '1' && map[i][0] != ' ')
            return (0);
        for (j = 0; map[i][j]; j++)
        {
            if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S' ||
                map[i][j] == 'E' || map[i][j] == 'W')
            {
                // Ensure surrounding tiles are not spaces (indicating gaps)
                if (i == 0 || !map[i + 1] || j == 0 || !map[i][j + 1] ||
                    map[i - 1][j] == ' ' || map[i + 1][j] == ' ' ||
                    map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
                    return (0);
            }
        }
        if (map[i][j - 1] != '1' && map[i][j - 1] != ' ')
            return (0);
    }
    return (1);
}
