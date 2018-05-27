/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 01:16:18 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/27 03:24:03 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char		*update_image(int *img, int punt[2], int *color, int player)
{
	if (player == 'O')
	{
		*img = 0;
		*color = 0xFF0000;
		return (ft_itoa(punt[0]++));
	}
	else
	{
		*img = 1;
		*color = 0x00FF00;
		return (ft_itoa(punt[1]++));
	}
}

void			ft_update_info(t_mlx *mlx, char player)
{
	char		*tmp;
	int			color;
	int			img;
	static int	puntuation[] = {0, 0};

	tmp = update_image(&img, puntuation, &color, player);
	mlx_destroy_image(mlx->ptr, mlx->info[img]);
	mlx->info[img] = mlx_new_image(mlx->ptr, MARGEN_X, 20);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->info[img],
			img ? RESOLUTION_X - MARGEN_X : 0, RESOLUTION_Y - MARGEN_Y - 28);
	mlx_string_put(mlx->ptr, mlx->win, (img ? RESOLUTION_X - MARGEN_X : 0)
			+ 50, RESOLUTION_Y - MARGEN_Y - 30, color, tmp);
	free(tmp);
}
