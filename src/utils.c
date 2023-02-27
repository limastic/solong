/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:56:04 by nfaust            #+#    #+#             */
/*   Updated: 2023/02/27 18:08:57 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	check_char(char c)
{
	if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P' && c != '\n')
		return (1);
	return (0);
}

int	print_char_number_error(size_t player_count,
		size_t exit_count, size_t collectable_count)
{
	if (player_count != 1)
		return (ft_printf("Error\nno player or more than 1 player in map\n", 1));
	if (exit_count != 1)
		return (ft_printf("Error\nno exit or more than 1 exit in map\n"), 1);
	if (!collectable_count)
		return (ft_printf("Error\nno collectables in map\n"), 1);
	return (0);
}
