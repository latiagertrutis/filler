/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_graphic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 22:41:08 by jagarcia          #+#    #+#             */
/*   Updated: 2018/05/03 11:58:42 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_read_map(char **line,  int dim[2], int row)
{
	int	read_cuant;
	int	a;
	
	if (row < 1000)
		read_cuant = dim[1] + 3 + 1 + 1;
	else
		read_cuant = dim[1] + ft_ndigits(row) + 1 + 1;
	*line = ft_strnew(read_cuant);
	if ((a = read(0, *line, read_cuant)) < 0)
		ft_error(NULL);
	(*line)[read_cuant - 1] = 0;
	return (a);
}

static int		keys(int code, void *mlx)
{
	if (code == ESC)
		exit(1);
	return (0);
}

static int		loop(void *mlx)
{
	int piece;

	ft_search_piece((t_mlx *)mlx);
	ft_place_piece((t_mlx *)mlx);
	
	return (0);
}

int				main(void)
{
	t_mlx *mlx;
	
	mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx));
	mlx->ptr = mlx_init();
	ft_initialice(&(mlx->params));
	if (!(mlx->win = mlx_new_window(mlx->ptr,mlx->params->win_size[0], mlx->params->win_size[1], "FILLER"))
		ft_error(NULL);
	if (!(mlx->img = mlx_new_image(mlx->ptr, dim[0] + MARGEN_X, dim[1] + MARGEN_Y)))
		ft_error(NULL);
	ft_print_map(mlx);
	mlx_key_hook(mlx->win, keys, mlx);
	mlx_loop_hook(mlx->ptr, loop, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}

int		main(void)
{
	char	*line;
	int		dim[2];
	int		row;

	/*
	** saltar numeracion de columnas
	*/
	if (dim[0] < 1000)
		ft_seek(0, dim[1] + ft_ndigits(dim[0]) + (dim[0] < 100 ? 3 : 2));
	else
		ft_seek(0, dim[1] + 5);
	
	
	/*
	** Imprimir mapa
	*/
	row = 0;
	
	while (read_map_row(&line, dim, row) && row < dim[0])
	{
		ft_putstr(line + ft_ndigits(row) + (row < 100 ? 4 - ft_ndigits(row) : 1));
		ft_putchar('\n');
		row += 1;
		ft_strdel(&line);
	}
	return (0);
}
