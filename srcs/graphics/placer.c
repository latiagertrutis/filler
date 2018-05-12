/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 18:38:54 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/12 15:06:33 by mrodrigu         ###   ########.fr       */
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
	else if (!player)
	{
		ft_putchar('A');
		brick = (mlx->bricks)[2];
	}
	else
		ft_error("Ese jugador no existe primo\n");
		mlx_put_image_to_window(mlx->ptr, mlx->win, brick, pos_x, pos_y);
}

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

void	ft_place_piece(t_mlx *mlx, int piece_pos[2], char player)
{
	int			i;
	int			j;
	
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

