/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_centered_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 03:32:33 by nfaust            #+#    #+#             */
/*   Updated: 2023/03/01 06:07:39 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

typedef struct s_coords {
	size_t		y;
	size_t		x;
}				t_coords;

static char	**alloc_centered_map(t_data *data)
{
	char	**centered_map;
	size_t	line_count;
	size_t	i;

	line_count = data->mlx->win_height / 100;
	centered_map = malloc((line_count + 1) * sizeof(char *));
	if (!centered_map)
		return (NULL);
	i = 0;
	while (i < line_count)
	{	
		centered_map[i] = malloc(((data->mlx->win_widht / 100) + 1));
		if (!centered_map[i])
			return (ft_free_twodimarr(centered_map), NULL);
		centered_map[i++][data->mlx->win_widht / 100] = 0;
	}
	centered_map[i] = NULL;
	return (centered_map);
}

static t_coords	*get_map_max_coords(char **map)
{
	t_coords	*coords;

	coords = malloc(sizeof(t_coords));
	coords->y = 0;
	while (map[coords->y])
		coords->y++;
	coords->x = 0;
	while (map[0][coords->x])
		coords->x++;
	coords->y--;
	coords->x--;
	return (coords);
}

static t_coords	*init_coords(t_data *data, t_coords *coords)
{
	t_coords	*max_map_coords;

	max_map_coords = get_map_max_coords(data->map);
	coords->y = 0;
	if (data->player_y > 5 && data->player_y < (max_map_coords->y - 5))
		coords->y += data->player_y - 5;
	else if (data->player_y > 5 && data->player_y >= (max_map_coords->y - 5))
		coords->y += data->player_y - 5 - (data->player_y - (max_map_coords->y - 5));
	coords->x = 0;
	if (data->player_x > 9 && data->player_x < (max_map_coords->x - 9))
		coords->x += data->player_x - 9;
	else if (data->player_x > 9 && data->player_x >= (max_map_coords->x - 9))
		coords->x += data->player_x - 9 - (data->player_x - (max_map_coords->x - 9));
	return (coords);
}

char	**get_centered_map(t_data *data)
{
	t_coords	*start_coords;
	char		**centered_map;
	size_t		i;
	size_t		j;
	size_t		curr_x;

	start_coords = malloc(sizeof(t_coords));
	if (!start_coords)
		return (NULL);
	start_coords = init_coords(data, start_coords);
	centered_map = alloc_centered_map(data);
	if (!centered_map)
		return (free(start_coords), NULL);
	i = 0;
	while (centered_map[i])
	{
		j = 0;
		curr_x = start_coords->x;
		while (centered_map[i][j])
		{
			// if (coords->min_y > coords->max_y)
			// 	coords->min_y = coords->max_y;
			printf("%li, %li, %li, %li, %li\n", i, j, start_coords->y, curr_x, start_coords->x);
			centered_map[i][j++] = data->map[start_coords->y][curr_x++];
		}
		start_coords->y++;
		i++;
	}
	i = 0;
	while (centered_map[i])
		printf("%s\n", centered_map[i++]);
	return (centered_map);
}
