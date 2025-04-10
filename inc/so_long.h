/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 20:54:20 by ysoyturk          #+#    #+#             */
/*   Updated: 2025/04/10 16:39:48 by ysoyturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_game
{
	int		map_x;
	int		map_y;
	int		player_on_exit;
	char	**map;
	void	*mlx;
	void	*win;
	void	*img_back;
	void	*img_coin;
	void	*img_exit;
	void	*img_play;
	void	*img_wall;
	int		img_width;
	int		img_height;
	int		player;
	int		player_x;
	int		player_y;
	int		collectible;
	int		coin;
	int		exit;
	int		exit_x;
	int		exit_y;
	int		moves;
	int		new_x;
	int		new_y;
}	t_game;

void	error_control(char *message);
void	free_map(t_game *game);
void	free_memory(char **lst);
void	free_linked(t_game *node);
void	free_all(t_game *node);
void	map_name(char **av);
void	is_rectangle(t_game *node);
void	is_equal(char **map, char *lst);
int		control_lst(char *lst, char **map);
void	map_copy(t_game *node, char **av);
int		lst_size(char **av);
int		map_size(char **map, t_game *node);
char	*make_lst(char **av, int k);
char	**make_map(char **av);
int		find_map_x(t_game *node);
int		find_map_y(t_game *node);
void	fill_map(t_game *node, char **av);
void	wall_check_y(t_game *node);
void	wall_check_x(t_game *node);
void	player_check(t_game *node);
void	exit_check(t_game *node);
void	collectible_check(t_game *node);
void	foreing_check(t_game *node);
void	find_player_position(t_game *node);
void	flood_fill(t_game *node, char **av);
void	flood_fill_map(char **map, int *map_size, int pos_x, int pos_y);
void	flood_fill_reader(char **map, t_game *node);
void	find_exit_position(t_game *node);
void	unreachable_exit(t_game *node);
void	real_map(t_game *node);
int		close_mlx(int keycode, t_game *node);
int		key_press(int keycode, t_game *node);
void	map_clean_mlx(t_game *node);
int		movement_check_x(int keycode, t_game *node);
int		movement_check_y(int keycode, t_game *node);
void	check_screen_size(t_game *node);

#endif