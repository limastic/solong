/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:29:34 by nfaust            #+#    #+#             */
/*   Updated: 2023/02/27 18:19:22 by nfaust           ###   ########.fr       */
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

int		check_error(int argc, char **argv);
int		check_char(char c);
char	**get_map(char *file_path);
int		check_map_feasibility(char **map);
int		print_char_number_error(size_t player_count,
			size_t exit_count, size_t collectable_count);
char	**get_reachable_map(char **map);

#endif