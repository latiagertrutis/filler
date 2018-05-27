/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 07:51:31 by jagarcia          #+#    #+#             */
/*   Updated: 2018/05/27 03:50:52 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void			line(int *addrs, int point, int end, int vertical)
{
	int j;

	j = 0;
	while (j < end)
		addrs[point + (j++ * vertical)] = LINE_COLOR;
}

static char			*read_map(char **line, int dim[2], int row)
{
	int	read_cuant;
	int	a;

	if (row < 1000)
		read_cuant = dim[1] + 5;
	else
		read_cuant = dim[1] + ft_ndigits(row) + 2;
	*line = ft_strnew(read_cuant);
	if ((a = read(0, *line, read_cuant)) < 0)
		ft_error(NULL);
	if (!a)
		ft_error("ERROR reading map\n");
	(*line)[read_cuant - 1] = 0;
	return ((*line) + (row < 1000 ? 4 : ft_ndigits(row) + 1));
}

static void			place_starts(t_mlx *mlx)
{
	int		starts;
	char	*line;
	int		row;
	char	*tmp[2];

	ft_seek(STDIN_FILENO, mlx->map->dim[1] + 5);
	starts = 2;
	row = -1;
	while (++row < mlx->map->dim[0])
	{
		tmp[0] = read_map(&line, mlx->map->dim, row);
		if ((tmp[1] = ft_strchr(tmp[0], 'X')))
		{
			ft_place_brick(mlx, row, tmp[1] - tmp[0], 'X');
			starts--;
		}
		else if ((tmp[1] = ft_strchr(tmp[0], 'O')))
		{
			ft_place_brick(mlx, row, tmp[1] - tmp[0], 'O');
			starts--;
		}
		ft_strdel(&line);
	}
	if (starts < 0 || starts)
		ft_error("ERROR searching starts\n");
}

void				ft_print_map(t_mlx *mlx)
{
	int		*addrs;
	int		i;
	int		img_dim[2];
	int		point;

	img_dim[0] = mlx->map->dim[1] * mlx->map->square[1];
	img_dim[1] = mlx->map->dim[0] * mlx->map->square[0];
	addrs = (int *)ft_get_addrs(mlx->img, mlx->map->dim[1] *
			mlx->map->square[1]);
	i = 0;
	while (i <= mlx->map->dim[0])
	{
		point = (img_dim[0] + 1) * i++ * mlx->map->square[0];
		line(addrs, point, img_dim[0], 1);
	}
	i = 0;
	while (i <= mlx->map->dim[1])
	{
		point = i++ * mlx->map->square[1];
		line(addrs, point, img_dim[1], img_dim[0] + 1);
	}
	ft_place_image(mlx, img_dim);
	place_starts(mlx);
	ft_jump_piece(mlx);
}
