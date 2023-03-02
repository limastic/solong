/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 01:42:11 by nfaust            #+#    #+#             */
/*   Updated: 2023/03/01 23:51:37 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	game_over(t_data *data)
{
	printf("GAME OVER\n");
	data->mlx->should_stop = 1;
	close_and_free(data->mlx);
}
