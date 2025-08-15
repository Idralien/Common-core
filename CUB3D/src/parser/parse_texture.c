/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:57:21 by quvan-de          #+#    #+#             */
/*   Updated: 2025/03/10 13:33:14 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	check_texture_extension(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	while (len > 0 && (path[len - 1] == '\n' || path[len - 1] == ' '))
		path[--len] = '\0';
	if (len < 4 || ft_strncmp(path + len - 4, ".xpm", 4) != 0)
		return (print_error("Error\nIncorrect file extension for texture"));
	return (1);
}

int	validate_texture(char *line, char **texture_path, t_game *game)
{
	if (*texture_path != NULL)
		return (print_error("Error\nTexture already assigned"));
	if (!get_path(line, texture_path))
		return (0);
	if (!check_texture_extension(*texture_path))
	{
		free(*texture_path);
		*texture_path = NULL;
		return (0);
	}
	game->map_flags.has_texture++;
	return (1);
}

int	parse_texture(char *line, t_game *game)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		return (validate_texture(line, &game->texture[0].path, game));
	else if (ft_strncmp(line, "SO", 2) == 0)
		return (validate_texture(line, &game->texture[1].path, game));
	else if (ft_strncmp(line, "WE", 2) == 0)
		return (validate_texture(line, &game->texture[2].path, game));
	else if (ft_strncmp(line, "EA", 2) == 0)
		return (validate_texture(line, &game->texture[3].path, game));
	else
		return (printf("Error\nInvalid or unrecognized texture entry: %s\n",
				line));
}

int	parse_textures_and_colors(char *line, t_game *game)
{
	if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
		|| ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0)
		return (parse_texture(line, game));
	if (ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0)
		return (parse_color(line, game));
	return (0);
}
