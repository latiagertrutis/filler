/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fight.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 21:02:08 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/06/04 05:30:49 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/filler.h"

void		ft_progress(t_mlx *mlx, int width, int p1, int p2)
{
	int i;
	int j;
	static int lp[2] = {0, 0};
	int percent;
	int *addr;

	i = 0;
	addr = (int *)ft_get_addrs(mlx->info->progress, width);
	if (p1)
	{
		percent = (width * (lp[0] + p1)) / (lp[0] + lp[1] + p1);
		while (i < 100)
		{
			j = i * width;
			while (j < percent + i * width)
				addr[j++] = 0x14eefe;
			i++;
		}
		lp[0]++;
	}
	else
	{
		i = 0;
		percent = (width * (lp[1] + p2)) / (lp[0] + lp[1] + p2);
		while (i < 100)
		{
			j = (width - 1) + (i * width);
			while (j > (width - percent + i * width))
				addr[j--] = 0xff69b4;
			i++;
		}
		lp[1]++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->info->progress,
			MARGEN_X + mlx->map->map_pos[0], RESOLUTION_Y - MARGEN_Y - 100);

}
