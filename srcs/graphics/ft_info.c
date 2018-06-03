/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 02:45:07 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/06/03 21:37:30 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_info(t_mlx *mlx)
{
	mlx->progress = mlx_new_image(mlx->ptr, mlx->map->square[1] * mlx->map->dim[1], 100);
	mlx_string_put(mlx->ptr, mlx->win, 50, RESOLUTION_Y - MARGEN_Y - 50,
				0xFF0000, mlx->map->players[0]);
	mlx_string_put(mlx->ptr, mlx->win, 50, RESOLUTION_Y - MARGEN_Y - 30,
				0xFF0000, "0");
	mlx_string_put(mlx->ptr, mlx->win, RESOLUTION_X - MARGEN_X + 50,
				RESOLUTION_Y - MARGEN_Y - 50, 0x00FF00, mlx->map->players[1]);
	mlx_string_put(mlx->ptr, mlx->win, RESOLUTION_X - MARGEN_X + 50,
				RESOLUTION_Y - MARGEN_Y - 30, 0x00FF00, "0");
}
