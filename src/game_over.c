/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 01:42:11 by nfaust            #+#    #+#             */
/*   Updated: 2023/03/03 14:35:08 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	game_over(t_data *data)
{
	ft_printf("LEVEL COMPLETE\nSCORE : %i\n", data->moove_count);
}
