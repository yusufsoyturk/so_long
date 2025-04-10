/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:23:43 by ysoyturk          #+#    #+#             */
/*   Updated: 2025/04/09 19:17:24 by ysoyturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	foreing_check(t_game *node)
{
	int	i;
	int	j;

	i = 0;
	while (node->map[i])
	{
		j = 0;
		while (node->map[i][j])
		{
			if (node->map[i][j] != '0' && node->map[i][j] != '1'
				&& node->map[i][j] != 'C' && node->map[i][j] != 'E'
				&& node->map[i][j] != 'P')
			{
				free_all(node);
				error_control("Error\nForeign Item");
			}
			j++;
		}
		i++;
	}
}

void	find_player_position(t_game *node)
{
	int	i;
	int	j;

	i = 0;
	while (node->map[i])
	{
		j = 0;
		while (node->map[i][j])
		{
			if (node->map[i][j] == 'P')
			{
				node->player_x = j;
				node->player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill_map(char **map, int *map_size, int pos_x, int pos_y)
{
	if (pos_x < 0 || pos_x >= map_size[0]
		|| pos_y < 0 || pos_y > map_size[1])
		return ;
	if (map[pos_y][pos_x] != '0' && map[pos_y][pos_x] != 'P'
		&& map[pos_y][pos_x] != 'C' && map[pos_y][pos_x] != 'E')
		return ;
	map[pos_y][pos_x] = '1';
	flood_fill_map(map, map_size, pos_x - 1, pos_y);
	flood_fill_map(map, map_size, pos_x + 1, pos_y);
	flood_fill_map(map, map_size, pos_x, pos_y - 1);
	flood_fill_map(map, map_size, pos_x, pos_y + 1);
}

void	flood_fill(t_game *node, char **av)
{
	char	**map;
	int		map_size[2];
	int		player_pos[2];

	map_size[0] = node->map_x;
	map_size[1] = node->map_y;
	player_pos[0] = node->player_x;
	player_pos[1] = node->player_y;
	map = make_map(av);
	flood_fill_map(map, map_size, player_pos[0], player_pos[1]);
	flood_fill_reader(map, node);
	free_memory(map);
}

void	flood_fill_reader(char **map, t_game *node)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
			{
				free_memory(map);
				free_all(node);
				error_control("Error\nUnreachable C");
			}
			j++;
		}
		i++;
	}
}
