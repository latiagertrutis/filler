/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 07:51:31 by jagarcia          #+#    #+#             */
/*   Updated: 2018/05/28 17:49:40 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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

static void			center_image(t_mlx *mlx)
{
	int dist_x;
	int dist_y;
	int	img_dim[2];

	img_dim[0] = mlx->map->dim[1] * mlx->map->square[1];
	img_dim[1] = mlx->map->dim[0] * mlx->map->square[0];
	dist_x = 0;
	dist_y = 0;
	while (img_dim[0] + 1 + dist_x < RESOLUTION_X - MARGEN_X * 2 - dist_x)
		dist_x++;
	while (img_dim[1] + 1 + dist_y < RESOLUTION_Y - MARGEN_Y * 2 - dist_y)
		dist_y++;
	mlx->map->img_pos[0] = dist_x;
	mlx->map->img_pos[1] = dist_y;
}

void				ft_print_map(t_mlx *mlx)
{
	void	*line;
	int		i;

	center_image(mlx);
	line = mlx_new_image(mlx->ptr, mlx->map->dim[1] * mlx->map->square[1], 1);
	i = 0;
	while (i <= mlx->map->dim[0])
	{
		mlx_put_image_to_window(mlx->ptr, mlx->win, line, MARGEN_X +
				mlx->map->img_pos[0], MARGEN_Y + mlx->map->img_pos[1] +
				mlx->map->square[0] * i++);
	}
	i = 0;
	mlx_destroy_image(mlx->ptr, line);
	line = mlx_new_image(mlx->ptr, 1, mlx->map->dim[0] * mlx->map->square[0]);
	while (i <= mlx->map->dim[1])
	{
		mlx_put_image_to_window(mlx->ptr, mlx->win, line, MARGEN_X +
				mlx->map->img_pos[0] + mlx->map->square[1] * i++, MARGEN_Y +
				mlx->map->img_pos[1]);
	}
	mlx_destroy_image(mlx->ptr, line);
	place_starts(mlx);
	ft_jump_piece(mlx);
}
