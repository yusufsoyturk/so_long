/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_in_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:59:34 by ysoyturk          #+#    #+#             */
/*   Updated: 2025/04/09 19:03:50 by ysoyturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	wall_check_y(t_game *node)
{
	int	i;

	i = 0;
	while (node->map[0][i])
	{
		if (node->map[0][i] != '1')
		{
			free_all(node);
			error_control("Error\nMissing Wall");
		}
		i++;
	}
	i = 0;
	while (node->map[node->map_y - 1][i])
	{
		if (node->map[node->map_y - 1][i] != '1')
		{
			free_all(node);
			error_control("Error\nMissing Wall");
		}
		i++;
	}
	wall_check_x(node);
}

void	wall_check_x(t_game *node)
{
	int	i;
	int	j;

	i = 0;
	j = node->map_x;
	while (node->map[i])
	{
		if (node->map[i][0] != '1' || node->map[i][j - 1] != '1')
		{
			free_all(node);
			error_control("Error\nMissing Wall");
		}
		i++;
	}
}

void	player_check(t_game *node)
{
	int	i;
	int	j;

	i = 0;
	node->player = 0;
	while (node->map[i])
	{
		j = 0;
		while (node->map[i][j])
		{
			if (node->map[i][j] == 'P')
				node->player++;
			j++;
		}
		i++;
	}
	if (node->player != 1)
	{
		free_all(node);
		error_control("Error\nInvalid Player");
	}
}

void	exit_check(t_game *node)
{
	int	i;
	int	j;

	i = 0;
	node->exit = 0;
	while (node->map[i])
	{
		j = 0;
		while (node->map[i][j])
		{
			if (node->map[i][j] == 'E')
				node->exit++;
			j++;
		}
		i++;
	}
	if (node->exit != 1)
	{
		free_all(node);
		error_control("Error\nInvalid Exit");
	}
}

void	collectible_check(t_game *node)
{
	int	i;
	int	j;

	i = 0;
	node->collectible = 0;
	while (node->map[i])
	{
		j = 0;
		while (node->map[i][j])
		{
			if (node->map[i][j] == 'C')
				node->collectible++;
			j++;
		}
		i++;
	}
	if (node->collectible < 1)
	{
		free_all(node);
		error_control("Error\nInvalid Collectible");
	}
}
