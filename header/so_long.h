/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:29:34 by nfaust            #+#    #+#             */
/*   Updated: 2023/03/01 03:36:01 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../mlx_linux/mlx.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_mlx {
	void	*mlx;
	void	*win;
	int		win_height;
	int		win_widht;
	int		should_stop;
}				t_mlx;

typedef struct s_data {
	t_mlx	*mlx;
	char	**map;
	size_t	moove_count;
	size_t	player_x;
	size_t	player_y;
	size_t	collectable_total;
	size_t	collectable_count;
}				t_data;

char	**check_error(int argc, char **argv);
int		check_char(char c);
char	**get_map(char *file_path);
int		check_map_feasibility(char **map);
int		print_char_number_error(size_t player_count,
			size_t exit_count, size_t collectable_count);
char	**get_reachable_map(char **map);
int		get_win_height(char **map);
int		get_win_width(char **map);
size_t	get_player_x(char **map);
size_t	get_player_y(char **map);
size_t	count_collectable(char **map);
void	moove_down(t_data *data);
void	moove_up(t_data *data);
void	moove_left(t_data *data);
void	moove_right(t_data *data);
char	**get_centered_map(t_data *data);
void	game_over(t_data *data);

#endif