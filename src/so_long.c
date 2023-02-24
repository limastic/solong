/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:19:42 by nfaust            #+#    #+#             */
/*   Updated: 2023/02/23 17:39:43 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"
#define ESC_KEY 65307

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_mlx {
	void	*mlx;
	void	*win;
	int		*should_stop;
}				t_mlx;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	close_on_esc(int keycode, t_mlx *mlx)
{
	printf("esc ? %i\n", keycode);
	if (keycode == ESC_KEY)
	{
		printf("Touche 'esc' pressée\n");
		*(mlx->should_stop) = 1;
	}
	return (0);
}

int	close_on_cross(t_mlx *mlx)
{
	*(mlx->should_stop) = 1;
	return (0);
}

int	close_and_free(t_mlx *mlx)
{
	if (*(mlx->should_stop))
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		mlx_loop_end(mlx->mlx);
		free(mlx->mlx);
		exit(0);
	}
	return (0);
}

void	*create_background(t_mlx *mlx, char *relative_path)
{
	void	*img;
	int		width;
	int		height;

	width = 1000;
	width = 800;
	img = mlx_xpm_file_to_image(mlx->mlx, relative_path, &width, &height);
	if (!img)
	{
		*(mlx->should_stop) = 1;
		printf("so_long: failed to read img in '%s'\n", relative_path);
		close_and_free(mlx);
	}
	return (img);
}

int	so_long(void)
{
	t_mlx	mlx;
	// void	*img;
	void	*img1;

	*(mlx.should_stop) = 0;
	mlx.mlx = mlx_init();
	if (!(mlx.mlx))
		return (1);
	mlx.win = mlx_new_window(mlx.mlx, 1920, 1080, "So long");
	if (!(mlx.win))
		return (1);
	mlx_key_hook(mlx.win, &close_on_esc, &mlx);
	mlx_hook(mlx.win, 17, 0, &close_on_cross, &mlx);
	img1 = create_background(&mlx, "./assets/sprites/tilesets/grass.xpm");
	mlx_put_image_to_window(mlx.mlx, mlx.win, img1, 0, 0);
	// img = create_background(&mlx, "./assets/sprites/tilesets/fences.xpm");
	// mlx_put_image_to_window(mlx.mlx, mlx.win, img, 0, 0);
	mlx_loop_hook(mlx.mlx, &close_and_free, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	if (check_error(argc, argv))
		return (1);
	return (0);
}
