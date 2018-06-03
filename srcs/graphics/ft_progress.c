/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fight.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 21:02:08 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/06/03 21:59:57 by mrodrigu         ###   ########.fr       */
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

static int	choose_color(int i, int p1)
{
	if (i < 10)
		return (p1 ? 0x0273ff : 0x900272);
	else if (i < 20)
		return (p1 ? 0x068bff : 0xaa0585);
	else if (i < 30)
		return (p1 ? 0x0aa3ff : 0xc00999);
	else if (i < 70)
		return (p1 ? 0x0fbcff : 0xda0ead);
	else if (i < 80)
		return (p1 ? 0x0aa3ff : 0xc00999);
	else if (i < 90)
		return (p1 ? 0x068bff : 0xaa0585);
	else
		return (p1 ? 0x0273ff : 0x900272);
}

void		ft_progress(t_mlx *mlx, int width, int p1, int p2)
{
	int i;
	int j;
	static int lp[2] = {0, 0};
	int percent;
	int *img_addr;

	i = 0;
	img_addr = (int *)ft_get_addrs(mlx->progress, width);
	if (p1)
	{
		percent = (width * (lp[0] + p1)) / (lp[0] + lp[1] + p1);
		while (i < 100)
		{
			j = i * width;
			while (j < percent + i * width)
				img_addr[j++] = choose_color(i, p1);
			i++;
		}
		lp[0]++;
	}
	else
	{
		i = 0;
		percent = width - (width * (lp[0] + p1)) / (lp[0] + lp[1] + p1);
		while (i < 100)
		{
			j = (width - 1) + (i * width);
			while (j > (width - percent + i * width))
				img_addr[j--] = choose_color(i, p1);
			i++;
		}
		lp[1]++;
	}
	center_image(mlx, width);
}
