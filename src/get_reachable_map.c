/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_reachable_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:13:55 by nfaust            #+#    #+#             */
/*   Updated: 2023/03/07 15:37:59 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static char	**alloc_reachable_map(char **map)
{
	size_t	i;
	size_t	j;
	size_t	line_len;
	char	**reachable_map;

	i = 0;
	line_len = 0;
	while (map[i])
		if (!i++)
			while (map[0][line_len])
				line_len++;
	reachable_map = malloc((i + 1) * sizeof(char *));
	if (!reachable_map)
		return (NULL);
	j = 0;
	while (j < i)
	{
		reachable_map[j] = malloc(sizeof(char) * (line_len + 1));
		if (!reachable_map[j])
			return (ft_free_twodimarr(reachable_map), NULL);
		ft_memset(reachable_map[j], 1, line_len);
		reachable_map[j++][line_len] = 0;
	}
	reachable_map[i] = NULL;
	return (reachable_map);
}

static int	is_walkable(char c)
{
	if (c == '0' || c == 'C')
		return (1);
	return (0);
}

static void	fill_reachable_map(char **map,
		char **reachable_map, size_t x, size_t y)
{
	if (reachable_map[y][x] != '-')
		return ;
	if (map[y][x] != 'P' && map[y][x] != 'E' && !is_walkable(map[y][x]))
		return (reachable_map[y][x] = '0', (void) 0);
	else if (map[y][x] == 'E')
		return (reachable_map[y][x] = '2', (void) 0);
	else
		reachable_map[y][x] = '1';
	fill_reachable_map(map, reachable_map, x, y + 1);
	fill_reachable_map(map, reachable_map, x, y - 1);
	fill_reachable_map(map, reachable_map, x + 1, y);
	fill_reachable_map(map, reachable_map, x - 1, y);
	if (map[y][x] == 'P')
	{
		y = 0;
		while (reachable_map[y])
		{
			x = 0;
			while (reachable_map[y][x])
				if (reachable_map[y][x++] == '-')
					reachable_map[y][x - 1] = '0';
			y++;
		}
	}
}

static void	init_reachable_map(char **reachable_map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (reachable_map[i])
	{
		j = 0;
		while (reachable_map[i][j])
			reachable_map[i][j++] = '-';
		i++;
	}
}

char	**get_reachable_map(char **map)
{
	char	**reachable_map;
	size_t	x;
	size_t	y;
	int		player_found;

	reachable_map = alloc_reachable_map(map);
	if (!reachable_map)
		return (NULL);
	init_reachable_map(reachable_map);
	y = 0;
	player_found = 0;
	while (!player_found && map[y])
	{
		x = 0;
		while (!player_found && map[y][x++])
			if (map[y][x - 1] == 'P')
				player_found = 1;
		y++;
	}
	return (fill_reachable_map(map, reachable_map, --x, --y), reachable_map);
}
