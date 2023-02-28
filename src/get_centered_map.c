/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_centered_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 03:32:33 by nfaust            #+#    #+#             */
/*   Updated: 2023/02/28 03:52:47 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

typedef struct s_coords {
	int		min_x;
	int		max_x;
	int		min_y;
	int		max_y;
}				t_coords;

static char	**alloc_centered_map(t_data *data)
{
	char	**centered_map;

	centered_map = malloc(((data->mlx->win_height / 100) + 1) * sizeof(char *));
}

static t_coords	*init_coords(t_data *data)
{
	t_coords	coords;

	coords.min_y = data->player_y - 5;
	if (coords.min_y < 0)
		coords.min_y = 0;
	coords.max_y = coords.min_y + 10;
	coords.min_x = data->player_x - 9;
	if (coords.min_x < 0)
		coords.min_x = 0;
	coords.max_x = coords.min_x + 18;
	return (&coords);
}

char	**get_centered_map(t_data *data)
{
	t_coords	*coords;
	char		**centered_map;

	coords = init_coords(data);
	centered_map = alloc_centered_map(data);
	while (coords.min_y <= coords.max_y)
		while (coords.min_x <= coords.max_x)
			
}
