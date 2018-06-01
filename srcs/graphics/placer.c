/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 18:38:54 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/06/01 05:34:24 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_place_brick(t_mlx *mlx, int row, int col, char player)
{
	int		pos_x;
	int		pos_y;
	void	*brick;

	pos_x = MARGEN_X + mlx->map->img_pos[0] + mlx->map->square[1] * col;
	pos_y = MARGEN_Y + mlx->map->img_pos[1] + mlx->map->square[0] * row;
	if (player == 'O')
		brick = (mlx->bricks)[0];
	else if (player == 'X')
		brick = (mlx->bricks)[1];
	else if (!player)
		brick = (mlx->bricks)[2];
	else
		ft_error("Ese jugador no existe primo\n");
	mlx_put_image_to_window(mlx->ptr, mlx->win, brick, pos_x, pos_y);
}

void	ft_place_piece(t_mlx *mlx, int pieza, char player)
{
	int			i;
	int			j;
	int			value;

	i = 0;
	j = 0;
	if (player && pieza > 0)
		ft_update_info(mlx, player);
	else if (pieza < 0)
		pieza = -pieza;
	while (i < (mlx->piece[pieza]->dim[0] * mlx->piece[pieza]->dim[1]))
	{
		if (mlx->piece[pieza]->shape[i / 8] & (0x80 >> (i % 8)))
		{
			ft_place_brick(mlx, i / mlx->piece[pieza]->dim[1] +
				mlx->piece[pieza]->pos[0], (i % mlx->piece[pieza]->dim[1])
				+ mlx->piece[pieza]->pos[1], player);
		}
		i++;
	}
}
