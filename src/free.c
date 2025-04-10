/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:00:11 by ysoyturk          #+#    #+#             */
/*   Updated: 2025/04/09 20:41:43 by ysoyturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_memory(char **lst)
{
	int	i;

	i = 0;
	while (lst[i])
	{
		free(lst[i]);
		i++;
	}
	free(lst);
}

void	free_linked(t_game *node)
{
	ft_memset(node, 0, sizeof(t_game));
	free(node);
}

void	free_map(t_game *node)
{
	int	i;

	i = 0;
	while (node->map[i])
	{
		free(node->map[i]);
		i++;
	}
	free(node->map);
}

void	free_all(t_game *node)
{
	free_map(node);
	free_linked(node);
}

void	map_clean_mlx(t_game *node)
{
	if (node->img_wall)
		mlx_destroy_image(node->mlx, node->img_wall);
	if (node->img_back)
		mlx_destroy_image(node->mlx, node->img_back);
	if (node->img_play)
		mlx_destroy_image(node->mlx, node->img_play);
	if (node->img_exit)
		mlx_destroy_image(node->mlx, node->img_exit);
	if (node->img_coin)
		mlx_destroy_image(node->mlx, node->img_coin);
	if (node->win)
		mlx_destroy_window(node->mlx, node->win);
	if (node->mlx)
	{
		mlx_destroy_display(node->mlx);
		free(node->mlx);
	}
	free_map(node);
	free(node);
}
