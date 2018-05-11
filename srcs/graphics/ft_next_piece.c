/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_piece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 22:20:28 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/11 16:30:18 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		jump_map(int dim[2])
{
	int map;
	int plateau;

	plateau = ft_ndigits(dim[0]) + ft_ndigits(dim[1]) + 11;
	plateau = 0;
	map = (dim[0] + 1) * (dim[1] + 5);
	if (dim[0] > 1000)
		map += dim[0] - 1000;
	
	ft_seek(STDIN_FILENO, map + plateau);
}

void	ft_next_piece(t_mlx *mlx)
{
	if (!ft_jump_piece(mlx))
	{
		jump_map(mlx->params->dim);
		ft_jump_piece(mlx);
	}
}
