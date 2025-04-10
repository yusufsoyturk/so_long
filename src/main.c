/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 21:02:46 by ysoyturk          #+#    #+#             */
/*   Updated: 2025/04/10 22:12:45 by ysoyturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char **av)
{
	t_game	*node;

	if (ac == 2)
	{
		map_name(av);
		node = malloc(sizeof(t_game));
		ft_memset(node, 0, sizeof(t_game));
		fill_map(node, av);
		real_map(node);
		free_all(node);
	}
	else
		error_control("Error\nWrong Format");
}
