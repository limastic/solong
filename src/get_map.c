/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:28:24 by nfaust            #+#    #+#             */
/*   Updated: 2023/02/27 21:23:20 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static size_t	_count_lines(char *file_path)
{
	int		file_fd;
	char	buffer[2];
	size_t	line_count;
	int		nl_ended;

	file_fd = open(file_path, O_RDONLY);
	if (file_fd == -1)
		return (0);
	line_count = 0;
	while (read(file_fd, buffer, 1))
	{
		nl_ended = 0;
		if (buffer[0] == '\n')
		{
			line_count++;
			nl_ended = 1;
		}
	}
	if (!nl_ended)
		return (ft_printf("Error\nno newline at EOF\n"), close(file_fd), 0);
	if (!line_count)
		ft_printf("Error\nempty map\n");
	return (close(file_fd), line_count);
}

static int	_protect_allocation(int file_fd, size_t line_count, char **map)
{
	if (!line_count)
	{
		if (file_fd != -1)
			close(file_fd);
		if (map)
			free(map);
		return (1);
	}
	if (file_fd == -1)
	{
		if (map)
			free(map);
		return (1);
	}
	if (!map)
	{
		close(file_fd);
		return (1);
	}
	return (0);
}

static char	**_allocate_map(char *file_path)
{
	int		file_fd;
	char	buffer[2];
	char	**map;
	size_t	char_count;
	size_t	i;

	i = _count_lines(file_path);
	map = malloc((i + 1) * sizeof(char *));
	file_fd = open(file_path, O_RDONLY);
	if (_protect_allocation(file_fd, i, map))
		return (NULL);
	char_count = 0;
	i = 0;
	while (read(file_fd, buffer, 1))
	{
		char_count ++;
		if (buffer[0] == '\n')
		{
			map[i] = malloc(char_count);
			if (!map[i++])
				return (ft_free_twodimarr(map), NULL);
		}
	}
	map[i] = NULL;
	return (close(file_fd), map);
}

char	**get_map(char *file_path)
{
	int		file_fd;
	char	buffer[2];
	char	**map;
	size_t	i;
	size_t	j;

	map = _allocate_map(file_path);
	if (!map)
		return (NULL);
	i = 0;
	j = 0;
	file_fd = open(file_path, O_RDONLY);
	if (file_fd == -1)
		return (ft_free_twodimarr(map), NULL);
	while (read(file_fd, buffer, 1))
	{
		if (buffer[0] == '\n')
		{
			map[i++][j] = 0;
			j = 0;
		}
		else
			map[i][j++] = buffer[0];
	}
	return (close(file_fd), map);
}
