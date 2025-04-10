/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unreachable_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:58:21 by ysoyturk          #+#    #+#             */
/*   Updated: 2025/04/10 14:47:40 by ysoyturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	find_exit_position(t_game *node)
{
	int	i;
	int	j;

	i = 0;
	while (node->map[i])
	{
		j = 0;
		while (node->map[i][j])
		{
			if (node->map[i][j] == 'E')
			{
				node->exit_x = j;
				node->exit_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	unreachable_exit(t_game *node)
{
	int	x;
	int	y;

	x = node->exit_x;
	y = node->exit_y;
	if (node->map[y][x + 1] == '1' && node->map[y][x - 1] == '1'
		&& node->map[y - 1][x] == '1' && node->map[y + 1][x] == '1')
	{
		free_all(node);
		error_control("Error\nUnreachacle Exit");
	}
}
