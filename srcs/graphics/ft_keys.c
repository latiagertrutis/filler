/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 19:01:10 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/06/03 20:03:18 by mrodrigu         ###   ########.fr       */
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

static void		hide_pause(t_mlx *mlx)
{
	void	*img;
	int		*addrs_info;
	int		*addrs_wall;
	int		i;
	int		j;

	img = mlx_new_image(mlx->ptr, 204, 37);
	addrs_info = (int *)ft_get_addrs(img, 204);
	addrs_wall = (int *)ft_get_addrs(mlx->wallpaper, RESOLUTION_X);
	i = 0;
	j = RESOLUTION_X * (MARGEN_Y + 100) + RESOLUTION_X / 2 - 30;
	while (i < 7548)
	{
		addrs_info[i++] = addrs_wall[j];
		if (!(i % (204)) && i)
			j += RESOLUTION_X - 204 + 1;
		else
			j++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, img,
			RESOLUTION_X / 2 - 30, MARGEN_Y + 100);
	mlx_destroy_image(mlx->ptr, img);
	return ;
}

int				ft_keys(int code, void *mlx)
{
	t_mlx	*mmlx;
	char	key[1];
	int		flag;

	if (code == ESC)
	{
		destroy_all(mlx);
		exit(0);
	}
	else if (code == SPACE)
	{
		mmlx = (t_mlx *)mlx;
		/* mlx_string_put(mmlx->ptr, mmlx->win, RESOLUTION_X / 2 - 30, */
		/* 		MARGEN_Y + 100, 0, "PAUSE"); */
		mlx_put_image_to_window(mmlx->ptr, mmlx->win, mmlx->img_pause, RESOLUTION_X / 2 - 30, MARGEN_Y + 100);
		if (mmlx->pause)
		{
			mmlx->pause = 0;
			hide_pause(mlx);
		}
		else
			mmlx->pause = 1;
	}
	return (0);
}
