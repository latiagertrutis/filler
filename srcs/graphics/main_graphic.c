/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_graphic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 22:41:08 by jagarcia          #+#    #+#             */
/*   Updated: 2018/05/28 02:59:14 by mrodrigu         ###   ########.fr       */
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

static int		keys(int code, void *mlx)
{
	if (code == ESC)
	{
		destroy_all(mlx);
		exit(1);
	}
	return (0);
}

static int		loop(void *mlx)
{
	static int	end = 1;

	if (end >= 0)
	{
		ft_set_piece_pos(mlx);
		if (!(end = ft_jump_piece(mlx)))
		{
			ft_place_piece(mlx, 0, 0);
			if (((t_mlx *)mlx)->piece[1]->shape)
				ft_place_piece(mlx, 1, ((t_mlx *)mlx)->piece[1]->player);
			ft_copy_piece(mlx);
			ft_jump_map(((t_mlx *)mlx)->map->dim);
			ft_jump_piece(mlx);
		}
		else if (end < 0)
		{
			ft_place_piece(mlx, -1, ((t_mlx *)mlx)->piece[1]->player);
			mlx_string_put(((t_mlx *)mlx)->ptr, ((t_mlx *)mlx)->win,
					RESOLUTION_X / 2 - 30, RESOLUTION_Y / 2, 0, "FINISH");
		}
		else
			ft_place_piece(mlx, 1, ((t_mlx *)mlx)->piece[1]->player);
	}
	return (0);
}

int				main(void)
{
	t_mlx		*mlx;
	t_map		*map;
	int			mode;

	mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx));
	mlx->ptr = mlx_init();
	ft_initialice(mlx);
	if (!(mlx->win = mlx_new_window(mlx->ptr, RESOLUTION_X,
			RESOLUTION_Y, "FILLER")))
		ft_error(NULL);
	map = mlx->map;
	if (!(mlx->img = mlx_new_image(mlx->ptr, map->dim[1] * map->square[1] + 1,
			map->dim[0] * map->square[0] + 1)))
		ft_error(NULL);
	ft_set_bricks(mlx);
	ft_print_map(mlx);
	ft_info(mlx);
	mlx_key_hook(mlx->win, keys, mlx);
	mlx_loop_hook(mlx->ptr, loop, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
