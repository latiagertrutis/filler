/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_piece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 21:11:39 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/14 22:01:00 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	size_piece(t_piece *piece)
{
	return (piece->dim[0] * piece->dim[1]) / 8 +
		((piece->dim[0] * piece->dim[1]) % 8 ? 1 : 0);
}

void		ft_copy_piece(t_mlx *mlx)
{
	mlx->piece[1]->dim[0] = mlx->piece[0]->dim[0];
	mlx->piece[1]->dim[1] = mlx->piece[0]->dim[1];
	mlx->piece[1]->pos[0] = mlx->piece[0]->pos[0];
	mlx->piece[1]->pos[1] = mlx->piece[0]->pos[1];
	mlx->piece[1]->player = mlx->piece[0]->player;
	ft_strdel(&(mlx->piece[1]->shape));
	mlx->piece[1]->shape = ft_strnew(size_piece(mlx->piece[1]));
	ft_memcpy(mlx->piece[1]->shape, mlx->piece[0]->shape,
	          size_piece(mlx->piece[1]));
}
