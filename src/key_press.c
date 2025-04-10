/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:58:35 by ysoyturk          #+#    #+#             */
/*   Updated: 2025/04/10 16:55:32 by ysoyturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	counter(int keycode, t_game *node)
{
	if (keycode == 119 || keycode == 97 || keycode == 115 || keycode == 100)
	{
		node->moves ++;
		ft_printf("Moves: %d\n", node->moves);
	}
}

void	key_press_control(t_game *node, int keycode)
{
	if (keycode == 65307)
		close_mlx(keycode, node);
	if (node->map[node->new_y][node->new_x] == 'E'
		&& node->coin == node->collectible)
	{
		counter(keycode, node);
		ft_printf("YOU WON!\n");
		map_clean_mlx(node);
		exit(0);
	}
	else if (node->map[node->new_y][node->new_x] == 'E')
		node->player_on_exit = 1;
	if (node->map[node->new_y][node->new_x] == 'C')
		node->coin++;
	counter(keycode, node);
}

void	key_put_img(char old_tile, t_game *node, int old_x, int old_y)
{
	node->map[old_y][old_x] = old_tile;
	if (old_tile == 'E')
		mlx_put_image_to_window(node->mlx, node->win,
			node->img_exit, old_x * 64, old_y * 64);
	else
		mlx_put_image_to_window(node->mlx, node->win,
			node->img_back, old_x * 64, old_y * 64);
}

int	key_press(int keycode, t_game *node)
{
	int		old_x;
	int		old_y;
	char	old_tile;

	old_tile = '0';
	node->new_x = movement_check_x(keycode, node);
	node->new_y = movement_check_y(keycode, node);
	old_x = node->player_x;
	old_y = node->player_y;
	if (node->map[node->new_y][node->new_x] == '1')
		return (0);
	if (node->player_on_exit == 1)
	{
		old_tile = 'E';
		node->player_on_exit = 0;
	}
	key_press_control(node, keycode);
	node->map[node->new_y][node->new_x] = 'P';
	key_put_img(old_tile, node, old_x, old_y);
	mlx_put_image_to_window(node->mlx, node->win,
		node->img_play, node->new_x * 64, node->new_y * 64);
	node->player_x = node->new_x;
	node->player_y = node->new_y;
	return (0);
}
