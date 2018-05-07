/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_starts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 15:53:00 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/07 21:36:25 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char		*read_map(char **line, int dim[2], int row)
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
	if (!a)
		ft_error("There is nothing to read :/");
	(*line)[read_cuant - 1] = 0;
	return ((*line) + (row < 1000 ? 4 : ft_ndigits(row) + 1));
}

static void		place_start(t_mlx *mlx, int row, int col, char player)
{
	void	*brick;
	int		pos_x;
	int		pos_y;

	if (player == 'O')
		brick = (mlx->bricks)[0];
	else if (player == 'X')
		brick = (mlx->bricks)[1];
	pos_x = MARGEN_X + mlx->params->img_pos[0] + 1
		+ mlx->params->square[1] * col;
	pos_y = MARGEN_Y + mlx->params->img_pos[1] + 1
		+ mlx->params->square[0] * row;
	mlx_put_image_to_window(mlx->ptr, mlx->win, brick, pos_x, pos_y);
}

void			ft_place_starts(t_mlx *mlx)
{
	int		starts;
	char	*line;
	int		row;
	char	*tmp[2];

	ft_seek(0, mlx->params->dim[1] + 4);
	starts = 2;
	row = -1;
	while (++row <= mlx->params->dim[0])
	{
		tmp[0] = read_map(&line, mlx->params->dim, row);
		if ((tmp[1] = ft_strchr(tmp[0], 'X')))
		{
			place_start(mlx, row, tmp[1] - tmp[0], 'X');
			starts--;
		}
		else if ((tmp[1] = ft_strchr(tmp[0], 'O')))
		{
			place_start(mlx, row, tmp[1] - tmp[0], 'O');
			starts--;
		}
		ft_strdel(&line);
	}
	if (starts < 0 || starts)
		ft_error("This map is not very well writen");
}
