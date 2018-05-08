/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_graphic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 22:41:08 by jagarcia          #+#    #+#             */
/*   Updated: 2018/05/07 23:40:10 by mrodrigu         ###   ########.fr       */
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
	int		piece_pos[2];
	char	player;

	if (ft_search_piece((t_mlx *)mlx, piece_pos, &player))
	{
		ft_printf("jugador %c\n", player);
		ft_place_piece((t_mlx *)mlx, piece_pos, player);
	}
	return (0);
}

	void			set_bricks(t_mlx *mlx)
{
	int	*addrs;
	int i;
	
	mlx->bricks = (void **)malloc(sizeof(void *) * 2);
	(mlx->bricks)[0] = mlx_new_image(mlx->ptr, (int)mlx->params->square[1] - 1, (int)mlx->params->square[0] - 1);
	(mlx->bricks)[1] = mlx_new_image(mlx->ptr, (int)mlx->params->square[1] - 1, (int)mlx->params->square[0] - 1);
	addrs = (int *)ft_get_addrs((mlx->bricks)[0], (int)mlx->params->square[1] - 1);
	i = 0;
	while (i < (int)(mlx->params->square[1] - 1) * (int)(mlx->params->square[0] - 1))
		addrs[i++] = 0xFF0000;
	addrs = (int *)ft_get_addrs((mlx->bricks)[1], (int)mlx->params->square[1] - 1);
	i = 0;
while (i < (int)(mlx->params->square[1] - 1) * (int)(mlx->params->square[0] - 1))
		addrs[i++] = 0x00FF00;
}

void	marco(t_mlx *mlx)
{
	int *addrs;
	void *img;
	int i;
	int techo;
	int start;
	
	i = 0;
	techo = RESOLUTION_X - MARGEN_X * 2 + 2;
	img = mlx_new_image(mlx->ptr, RESOLUTION_X, RESOLUTION_Y);
	addrs = (int *)ft_get_addrs(img, RESOLUTION_X);
	start = RESOLUTION_X * (MARGEN_Y-1) + MARGEN_X - 1;
	while (i < techo)
		addrs[start + i++] = 0x0000FF;
	i = 0;
	techo = RESOLUTION_Y - MARGEN_Y * 2 + 2;
	while (i < techo)
		addrs[start + (i++ * RESOLUTION_X)] = 0x0000FF;
	i = 0;
	start = start + RESOLUTION_X - MARGEN_X * 2 + 1;
	while (i < techo)
		addrs[start + (i++ * RESOLUTION_X)] = 0x0000FF;
	start = (RESOLUTION_X * (MARGEN_Y-1) + MARGEN_X - 1) + RESOLUTION_X * (RESOLUTION_Y - MARGEN_Y * 2 + 1);
	i = 0;
	techo = RESOLUTION_X - MARGEN_X * 2 + 2;
	while (i < techo)
		addrs[start + i++] = 0x0000FF;
	mlx_put_image_to_window(mlx->ptr, mlx->win, img, 0, 0);
	return ;
}

int				main(void)
{
	t_mlx *mlx;
	t_params *par;

	// dim[0] son las filas square 0 es el lado vertical
	// dim[1] son las columnas scuare 1 es el lado horizontal 
	mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx));
	mlx->ptr = mlx_init();
	ft_initialice(&(mlx->params));
	if (!(mlx->win = mlx_new_window(mlx->ptr, RESOLUTION_X, RESOLUTION_Y, "FILLER")))
		ft_error(NULL);
	par = mlx->params;
	if (!(mlx->img = mlx_new_image(mlx->ptr, par->dim[1] * par->square[1] + 1, par->dim[0] * par->square[0] + 1)))
		ft_error(NULL);
	marco(mlx);
	set_bricks(mlx);
	ft_print_map(mlx);
	mlx_key_hook(mlx->win, keys, mlx);
	mlx_loop_hook(mlx->ptr, loop, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}

