/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 19:22:00 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/14 22:00:14 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_info(t_mlx *mlx)
{
	mlx_string_put(mlx->ptr, mlx->win, 50, RESOLUTION_Y - MARGEN_Y - 50,
				0xFF0000, mlx->map->players[0]);
	mlx_string_put(mlx->ptr, mlx->win, RESOLUTION_X - MARGEN_X + 50 ,
				RESOLUTION_Y - MARGEN_Y - 50, 0x00FF00, mlx->map->players[1]);
}
