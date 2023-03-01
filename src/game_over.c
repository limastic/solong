/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 01:42:11 by nfaust            #+#    #+#             */
/*   Updated: 2023/03/01 06:10:08 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	game_over(t_data *data)
{
	data->collectable_count = 0;
	printf("GAME OVER\n");
	sleep(10);
	return ;
}
