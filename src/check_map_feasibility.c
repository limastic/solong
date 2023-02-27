/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_feasibility.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:15:58 by nfaust            #+#    #+#             */
/*   Updated: 2023/02/27 20:18:32 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

typedef struct s_char_count
{
	size_t	j;
	size_t	i;
	size_t	player_count;
	size_t	exit_count;
	size_t	collectable_count;
}	t_char_count;

static int	check_chars_number(char **map)
{
	t_char_count	char_count;

	char_count.player_count = 0;
	char_count.exit_count = 0;
	char_count.collectable_count = 0;
	char_count.i = 0;
	while (map[char_count.i])
	{
		char_count.j = 0;
		while (map[char_count.i][char_count.j])
		{
			if (map[char_count.i][char_count.j] == 'P')
				char_count.player_count++;
			else if (map[char_count.i][char_count.j] == 'E')
				char_count.exit_count++;
			else if (map[char_count.i][char_count.j] == 'C')
				char_count.collectable_count++;
			char_count.j++;
		}
		char_count.i++;
	}
	return (print_char_number_error(char_count.player_count,
			char_count.exit_count, char_count.collectable_count));
}

int	check_reachability(char **map)
{
	char	**reachable_map;
	size_t	i;
	size_t	j;

	reachable_map = get_reachable_map(map);
	if (!reachable_map)
		return (1);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j++])
			if ((map[i][j - 1] == 'E' || map[i][j - 1] == 'C') &&
					reachable_map[i][j - 1] == '0')
				return (ft_free_twodimarr(reachable_map),
					ft_printf("Error\nimpossible map\n"), 1);
		i++;
	}
	return (ft_free_twodimarr(reachable_map), 0);
}

int	check_map_feasibility(char **map)
{
	if (check_chars_number(map))
		return (1);
	if (check_reachability(map))
		return (1);
	return (0);
}
