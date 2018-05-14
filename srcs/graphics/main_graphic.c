/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_graphic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 22:41:08 by jagarcia          #+#    #+#             */
/*   Updated: 2018/05/14 21:57:34 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		keys(int code, void *mlx)
{
	if (code == ESC)
		exit(1);
	return (0);
}

static int		loop(void *mlx)
{
	static int	end = 1;
	t_mlx		*mmlx;

	mmlx = (t_mlx *)mlx;
	if (end >= 0)
	{
		ft_set_piece_pos(mmlx);
		if (!(end = ft_jump_piece(mlx)))
		{
			ft_place_piece(mmlx, 0, 0);
			if (mmlx->piece[1]->shape)
				ft_place_piece(mmlx, 1, mmlx->piece[1]->player);
			ft_copy_piece(mmlx);
			ft_jump_map((mmlx)->map->dim);
			ft_jump_piece(mlx);
		}
		else if (end < 0)
		{
			ft_place_piece(mmlx, 1, mmlx->piece[1]->player);
			mlx_string_put((mmlx)->ptr, (mmlx)->win, RESOLUTION_X / 2 - 30,
					RESOLUTION_Y / 2, 0x000000, "FINISH");
		}
		else
			ft_place_piece(mmlx, 1, mmlx->piece[1]->player);
	}
	return (0);
}

	void			set_bricks(t_mlx *mlx)
{
	int	*addrs;
	int i;
	
	mlx->bricks = (void **)malloc(sizeof(void *) * 3);
	(mlx->bricks)[0] = mlx_new_image(mlx->ptr, (int)mlx->map->square[1] - 1, (int)mlx->map->square[0] - 1);
	(mlx->bricks)[1] = mlx_new_image(mlx->ptr, (int)mlx->map->square[1] - 1, (int)mlx->map->square[0] - 1);
	(mlx->bricks)[2] = mlx_new_image(mlx->ptr, (int)mlx->map->square[1] - 1, (int)mlx->map->square[0] - 1);
	addrs = (int *)ft_get_addrs((mlx->bricks)[0], (int)mlx->map->square[1] - 1);
	i = 0;
	while (i < (int)(mlx->map->square[1] - 1) * (int)(mlx->map->square[0] - 1))
		addrs[i++] = 0xFF0000;
	addrs = (int *)ft_get_addrs((mlx->bricks)[1], (int)mlx->map->square[1] - 1);
	i = 0;
	while (i < (int)(mlx->map->square[1] - 1) * (int)(mlx->map->square[0] - 1))
		addrs[i++] = 0x00FF00;
	addrs = (int *)ft_get_addrs((mlx->bricks)[2], (int)mlx->map->square[1] - 1);
	i = 0;
	while (i < (int)(mlx->map->square[1] - 1) * (int)(mlx->map->square[0] - 1))
		addrs[i++] = 0xFFFFFF;
}

int				main(void)
{
	t_mlx		*mlx;
	t_map		*map;
	int			mode;
	
	mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx));
	mlx->ptr = mlx_init();
	ft_initialice(mlx);
	if (!(mlx->win = mlx_new_window(mlx->ptr, RESOLUTION_X, RESOLUTION_Y, "FILLER")))
		ft_error(NULL);
	map = mlx->map;
	if (!(mlx->img = mlx_new_image(mlx->ptr, map->dim[1] * map->square[1] + 1, map->dim[0] * map->square[0] + 1)))
		ft_error(NULL);
	set_bricks(mlx);
	ft_print_map(mlx);	
	ft_info(mlx);
	mlx_key_hook(mlx->win, keys, mlx);
	mlx_loop_hook(mlx->ptr, loop, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
