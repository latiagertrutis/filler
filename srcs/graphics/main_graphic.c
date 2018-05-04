/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_graphic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 22:41:08 by jagarcia          #+#    #+#             */
/*   Updated: 2018/05/04 20:11:31 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"



static int		keys(int code, void *mlx)
{
	if (code == ESC)
		exit(1);
	return (0);
}

/*static int		loop(void *mlx)
{
	int piece;

	ft_search_piece((t_mlx *)mlx);
	ft_place_piece((t_mlx *)mlx);
	
	return (0);
	}*/

	void			set_bricks(t_mlx *mlx)
{
	int	*addrs;
	int i;
	
	mlx->bricks = (void **)malloc(sizeof(void *) * 2);
	(mlx->bricks)[0] = mlx_new_image(mlx->ptr, mlx->params->square[1] - 1, mlx->params->square[0] - 1);
	(mlx->bricks)[1] = mlx_new_image(mlx->ptr, mlx->params->square[1] - 1, mlx->params->square[0] - 1);
	addrs = (int *)ft_get_addrs((mlx->bricks)[0], mlx->params->square[1]);
	i = 0;
	while (i < (mlx->params->square[1] - 1) * (mlx->params->square[0] - 1))
		addrs[i++] = 0xFF0000;
	addrs = (int *)ft_get_addrs((mlx->bricks)[1], mlx->params->square[1]);
	i = 0;
	while (i < (mlx->params->square[1] - 1) * (mlx->params->square[0] - 1))
		addrs[i++] = 0x00FF00;
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
	ft_printf("filas %i columnas %i\n", par->dim[0], par->dim[1]);
	ft_printf("square mide %i x %i\n", par->square[0], par->square[1]);
	set_bricks(mlx);
	ft_print_map(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, (mlx->bricks)[0],MARGEN_X + 1, MARGEN_Y + 1);
	mlx_put_image_to_window(mlx->ptr, mlx->win, (mlx->bricks)[0],MARGEN_X + 1 + mlx->params->square[1], MARGEN_Y + 1);
	mlx_put_image_to_window(mlx->ptr, mlx->win, (mlx->bricks)[0],MARGEN_X + 1 + mlx->params->square[1] * (mlx->params->dim[1] - 1), MARGEN_Y + 1);
	mlx_put_image_to_window(mlx->ptr, mlx->win, (mlx->bricks)[0],MARGEN_X + 1, MARGEN_Y + 1 + mlx->params->square[0]);
	mlx_put_image_to_window(mlx->ptr, mlx->win, (mlx->bricks)[1],MARGEN_X + 1, MARGEN_Y + 1 + mlx->params->square[0] * (mlx->params->dim[0] - 1));
	mlx_put_image_to_window(mlx->ptr, mlx->win, (mlx->bricks)[0],MARGEN_X + 1 + mlx->params->square[1], MARGEN_Y + 1 + mlx->params->square[0] * (mlx->params->dim[0] - 1));
	mlx_put_image_to_window(mlx->ptr, mlx->win, (mlx->bricks)[1],MARGEN_X + 1 + mlx->params->square[1] * 5, MARGEN_Y + 1 + mlx->params->square[0] * (5));
	mlx_put_image_to_window(mlx->ptr, mlx->win, (mlx->bricks)[1],MARGEN_X + 1 + mlx->params->square[1] * (mlx->params->dim[1] - 1), MARGEN_Y + 1 + mlx->params->square[0] * (mlx->params->dim[0] - 1));
//	mlx_put_image_to_window(mlx->ptr, mlx->win, (mlx->bricks)[1],MARGEN_X + mlx->params->square[1], MARGEN_Y + 1);
	mlx_key_hook(mlx->win, keys, mlx);
//	mlx_loop_hook(mlx->ptr, loop, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}

/*int		main(void)
{
	char	*line;
	int		dim[2];
	int		row;

	
	** saltar numeracion de columnas
	
	if (dim[0] < 1000)
		ft_seek(0, dim[1] + ft_ndigits(dim[0]) + (dim[0] < 100 ? 3 : 2));
	else
		ft_seek(0, dim[1] + 5);
	
	
	
	** Imprimir mapa
	
	row = 0;
	

	return (0);
}*/
