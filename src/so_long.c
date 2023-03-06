/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:19:42 by nfaust            #+#    #+#             */
/*   Updated: 2023/03/04 14:46:43 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	close_and_free(t_data *data)
{
	mlx_destroy_window(data->mlx->mlx, data->mlx->win);
	mlx_loop_end(data->mlx->mlx);
	mlx_destroy_display(data->mlx->mlx);
	free(data->mlx->mlx);
	ft_free_twodimarr(data->map);
	free(data->player_url);
	exit(0);
}

void	*get_path(char c, t_data *data)
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

static int	render_map(t_data *data)
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

int	check_keys(int keycode, t_data *data)
{
	size_t	save_moove_count;

	save_moove_count = data->moove_count;
	if (keycode == ESC_KEY)
		close_and_free(data);
	else if ((keycode == UP_KEY || keycode == W_KEY))
		moove_up(data);
	else if ((keycode == DOWN_KEY || keycode == S_KEY))
		moove_down(data);
	else if ((keycode == LEFT_KEY || keycode == A_KEY))
		moove_left(data);
	else if ((keycode == RIGHT_KEY || keycode == D_KEY))
		moove_right(data);
	else if (keycode == B_KEY)
		return (free(data->player_url), data->player_url = ft_strdup("assets\
/sprites/characters/bajeanno.xpm"), render_map(data));
	if (save_moove_count != data->moove_count)
		render_map(data);
	return (0);
}

static void	init_data(t_data *data, t_mlx *mlx, char **map)
{
	data->map = map;
	data->player_url = ft_strdup("./assets/sprites/characters/player.xpm");
	if (!data->player_url)
		return (ft_free_twodimarr(data->map), exit(0), (void) 0);
	data->mlx = mlx;
	data->moove_count = 0;
	data->player_x = get_player_x(map);
	data->player_y = get_player_y(map);
	data->collectable_count = 0;
	data->collectable_total = count_collectable(map);
}

int	so_long(char **map)
{
	t_mlx	mlx;
	t_data	data;

	mlx.win_height = get_win_height(map);
	mlx.win_widht = get_win_width(map);
	mlx.mlx = mlx_init();
	if (!(mlx.mlx))
		return (1);
	mlx.win = mlx_new_window(mlx.mlx, mlx.win_widht,
			mlx.win_height, "./so_long");
	if (!(mlx.win))
		return (mlx_destroy_display(mlx.mlx), free(mlx.mlx), 1);
	init_data(&data, &mlx, map);
	render_map(&data);
	mlx_key_hook(mlx.win, &check_keys, &data);
	mlx_hook(mlx.win, 17, 0, &close_and_free, &data);
	mlx_loop(mlx.mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**map;

	map = check_error(argc, argv);
	if (!map)
		return (1);
	so_long(map);
	return (0);
}
