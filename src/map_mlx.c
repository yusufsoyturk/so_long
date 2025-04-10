/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:58:29 by ysoyturk          #+#    #+#             */
/*   Updated: 2025/04/10 18:41:59 by ysoyturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	img_filler(t_game *node)
{
	node->img_back = mlx_xpm_file_to_image(node->mlx,
			"textures/back.xpm", &node->img_width, &node->img_height);
	node->img_coin = mlx_xpm_file_to_image(node->mlx,
			"textures/coin.xpm", &node->img_width, &node->img_height);
	node->img_exit = mlx_xpm_file_to_image(node->mlx,
			"textures/exit.xpm", &node->img_width, &node->img_height);
	node->img_play = mlx_xpm_file_to_image(node->mlx,
			"textures/player.xpm", &node->img_width, &node->img_height);
	node->img_wall = mlx_xpm_file_to_image(node->mlx,
			"textures/wall.xpm", &node->img_width, &node->img_height);
}

static void	real_map_filler_image(t_game *node, int i, int j)
{
	if (node->map[i][j] == '1')
		mlx_put_image_to_window(node->mlx,
			node->win, node->img_wall, j * 64, i * 64);
	else if (node->map[i][j] == '0')
		mlx_put_image_to_window(node->mlx,
			node->win, node->img_back, j * 64, i * 64);
	else if (node->map[i][j] == 'P')
		mlx_put_image_to_window(node->mlx,
			node->win, node->img_play, j * 64, i * 64);
	else if (node->map[i][j] == 'E')
		mlx_put_image_to_window(node->mlx,
			node->win, node->img_exit, j * 64, i * 64);
	else if (node->map[i][j] == 'C')
		mlx_put_image_to_window(node->mlx,
			node->win, node->img_coin, j * 64, i * 64);
}

static	void	real_map_filler(t_game *node)
{
	int	i;
	int	j;

	i = 0;
	img_filler(node);
	while (node->map[i])
	{
		j = 0;
		while (node->map[i][j])
		{
			real_map_filler_image(node, i, j);
			j++;
		}
		i++;
	}
}

int	close_mlx_x(t_game *node)
{
	if (node != NULL)
	{
		ft_printf("You Left The Game!\n");
		map_clean_mlx(node);
		exit (0);
	}
	return (0);
}

void	real_map(t_game *node)
{
	node->mlx = mlx_init();
	check_screen_size(node);
	node->win = mlx_new_window(node->mlx,
			node->map_x * 64, node->map_y * 64, "so_long");
	real_map_filler(node);
	mlx_hook(node->win, 2, (1L << 0), key_press, node);
	mlx_hook(node->win, 17, (1L << 0), close_mlx_x, node);
	mlx_loop(node->mlx);
}
