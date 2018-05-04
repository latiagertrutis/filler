/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_starts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 15:53:00 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/04 17:36:05 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		read_map(char **line,  int dim[2], int row)
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

void	ft_place_starts(t_mlx *mlx)
{
	int		starts;
	char	*line;
	int		row;
	char	*tmp;
	char	*tmp2;
	
	starts = 2;
	if (mlx->params->dim[0] < 1000)
		ft_seek(0, mlx->params->dim[1] + ft_ndigits(mlx->params->dim[0]) + (mlx->params->dim[0] < 100 ? 3 : 2));
	else
		ft_seek(0, mlx->params->dim[1] + 5);
	while (row < mlx->params->dim[0])
	{
		read_map(&line, mlx->params->dim, row);
		tmp2 = line + ft_ndigits(row) + (row < 100 ? 4 - ft_ndigits(row) : 1);
		if (tmp = ft_strchr(tmp2, 'X'))
		{
			place_start(mlx, row, tmp - tmp2, 'X');
			start--;
		}
		else if (tmp = ft_strchr(line, 'O'))
		{
			place_start(mlx, row, tmp - tmp2, 'O');
			start--;
		}
		row += 1;
		ft_strdel(&line);
	}
	if (start < 0)
		ft_error("This map is not very well writen");
}
