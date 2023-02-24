/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:28:24 by nfaust            #+#    #+#             */
/*   Updated: 2023/02/24 00:21:41 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static int	_check_path(char *file_path)
{
	size_t	path_len;
	size_t	i;
	int		file_fd;

	path_len = ft_strlen(file_path);
	if (path_len < 4)
		return (1);
	i = path_len - 4;
	if (ft_strncmp(file_path + i, ".ber", 5))
		return (1);
	file_fd = open(file_path, O_RDONLY);
	if (file_fd == -1)
		return (1);
	close(file_fd);
	file_fd = open(file_path, __O_DIRECTORY);
	if (file_fd != -1)
		return (close(file_fd), 1);
	return (0);
}

static int	_check_shape_and_content(char **map)
{
	size_t	i;
	size_t	j;
	size_t	line_len;

	line_len = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if (!map[i][0])
			return (ft_printf("Error\nempty newline(s) in map or map is empty\n")
				, 1);
		if (ft_strlen(map[i]) != line_len)
			return (ft_printf("Error\nmap is not a rectangle\n"), 1);
		j = 0;
		while (map[i][j])
			if (check_char(map[i][j++]))
				return (ft_printf("Error\ninvalids char(s) in map\n"), 1);
		i++;
	}
	if (line_len <= 2 || i <= 2)
		return (ft_printf("Error\nmap is not wide and/or high enough\n"));
	return (0);
}

static int	_check_wall_surroundment(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		if (i == 0 || !map[i + 1])
		{
			while (map[i][j])
				if (map[i][j++] != '1')
					return (ft_printf("Error\nmap is not surrounded by walls\n")
						, 1);
		}
		else
			while (map[i][j++])
				if (map[i][j - 1] != '1' && (!(j - 1) || !map[i][j]))
					return (ft_printf("Error\nmap is not surrounded by walls\n")
						, 1);
		i++;
	}
	return (0);
}

static int	_check_file_rules(char **map)
{
	if (_check_shape_and_content(map) || _check_wall_surroundment(map))
		return (1);
	return (0);
}

int	check_error(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
		return (ft_printf("Error\nwrong number of args\n"), 1);
	if (_check_path(argv[1]))
		return (ft_printf("Error\nInvalid map path, \
wrong access rights or is a directory: '%s'\n"
				, argv[1]), 1);
	map = get_map(argv[1]);
	if (!map)
		return (1);
	if (_check_file_rules(map))
		return (ft_free_twodimarr(map), 1);
	ft_free_twodimarr(map);
	return (0);
}
