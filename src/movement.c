/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 20:53:59 by ysoyturk          #+#    #+#             */
/*   Updated: 2025/04/10 16:52:10 by ysoyturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	close_mlx(int keycode, t_game *node)
{
	if (keycode == 65307 && node != NULL)
	{
		ft_printf("You Left The Game!\n");
		map_clean_mlx(node);
		exit (0);
	}
	return (0);
}

void	check_screen_size(t_game *node)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mlx_get_screen_size(node->mlx, &i, &j);
	if ((node->map_x * 64 >= i) || (node->map_y * 64 >= j))
	{
		map_clean_mlx(node);
		ft_putendl_fd("Error\nMap size to big", 2);
		exit(1);
	}
}

int	movement_check_y(int keycode, t_game *node)
{
	int	new_y;

	new_y = node->player_y;
	if (keycode == 119)
		new_y = node->player_y - 1;
	else if (keycode == 115)
		new_y = node->player_y + 1;
	return (new_y);
}

int	movement_check_x(int keycode, t_game *node)
{
	int	new_x;

	new_x = node->player_x;
	if (keycode == 97)
		new_x = node->player_x - 1;
	else if (keycode == 100)
		new_x = node->player_x + 1;
	return (new_x);
}
