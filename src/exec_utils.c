/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:41:27 by nfaust            #+#    #+#             */
/*   Updated: 2023/02/28 03:31:19 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	get_win_height(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
		i++;
	if (i > ULONG_MAX / 100)
		i = 1100;
	else
		i *= 100;
	if (i > 1100)
		i = 1100;
	return ((int)i);
}

int	get_win_width(char **map)
{
	size_t	j;

	j = 0;
	while (map[0][j])
		j++;
	if (j > ULONG_MAX / 100)
		j = 1900;
	else
		j *= 100;
	if (j > 1900)
		j = 1900;
	return ((int)j);
}

size_t	get_player_x(char **map)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
			if (map[y][x++] == 'P')
				return (x - 1);
		y++;
	}
	return (0);
}

size_t	get_player_y(char **map)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
			if (map[y][x++] == 'P')
				return (y);
		y++;
	}
	return (0);
}

size_t	count_collectable(char **map)
{
	size_t	i;
	size_t	j;
	size_t	collectable_count;

	collectable_count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			if (map[i][j++] == 'C')
				collectable_count++;
		i++;
	}
	return (collectable_count);
}
