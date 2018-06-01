/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 19:01:10 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/06/01 19:02:18 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		destroy_all(t_mlx *mlx)
{
	mlx_destroy_image(mlx->ptr, mlx->img);
	mlx_destroy_image(mlx->ptr, mlx->bricks[0]);
	mlx_destroy_image(mlx->ptr, mlx->bricks[1]);
	free(mlx->bricks);
	mlx_destroy_image(mlx->ptr, mlx->info[0]);
	mlx_destroy_image(mlx->ptr, mlx->info[1]);
	free(mlx->info);
	free(mlx->map->players[0]);
	free(mlx->map->players[1]);
	free(mlx->map->players);
	free(mlx->piece[0]->shape);
	free(mlx->piece[1]->shape);
	free(mlx->piece[0]);
	free(mlx->piece[1]);
	free(mlx->piece);
	mlx_destroy_window(mlx->ptr, mlx->win);
}

int		ft_keys(int code, void *mlx)
{
	t_mlx	*mmlx;
	char	key[1];
	int		flag;
	
	if (code == ESC)
	{
		//	destroy_all(mlx);
		exit(0);
	}
	else if (code == SPACE)
	{
		mmlx = (t_mlx *)mlx;
		mlx_string_put(mmlx->ptr, mmlx->win, RESOLUTION_X / 2 - 30, MARGEN_Y + 100, 0, "PAUSE");
		if (mmlx->pause)
		{
			mmlx->pause = 0;
			
		}
		else
			mmlx->pause = 1;
	}
	return (0);
}
