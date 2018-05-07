/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 15:03:24 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/07 16:41:30 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_place_image(t_mlx *mlx, int img_dim[2])
{
	int dist_x;
	int dist_y;

	dist_x = 0;
	dist_y = 0;
	while (img_dim[0] + 1 + dist_x < RESOLUTION_X - MARGEN_X * 2 - dist_x)
		dist_x++;
	while (img_dim[1] + 1 + dist_y < RESOLUTION_Y - MARGEN_Y * 2 - dist_y)
		dist_y++;
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, MARGEN_X + dist_x,
							MARGEN_Y + dist_y);
	mlx->params->img_pos[0] = dist_x;
	mlx->params->img_pos[1] = dist_y;
}
