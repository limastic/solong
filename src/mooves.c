/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mooves.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 01:15:09 by nfaust            #+#    #+#             */
/*   Updated: 2023/03/03 13:00:40 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	moove_left(t_data *data)
{
	char	left_tile_value;

	left_tile_value = data->map[data->player_y][data->player_x - 1];
	if (data->map[data->player_y][data->player_x] == 'e')
		return ;
	if (left_tile_value == '1')
		return ;
	if (left_tile_value == '0' || left_tile_value == 'C' || (left_tile_value
			== 'E' && data->collectable_count == data->collectable_total))
	{
		if (left_tile_value == 'C')
			data->collectable_count += 1;
		if (left_tile_value != 'E')
			data->map[data->player_y][data->player_x - 1] = 'P';
		else
			data->map[data->player_y][data->player_x - 1] = 'e';
		data->map[data->player_y][data->player_x] = '0';
		data->moove_count += 1;
		ft_printf("%i\n", data->moove_count);
		data->player_x--;
		if (left_tile_value == 'E')
			game_over(data);
	}
}

void	moove_right(t_data *data)
{
	char	right_tile_value;

	right_tile_value = data->map[data->player_y][data->player_x + 1];
	if (data->map[data->player_y][data->player_x] == 'e')
		return ;
	if (right_tile_value == '1')
		return ;
	if (right_tile_value == '0' || right_tile_value == 'C' || (right_tile_value
			== 'E' && data->collectable_count == data->collectable_total))
	{
		if (right_tile_value == 'C')
			data->collectable_count += 1;
		if (right_tile_value != 'E')
			data->map[data->player_y][data->player_x + 1] = 'P';
		else
			data->map[data->player_y][data->player_x + 1] = 'e';
		data->map[data->player_y][data->player_x] = '0';
		data->moove_count += 1;
		ft_printf("%i\n", data->moove_count);
		data->player_x++;
		if (right_tile_value == 'E')
			game_over(data);
	}
}

void	moove_up(t_data *data)
{
	char	top_tile_value;

	top_tile_value = data->map[data->player_y - 1][data->player_x];
	if (data->map[data->player_y][data->player_x] == 'e')
		return ;
	if (top_tile_value == '1')
		return ;
	if (top_tile_value == '0' || top_tile_value == 'C' || (top_tile_value
			== 'E' && data->collectable_count == data->collectable_total))
	{
		if (top_tile_value == 'C')
			data->collectable_count += 1;
		if (top_tile_value != 'E')
			data->map[data->player_y - 1][data->player_x] = 'P';
		else
			data->map[data->player_y - 1][data->player_x] = 'e';
		data->map[data->player_y][data->player_x] = '0';
		data->moove_count += 1;
		ft_printf("%i\n", data->moove_count);
		data->player_y--;
		if (top_tile_value == 'E')
			game_over(data);
	}
}

void	moove_down(t_data *data)
{
	char	bott_tile_value;

	bott_tile_value = data->map[data->player_y + 1][data->player_x];
	if (data->map[data->player_y][data->player_x] == 'e')
		return ;
	if (bott_tile_value == '1')
		return ;
	if (bott_tile_value == '0' || bott_tile_value == 'C' || (bott_tile_value
			== 'E' && data->collectable_count == data->collectable_total))
	{
		if (bott_tile_value == 'C')
			data->collectable_count += 1;
		if (bott_tile_value != 'E')
			data->map[data->player_y + 1][data->player_x] = 'P';
		else
			data->map[data->player_y + 1][data->player_x] = 'e';
		data->map[data->player_y][data->player_x] = '0';
		data->moove_count += 1;
		ft_printf("%i\n", data->moove_count);
		data->player_y++;
		if (bott_tile_value == 'E')
			game_over(data);
	}
}
