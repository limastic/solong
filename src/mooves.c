/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mooves.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 01:15:09 by nfaust            #+#    #+#             */
/*   Updated: 2023/02/28 02:14:18 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	moove_left(t_data *data)
{
	char	left_tile_value;

	printf("%li, %li\n", data->player_y, data->player_x);
	left_tile_value = data->map[data->player_y][data->player_x - 1];
	if (left_tile_value == '1')
		return ;
	if (left_tile_value == '0' || left_tile_value == 'C')
	{
		if (left_tile_value == 'C')
			data->collectable_count += 1;
		data->map[data->player_y][data->player_x - 1] = 'P';
		data->map[data->player_y][data->player_x] = '0';
		data->moove_count += 1;
		data->player_x--;
	}
	else if (left_tile_value == 'E')
		if (data->collectable_count == data->collectable_total)
			game_over(data);
}

void	moove_right(t_data *data)
{
	char	right_tile_value;

	printf("ici, %li, %li\n", data->player_y, data->player_x);
	right_tile_value = data->map[data->player_y][data->player_x + 1];
	if (right_tile_value == '1')
		return ;
	if (right_tile_value == '0' || right_tile_value == 'C')
	{
		if (right_tile_value == 'C')
			data->collectable_count += 1;
		data->map[data->player_y][data->player_x + 1] = 'P';
		data->map[data->player_y][data->player_x] = '0';
		data->moove_count += 1;
		data->player_x++;
	}
	else if (right_tile_value == 'E')
		if (data->collectable_count == data->collectable_total)
			game_over(data);
}

void	moove_up(t_data *data)
{
	char	top_tile_value;

	top_tile_value = data->map[data->player_y - 1][data->player_x];
	if (top_tile_value == '1')
		return ;
	if (top_tile_value == '0' || top_tile_value == 'C')
	{
		if (top_tile_value == 'C')
			data->collectable_count += 1;
		data->map[data->player_y - 1][data->player_x] = 'P';
		data->map[data->player_y][data->player_x] = '0';
		data->moove_count += 1;
		data->player_y--;
	}
	else if (top_tile_value == 'E')
		if (data->collectable_count == data->collectable_total)
			game_over(data);
}

void	moove_down(t_data *data)
{
	char	bottom_tile_value;

	bottom_tile_value = data->map[data->player_y + 1][data->player_x];
	if (bottom_tile_value == '1')
		return ;
	if (bottom_tile_value == '0' || bottom_tile_value == 'C')
	{
		if (bottom_tile_value == 'C')
			data->collectable_count += 1;
		data->map[data->player_y + 1][data->player_x] = 'P';
		data->map[data->player_y][data->player_x] = '0';
		data->moove_count += 1;
		data->player_y++;
	}
	else if (bottom_tile_value == 'E')
		if (data->collectable_count == data->collectable_total)
			game_over(data);
}
