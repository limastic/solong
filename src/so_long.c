/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:19:42 by nfaust            #+#    #+#             */
/*   Updated: 2023/03/01 04:38:44 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"
#define ESC_KEY 65307
#define W_KEY 119
#define S_KEY 115
#define A_KEY 97
#define D_KEY 100
#define UP_KEY 65362
#define DOWN_KEY 65364
#define LEFT_KEY 65361
#define RIGHT_KEY 65363

int	close_and_free(t_mlx *mlx)
{
	if (mlx->should_stop)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		mlx_loop_end(mlx->mlx);
		free(mlx->mlx);
		exit(0);
	}
	return (0);
}

void	*get_path(char c)
{
	char	*relative_path;

	if (c == '1')
		relative_path = ft_strdup("./assets/sprites/objects/objects.xpm");
	else if (c == '0')
		relative_path = ft_strdup("./assets/sprites/tilesets/grass.xpm");
	else if (c == 'E')
		relative_path = ft_strdup("./assets/sprites/objects/door.xpm");
	else if (c == 'P')
		relative_path = ft_strdup("./assets/sprites/characters/player.xpm");
	else
		relative_path = ft_strdup("assets/sprites/objects/collectable.xpm");
	return (relative_path);
}

static void	render_tile(t_mlx *mlx, char c, int i, int j)
{
	char	*relative_path;
	void	*img;
	int		width;
	int		height;

	relative_path = get_path(c);
	if (!relative_path)
		return ;
	img = mlx_xpm_file_to_image(mlx->mlx, relative_path, &width, &height);
	if (!img)
	{
		mlx->should_stop = 1;
		ft_printf("Error\nfailed to load image : '%s'\n", relative_path);
		if (relative_path)
			free(relative_path);
		close_and_free(mlx);
	}
	free(relative_path);
	mlx_put_image_to_window(mlx->mlx, mlx->win, img, j * 100, i * 100);
	// printf("rendered img in %i, %i\n", j * 100, i * 100);
	mlx_destroy_image(mlx->mlx, img);
}

static void	render_big_map(t_data *data)
{
	int		i;
	int		j;
	char	**centered_map;

	centered_map = get_centered_map(data);
	if (!centered_map)
		return ;
	i = 0;
	while (centered_map[i])
	{
		j = 0;
		while (centered_map[i][j])
		{
			render_tile(data->mlx, centered_map[i][j], i, j);
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

	if (data->mlx->win_height < 1100 && data->mlx->win_widht < 1900)
	{
		printf("%i, %i\n", data->mlx->win_widht, data->mlx->win_height);
		i = 0;
		while (data->map[i])
		{
			j = 0;
			while (data->map[i][j])
			{
				render_tile(data->mlx, data->map[i][j], i, j);
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
		data->mlx->should_stop = 1;
	else if (keycode == UP_KEY || keycode == W_KEY)
		moove_up(data);
	else if (keycode == DOWN_KEY || keycode == S_KEY)
		moove_down(data);
	else if (keycode == LEFT_KEY || keycode == A_KEY)
		moove_left(data);
	else if (keycode == RIGHT_KEY || keycode == D_KEY)
		moove_right(data);
	if (save_moove_count != data->moove_count)
		render_map(data);
	return (0);
}

int	close_on_cross(t_mlx *mlx)
{
	mlx->should_stop = 1;
	return (0);
}

int	so_long(char **map)
{
	t_mlx	mlx;
	t_data	data;

	mlx.should_stop = 0;
	mlx.win_height = get_win_height(map);
	mlx.win_widht = get_win_width(map);
	mlx.mlx = mlx_init();
	if (!(mlx.mlx))
		return (1);
	mlx.win = mlx_new_window(mlx.mlx, mlx.win_widht, mlx.win_height, "./so_long");
	if (!(mlx.win))
		return (1);
	data.map = map;
	data.mlx = &mlx;
	data.moove_count = 0;
	data.player_x = get_player_x(map);
	data.player_y = get_player_y(map);
	data.collectable_count = 0;
	data.collectable_total = count_collectable(map);
	render_map(&data);
	mlx_key_hook(mlx.win, &check_keys, &data);
	mlx_hook(mlx.win, 17, 0, &close_on_cross, &mlx);
	mlx_loop_hook(mlx.mlx, &close_and_free, &mlx);
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
	ft_free_twodimarr(map);
	return (0);
}
