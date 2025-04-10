/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_for_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 21:04:03 by ysoyturk          #+#    #+#             */
/*   Updated: 2025/04/10 16:48:09 by ysoyturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	error_control(char *message)
{
	ft_putendl_fd(message, 2);
	exit(1);
}

void	map_name(char **av)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error_control("Error\nMap not found");
	if (av[1][5] == '.')
		error_control("Error\nMap name incorrect");
	if (av[1][ft_strlen(av[1]) - 4] != '.' || av[1][ft_strlen(av[1]) - 3] != 'b'
		|| av[1][ft_strlen(av[1]) - 2] != 'e'
		|| av[1][ft_strlen(av[1]) - 1] != 'r')
		error_control("Error\nMap name incorrect");
}

void	is_rectangle(t_game *node)
{
	int	line;
	int	line2;
	int	i;

	i = 1;
	line = ft_strlen(node->map[0]);
	while (node->map[i])
	{
		line2 = ft_strlen(node->map[i]);
		if (line != line2)
		{
			free_all(node);
			error_control("Error\nMap is not rectangle.");
		}
		i++;
	}
}
