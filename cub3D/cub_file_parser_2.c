/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_file_parser_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:44:34 by brsantsc          #+#    #+#             */
/*   Updated: 2025/02/26 01:07:43 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	validate_map(t_game *game)
{
	if (!is_map_closed(game->map))
		error_exit("Error: Map is not closed");
	if (!has_valid_start_position(game->map, &game->player))
		error_exit("Error: No valid player start position");
}

int	is_texture_line(char *line)
{
	return (ft_strncmp(line, "NO ", 3) == 0
		|| ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0
		|| ft_strncmp(line, "EA ", 3) == 0);
}

int	is_color_line(char *line)
{
	return (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0);
}

int	is_map_line(char *line)
{
	while (*line)
	{
		if (*line != ' ' && *line != '0' && *line != '1' && *line != 'N'
			&& *line != 'S' && *line != 'E' && *line != 'W')
			return (0);
		line++;
	}
	return (1);
}

int	is_empty_line(char *line)
{
	while (*line)
	{
		if (*line != ' ' && *line != '\n')
			return (0);
		line++;
	}
	return (1);
}
