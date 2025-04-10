/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:59:39 by ysoyturk          #+#    #+#             */
/*   Updated: 2025/04/10 16:40:17 by ysoyturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	map_size(char **map, t_game *node)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	j = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			k++;
			j++;
		}
		i++;
	}
	if (k == 0)
	{
		free_memory(map);
		free_linked(node);
		error_control("Error\nEmpty Folder");
	}
	return (k);
}

void	map_copy(t_game *node, char **av)
{
	int		i;
	char	**map;
	int		count;

	map = make_map(av);
	count = map_size(map, node);
	i = 0;
	node->map = malloc(sizeof(char *) * (count + 1));
	while (map[i])
	{
		node->map[i] = ft_strdup(map[i]);
		i++;
	}
	node->map[i] = NULL;
	free_memory(map);
}
