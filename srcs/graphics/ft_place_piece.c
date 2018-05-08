/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 20:21:00 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/08 23:37:57 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_place_piece(t_mlx *mlx, int piece_pos[2], char player)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < (mlx->params->piece_dim[0] * mlx->params->piece_dim[1]))
	{
		if (mlx->params->piece[i / 8] & (0x80 >> (i % 8)))
		{
			ft_place_brick(mlx, i / mlx->params->piece_dim[1] + piece_pos[0], (i % mlx->params->piece_dim[1])
				+ piece_pos[1], player);
		}
		i++;
		
	}
	
}
