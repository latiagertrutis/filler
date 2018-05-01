/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_graphic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 22:41:08 by jagarcia          #+#    #+#             */
/*   Updated: 2018/05/01 13:18:09 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		read_map_row(char **line, char **line2,  int dim[2], int row)
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
	if (!a)
		return (a);
	if (row + 1 < 1000)
		read_cuant = dim[1] + 3 + 1 + 1;
	else
		read_cuant = dim[1] + ft_ndigits(row + 1) + 1 + 1;
		*line2 = ft_strnew(read_cuant);
	if ((a = read(0, *line2, read_cuant)) < 0)
		ft_error(NULL);
	(*line2)[read_cuant - 1] = 0;

	return (a);
}

int		main(void)
{
	char	*line;
	char	*line2;
	int		dim[2];
	int		row;

	ft_seek(0, 49 * 5); // saltar cabezera de mapa
	/*
	** Obtener dimension
	*/
	if (get_next_line(0, &line) < 0)
		ft_error(NULL);
	dim[0] = ft_atoi(ft_strchr(line, ' ') + 1);
	dim[1] = ft_atoi(ft_strrchr(line, ' ') + 1);
	ft_strdel(&line);
	ft_printf("%i filas y %i columnas\n", dim[0], dim[1]);

	
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
	while (read_map_row(&line, &line2, dim, row) && row < dim[0])
	{
		ft_putchar('<');
		ft_putstr(line /*+ ft_ndigits(row) + (row < 100 ? 4 - ft_ndigits(row) : 1)*/);
		ft_putchar('>');
		ft_putchar('\n');
		ft_putchar('<');
		ft_putstr(line2 /*+ ft_ndigits(row) + (row < 100 ? 4 - ft_ndigits(row) : 1)*/);
		ft_putchar('>');
	//	ft_printf("columna numero %i", row);
		ft_putchar('\n');
		row += 2;
		ft_strdel(&line);
		ft_strdel(&line2);
	}
	return (0);
}
