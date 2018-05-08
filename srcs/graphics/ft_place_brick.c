/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_brick.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 23:10:32 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/08 20:15:40 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_place_brick(t_mlx *mlx, int row, int col, char player)
{
	int		pos_x;
	int		pos_y;
	void	*brick;
	
	pos_x = MARGEN_X + mlx->params->img_pos[0] + 1 + mlx->params->square[1] * col;
	pos_y = MARGEN_Y + mlx->params->img_pos[1] + 1 + mlx->params->square[0] * row;
	if (player == 'O')
		brick = (mlx->bricks)[0];
	else if (player == 'X')
		brick = (mlx->bricks)[1];
	else
		ft_error("Ese jugador no existe primo\n");
		mlx_put_image_to_window(mlx->ptr, mlx->win, brick, pos_x, pos_y);
}