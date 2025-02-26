/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_file_parser_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:51:32 by brsantsc          #+#    #+#             */
/*   Updated: 2025/02/26 11:42:06 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	parse_map(char *line, t_game *game)
{
	game->map = append_to_map(game->map, line);
}

char	**append_to_map(char **map, char *line)
{
	int		i;
	int		j;
	char	**new_map;

	i = 0;
	while (map && map[i])
		i++;
	new_map = malloc(sizeof(char *) * (i + 2));
	if (!new_map)
		error_exit("Error: Memory allocation failed");
	j = 0;
	while (j < i)
	{
		new_map[j] = map[j];
		i++;
	}
	new_map[i] = ft_strdup(line);
	new_map[i + 1] = NULL;
	free(map);
	return (new_map);
}
