/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:00:05 by ysoyturk          #+#    #+#             */
/*   Updated: 2025/04/10 16:22:35 by ysoyturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	find_map_x(t_game *node)
{
	int	x;

	x = 0;
	while (node->map[0][x])
		x++;
	return (x);
}

int	find_map_y(t_game *node)
{
	int	y;

	y = 0;
	while (node->map[y])
		y++;
	return (y);
}

void	fill_map(t_game *node, char **av)
{
	map_copy(node, av);
	is_rectangle(node);
	node->map_x = find_map_x(node);
	node->map_y = find_map_y(node);
	wall_check_y(node);
	collectible_check(node);
	player_check(node);
	exit_check(node);
	foreing_check(node);
	find_player_position(node);
	find_exit_position(node);
	flood_fill(node, av);
	find_exit_position(node);
	unreachable_exit(node);
}
