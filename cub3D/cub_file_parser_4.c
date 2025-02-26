/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_file_parser_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:25:50 by brsantsc          #+#    #+#             */
/*   Updated: 2025/02/26 11:40:07 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	check_top_bottom_walls(char **map)
{
	int	j;

	j = 0;
	while (map[0][j])
	{
		if (map[0][j] != '1' && map[0][j] != ' ')
			return (0);
		j++;
	}
	j = 0;
	while (map[j])
		j++;
	j = 0;
	while (map[j - 1][j])
	{
		if (map[j - 1][j] != '1' && map[j - 1][j] != ' ')
			return (0);
		j++;
	}
	return (1);
}

int	check_side_walls(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' && map[i][0] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	is_surrounded_by_walls(char **map, int i, int j)
{
	if (i == 0 || !map[i + 1] || j == 0 || !map[i][j + 1] ||
		map[i - 1][j] == ' ' || map[i + 1][j] == ' ' ||
		map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
		return (0);
	return (1);
}

int	check_map_validity(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S' ||
				map[i][j] == 'E' || map[i][j] == 'W')
			{
				if (!is_surrounded_by_walls(map, i, j))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_map_closed(char **map)
{
	if (!map)
		return (0);
	if (!check_top_bottom_walls(map) || !check_side_walls(map))
		return (0);
	if (!check_map_validity(map))
		return (0);
	return (1);
}
