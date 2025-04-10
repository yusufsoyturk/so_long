/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_char_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 21:10:44 by ysoyturk          #+#    #+#             */
/*   Updated: 2025/04/10 15:48:32 by ysoyturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	lst_size(char **av)
{
	int		i;
	int		j;
	int		fd;
	char	*line;

	fd = open(av[1], O_RDONLY);
	i = 0;
	j = 0;
	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		while (line[i])
		{
			i++;
			j++;
		}
		free(line);
		line = get_next_line(fd);
	}
	return (j);
}

char	*make_lst(char **av, int k)
{
	char	*lst;
	char	*lst2;
	int		i;
	int		fd;
	int		j;

	fd = open(av[1], O_RDONLY);
	i = lst_size(av);
	lst = malloc(sizeof(char) * i + 1);
	lst2 = get_next_line(fd);
	while (lst2)
	{
		j = 0;
		while (lst2[j])
			lst[k++] = lst2[j++];
		free(lst2);
		lst2 = get_next_line(fd);
	}
	lst[k] = '\0';
	return (lst);
}

int	control_lst(char *lst, char **map)
{
	int	i;
	int	a;

	a = 0;
	i = 0;
	while (lst[i])
	{
		if (lst[i + 1] && lst[i] == '\n' && lst[i + 1] == '\n'
			&& lst[i + 2] && lst[i + 2] != '\n')
		{
			free(lst);
			free_memory(map);
			error_control("Error\nMap is not rectangle");
		}
		if (lst[i + 1] && lst[i] == '\n' && lst[i + 1] != '\n')
			a++;
		i++;
	}
	return (a);
}

void	is_equal(char **map, char *lst)
{
	int	j;
	int	a;

	j = 0;
	a = control_lst(lst, map);
	while (map[j])
		j++;
	if (a > j)
	{
		free(lst);
		free_memory(map);
		error_control("Error\nMap is not rectangle");
	}
}

char	**make_map(char **av)
{
	char	**map;
	char	*lst;
	int		k;

	k = 0;
	lst = make_lst(av, k);
	map = ft_split(lst, '\n');
	is_equal(map, lst);
	free(lst);
	return (map);
}
