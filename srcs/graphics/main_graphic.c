/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_graphic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 22:41:08 by jagarcia          #+#    #+#             */
/*   Updated: 2018/05/14 21:03:41 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		keys(int code, void *mlx)
{
	if (code == ESC)
		exit(1);
	return (0);
}

static int		size_array(t_piece *pieces)
{
	int a;

	a = (pieces->piece_dim[0] * pieces->piece_dim[1]) / 8 +
	        ((pieces->piece_dim[0] * pieces->piece_dim[1]) % 8 ? 1 : 0);
//	ft_printf("a vale %i\n", a);
	return (a);
}

static void copy_piece(t_mlx *mlx)
{
	mlx->pieces[1]->piece_dim[0] = mlx->pieces[0]->piece_dim[0];
	mlx->pieces[1]->piece_dim[1] = mlx->pieces[0]->piece_dim[1];
	mlx->pieces[1]->piece_pos[0] = mlx->pieces[0]->piece_pos[0];
	mlx->pieces[1]->piece_pos[1] = mlx->pieces[0]->piece_pos[1];
	mlx->pieces[1]->player = mlx->pieces[0]->player;
	mlx->pieces[1]->piece = ft_strnew(size_array(mlx->pieces[1]));
	ft_memcpy(mlx->pieces[1]->piece, mlx->pieces[0]->piece, size_array(mlx->pieces[1]));
}

static int		loop(void *mlx)
{
	static int	end = 1;
	t_mlx		*mmlx;

	mmlx = (t_mlx *)mlx;
	if (end >= 0)
	{
		ft_search_piece(mmlx);
		if (!(end = ft_jump_piece(mlx)))
		{
			ft_place_piece(mmlx, 0, 0);
			if (mmlx->pieces[1]->piece)
				ft_place_piece(mmlx, 1, mmlx->pieces[1]->player);
			copy_piece(mmlx);
			ft_jump_map((mmlx)->params->dim);
			ft_jump_piece(mlx);
		}
		else if (end < 0)
		{
			ft_place_piece(mmlx, 1, mmlx->pieces[1]->player);
			mlx_string_put((mmlx)->ptr, (mmlx)->win, RESOLUTION_X / 2 - 30,
					RESOLUTION_Y / 2, 0x000000, "FINISH");
		}
		else
		{
			if (mmlx->pieces[1]->piece)
				ft_place_piece(mmlx, 1, mmlx->pieces[1]->player);
			ft_strdel(&((mmlx)->pieces[1]->piece));
		}
	}
	return (0);
}

	void			set_bricks(t_mlx *mlx)
{
	int	*addrs;
	int i;
	
	mlx->bricks = (void **)malloc(sizeof(void *) * 3);
	(mlx->bricks)[0] = mlx_new_image(mlx->ptr, (int)mlx->params->square[1] - 1, (int)mlx->params->square[0] - 1);
	(mlx->bricks)[1] = mlx_new_image(mlx->ptr, (int)mlx->params->square[1] - 1, (int)mlx->params->square[0] - 1);
	(mlx->bricks)[2] = mlx_new_image(mlx->ptr, (int)mlx->params->square[1] - 1, (int)mlx->params->square[0] - 1);
	addrs = (int *)ft_get_addrs((mlx->bricks)[0], (int)mlx->params->square[1] - 1);
	i = 0;
	while (i < (int)(mlx->params->square[1] - 1) * (int)(mlx->params->square[0] - 1))
		addrs[i++] = 0xFF0000;
	addrs = (int *)ft_get_addrs((mlx->bricks)[1], (int)mlx->params->square[1] - 1);
	i = 0;
	while (i < (int)(mlx->params->square[1] - 1) * (int)(mlx->params->square[0] - 1))
		addrs[i++] = 0x00FF00;
	addrs = (int *)ft_get_addrs((mlx->bricks)[2], (int)mlx->params->square[1] - 1);
	i = 0;
	while (i < (int)(mlx->params->square[1] - 1) * (int)(mlx->params->square[0] - 1))
		addrs[i++] = 0xFFFFFF;
}

int				main(void)
{
	t_mlx		*mlx;
	t_params	*par;
	int			mode;
	
	// dim[0] son las filas square 0 es el lado vertical
	// dim[1] son las columnas scuare 1 es el lado horizontal 
	mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx));
	mlx->ptr = mlx_init();
	ft_initialice(mlx);
//	ft_printf("un jugador es %s y el otro %s\n", mlx->params->players[0], mlx->params->players[1]);
	if (!(mlx->win = mlx_new_window(mlx->ptr, RESOLUTION_X, RESOLUTION_Y, "FILLER")))
		ft_error(NULL);
	par = mlx->params;
	if (!(mlx->img = mlx_new_image(mlx->ptr, par->dim[1] * par->square[1] + 1, par->dim[0] * par->square[0] + 1)))
		ft_error(NULL);
	set_bricks(mlx);
	ft_print_map(mlx);	
	ft_info(mlx);
	mlx_key_hook(mlx->win, keys, mlx);
	mlx_loop_hook(mlx->ptr, loop, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
