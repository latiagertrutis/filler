/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_progress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 01:12:33 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/06/03 19:44:58 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

static void			center_image(t_mlx *mlx, int width)
{
	int dist_x;
	int dist_y;
	int	img_dim[2];

	img_dim[0] = width;

	dist_x = 0;
	dist_y = 0;
	while (img_dim[0] + 1 + dist_x < RESOLUTION_X - MARGEN_X * 2 - dist_x)
		dist_x++;
	mlx->map->img_pos[0] = dist_x;
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->progress, MARGEN_X + dist_x, RESOLUTION_Y - MARGEN_Y - 100);
}

void		ft_progress(t_mlx *mlx, int width, int p1, int p2)
{
	int i;
	int j;
	static int lp[2] = {0, 0};
	static double error[2] = {0.0, 0.0};
	double percent;
	int *img_addr;

	i = 0;
	img_addr = (int *)ft_get_addrs(mlx->progress, width);
	percent = (double)(width * p1) / (double)(mlx->map->dim[0] * mlx->map->dim[1]);
	if (percent + error[0] > (int)percent)
	{
		percent += error[0];
		error[0] = 0.0;
	}
	error[0] += percent - (int)percent;
	while (i < 100 && p1 && percent < width)
	{
		j = i * width + lp[0];
		while ((j % width) < ((int)lp[0] + (int)percent))
			img_addr[j++] = 0x14eefe;
		i++;
	}
	lp[0] += p1 ? percent : 0.0;
	i = 0;
	percent = (double)(width * p2) / (double)( mlx->map->dim[0] * mlx->map->dim[1]);
	if (percent + error[1] > (int)percent)
	{
		percent += error[1];
		error[1] = 0.0;
	}
	error[1] += percent - (int)percent;
	while (i < 100 && p2)
	{
		j = (width - 1) + (i * width) - lp[1];
		while ((j % width) >= (width - (int)percent - (int)lp[1] - 1))
			img_addr[j--] = 0xff69b4;
		i++;
	}
	lp[1] += p2 ? percent : 0.0;
	center_image(mlx, width);
}
