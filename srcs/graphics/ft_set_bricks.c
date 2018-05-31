/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_bricks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 01:31:17 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/28 16:16:41 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		build_brick(t_mlx *mlx, int brick, int color)
{
	int	i;
	int	*addrs;

	i = 0;
	addrs = (int *)ft_get_addrs((mlx->bricks)[brick], mlx->map->square[1] + 1);
	while (i < (mlx->map->square[1] + 1) * (mlx->map->square[0] + 1))
	{
		if (i <= (mlx->map->square[1] + 1) * 2)
			addrs[i] = 0;
		else if (i % (mlx->map->square[1] + 1) < 2 || i % (mlx->map->square[1]
				+ 1) > (mlx->map->square[1] + 1) - 3)
			addrs[i] = 0;
		else if (i > (mlx->map->square[1] + 1) * (mlx->map->square[0] - 1))
			addrs[i] = 0;
		else
			addrs[i] = color;
		i++;
	}
}

static void		set_color_as_brick(t_mlx *mlx, int color0, int color1)
{
	int *addrs;
	int	i;
	
	(mlx->bricks)[0] = mlx_new_image(mlx->ptr, mlx->map->square[1] + 1,
			mlx->map->square[0] + 1);
	build_brick(mlx, 0, color0);
	(mlx->bricks)[1] = mlx_new_image(mlx->ptr, mlx->map->square[1] + 1,
			mlx->map->square[0] + 1);
	build_brick(mlx, 1, color1);
}

static void		set_image_as_brick(t_mlx *mlx, char *file0, char *file1)
{
	int		tmp1;
	int		tmp2;
	char	*file;

	if (!(file = ft_strjoin("bricks/", file0)))
		ft_error(NULL);
	(mlx->bricks)[0] = mlx_xpm_file_to_image(mlx->ptr, file, &tmp1, &tmp2);
	free(file);
	if (!(file = ft_strjoin("bricks/", file1)))
		ft_error(NULL);
	(mlx->bricks)[1] = mlx_xpm_file_to_image(mlx->ptr, file, &tmp1, &tmp2);
	free(file);
}

void			ft_set_bricks(t_mlx *mlx)
{
	int	i;
	int	*addrs;

	mlx->bricks = (void **)ft_memalloc(sizeof(void *) * 3);
	if (mlx->map->dim[0] == 15 && mlx->map->dim[1] == 17)
	{
//		set_image_as_brick(mlx, "BRICKB_15x17.xpm", "BRICKA_15x17.xpm");
		set_color_as_brick(mlx, 0x2753A5, 0xB3592B);
	}
	else if (mlx->map->dim[0] == 24 && mlx->map->dim[1] == 40)
		set_image_as_brick(mlx, "BRICKB_24x40.xpm", "BRICKA_24x40.xpm");
	else if (mlx->map->dim[0] == 100 && mlx->map->dim[1] == 99)
		set_image_as_brick(mlx, "BRICKB_100x99.xpm", "BRICKA_100x99.xpm");
	else
		set_color_as_brick(mlx, 0xFF0000, 0x00FF00);
	(mlx->bricks)[2] = mlx_new_image(mlx->ptr, mlx->map->square[1] + 1,
			mlx->map->square[0] + 1);
	addrs = (int *)ft_get_addrs((mlx->bricks)[2], mlx->map->square[1]);
	i = 0;
	while (i < (mlx->map->square[1] + 1) * (mlx->map->square[0] + 1))
		addrs[i++] = 0xFFFFFF;
}
