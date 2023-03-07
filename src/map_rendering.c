/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:58:06 by nfaust            #+#    #+#             */
/*   Updated: 2023/03/07 11:59:05 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

static void	*get_path(char c, t_data *data)
{
	char	*relative_path;

	if (c == '1')
		relative_path = ft_strdup("./assets/sprites/objects/wall.xpm");
	else if (c == '0')
		relative_path = ft_strdup("./assets/sprites/tilesets/grass.xpm");
	else if (c == 'E')
		relative_path = ft_strdup("./assets/sprites/objects/door.xpm");
	else if (c == 'P')
		relative_path = ft_strdup(data->player_url);
	else if (c == 'e')
		relative_path = ft_strdup("assets/sprites/objects/doorwin.xpm");
	else
		relative_path = ft_strdup("assets/sprites/objects/collectable.xpm");
	return (relative_path);
}

static void	render_tile(t_data *data, char c, int i, int j)
{
	char	*relative_path;
	void	*img;
	int		width;
	int		height;

	relative_path = get_path(c, data);
	if (!relative_path)
		close_and_free(data);
	img = mlx_xpm_file_to_image(data->mlx->mlx, relative_path, &width, &height);
	if (!img)
	{
		ft_printf("Error\nfailed to load image : '%s'\n", relative_path);
		if (relative_path)
			free(relative_path);
		close_and_free(data);
	}
	free(relative_path);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
		img, j * 100, i * 100);
	mlx_destroy_image(data->mlx->mlx, img);
}

static void	render_big_map(t_data *data)
{
	int		i;
	int		j;
	char	**centered_map;

	centered_map = get_centered_map(data);
	if (!centered_map)
		close_and_free(data);
	i = 0;
	while (centered_map[i])
	{
		j = 0;
		while (centered_map[i][j])
		{
			render_tile(data, centered_map[i][j], i, j);
			j++;
		}
		i++;
	}
	return (ft_free_twodimarr(centered_map));
}

int	render_map(t_data *data)
{
	int	i;
	int	j;

	if (!data->player_url)
		close_and_free(data);
	if (data->mlx->win_height < 1100 && data->mlx->win_widht < 1900)
	{
		i = 0;
		while (data->map[i])
		{
			j = 0;
			while (data->map[i][j])
			{
				render_tile(data, data->map[i][j], i, j);
				j++;
			}
			i++;
		}
	}
	else
		render_big_map(data);
	return (0);
}
