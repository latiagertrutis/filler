/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 07:51:31 by jagarcia          #+#    #+#             */
/*   Updated: 2018/05/04 20:09:23 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		line(int *addrs, int point, int end, int vertical)
{
	int j;

	j = 0;
	while (j < end)
		addrs[point + (j++ * vertical)] = LINE_COLOR;
}

void			ft_print_map(t_mlx *mlx)
{
	int		*addrs;
	int		i;
	int		img_dim[2];
	int		point;

	/*
	**La imagen mide 1 pixel mas de lo logico es decir (columnas * lado cuadrado + 1) x (filas * lado cuadrado + 1)
	**para asi meter el campo de col*l_cuad x fil * l_cuad y que los ladrillos encagen
	**quizas seria recomendable que midiese 2 pixeles mas para asi centrar el campo en la imagen y esta en la pantalla
	**hay 2 valores que manejar el tamanyo real de la imagen que tiene una fila y una columna mas de pixeles
	**y el tamanyo del campo que es el logico columnas por lado y filas por lado (es decir 1 menos que el real)
	*/
	img_dim[0] = mlx->params->dim[1] * mlx->params->square[1] + 1;
	img_dim[1] = mlx->params->dim[0] * mlx->params->square[0] + 1;
	addrs = (int *)ft_get_addrs(mlx->img, RESOLUTION_X - MARGEN_X * 2);
	line(addrs, 0, img_dim[0], 1);
	line(addrs, 0, img_dim[1], img_dim[0]);
	line(addrs, img_dim[0] - 1, img_dim[1] - 1 , img_dim[0]);
	line(addrs, img_dim[0] * (img_dim[1] - 1), (img_dim[0] - 1), 1);
//	addrs[1366 * 700] = 0x0000FF;
	i = 0;
 	while (i < mlx->params->dim[0])
	{
		point = img_dim[0] * (i++ * (mlx->params->square[0]));
		line(addrs, point, img_dim[0] - 1, 1);
	}
	i = 0;
	while (i < mlx->params->dim[1])
	{
		point = i++ * (mlx->params->square[1]);
		line(addrs, point, img_dim[1] - 1, img_dim[0]);
		}
//	ft_place_starts(mlx, addrs);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, MARGEN_X, MARGEN_Y);
}
