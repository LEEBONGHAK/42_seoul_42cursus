/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bolee <bolee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:37:48 by bolee             #+#    #+#             */
/*   Updated: 2022/07/04 15:37:49 by bolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_hook(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		exit(0);
	}
	return (0);
}

static int	close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_mlx	mlx;
	t_3d	**cdn_3;
	t_2d	**cdn_2;
	t_scr	scr;

	if (argc != 2)
		err_exit("\033[0;31m[ERROR] Please check input\033[0m\n");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		perr_exit("\033[0;31m[ERROR] Please check file path\033[0m\n");
	cdn_3 = get_cdn_3(fd);
	if (close(fd) == -1)
		perr_exit("\033[0;31m[ERROR] close() error\033[0m\n");
	cdn_2 = take_cdn_2(cdn_3, argv[1]);
	scr = init_screen(cdn_2);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, scr.width, scr.height, argv[1]);
	draw_win(cdn_2, &mlx, scr);
	mlx_hook(mlx.win, 2, 0, key_hook, &mlx);
	mlx_hook(mlx.win, 17, 0, close_window, &mlx);
	mlx_loop(mlx.mlx);
	free_double_arr((void **) cdn_3);
	free_double_arr((void **) cdn_2);
	return (0);
}
