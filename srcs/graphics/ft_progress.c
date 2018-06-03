/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_progress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 01:12:33 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/06/03 18:02:04 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

void		ft_progress(t_mlx *mlx, int width, int p1, int p2)
{(void)p2;
	int i;
	int j;
	static int lp[2] = {0, 0};
	int percent;
	int *img_addr;

	i = 0;
	img_addr = (int *)ft_get_addrs(mlx->progress, width);
	percent = (width * p1) / (mlx->map->dim[0] * mlx->map->dim[1]);
//	ft_printf("width: %d\npercent: %d\np1: %d\n", width, percent, lp[0]);
	while (i < 100 && p1 && percent < width)
	{
		j = i * width + lp[0];
		while ((j % width) < (lp[0] + percent))
		{
			img_addr[j++] = 0x14eefe;
		}
		i++;
	}
	lp[0] += p1 ? percent : 0;
	i = 0;
	percent = (width * p2) / ( mlx->map->dim[0] * mlx->map->dim[1]);
	while (i < 100 && p2)
	{
		j = (width - 1) + (i * width) - lp[1];
		while ((j % width) >= (width - percent - lp[1] - 1))
		{
			img_addr[j--] = 0xff69b4;
		}
		i++;
	}
	lp[1] += p2 ? percent : 0;
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->progress, MARGEN_X, RESOLUTION_Y - MARGEN_Y - 100);
}
