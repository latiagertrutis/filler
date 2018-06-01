/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_graphic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 22:41:08 by jagarcia          #+#    #+#             */
/*   Updated: 2018/06/01 19:01:47 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		loop(void *mlx)
{
	static int	end = 1;

	if (end >= 0 && !(((t_mlx *)mlx)->pause))
	{
		ft_set_piece_pos(mlx);
		if (!(end = ft_jump_piece(mlx)))
		{
			ft_place_piece(mlx, 0, 0);
			if (((t_mlx *)mlx)->piece[1]->shape)
				ft_place_piece(mlx, 1, ((t_mlx *)mlx)->piece[1]->player);
			ft_copy_piece(mlx);
			ft_jump_map(((t_mlx *)mlx)->map->dim);
			ft_jump_piece(mlx);
		}
		else if (end < 0)
		{
			ft_place_piece(mlx, -1, ((t_mlx *)mlx)->piece[1]->player);
			mlx_string_put(((t_mlx *)mlx)->ptr, ((t_mlx *)mlx)->win,
					RESOLUTION_X / 2 - 30, RESOLUTION_Y / 2, 0, "FINISH");
		}
		else
			ft_place_piece(mlx, 1, ((t_mlx *)mlx)->piece[1]->player);
	}
	return (0);
}

int				main(void)
{
	t_mlx		*mlx;
	t_map		*map;
	int			x;
	int			y;
	
	mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx));
	mlx->ptr = mlx_init();
	ft_initialice(mlx);
	if (!(mlx->win = mlx_new_window(mlx->ptr, RESOLUTION_X,
			RESOLUTION_Y, "FILLER")))
		ft_error(NULL);
	map = mlx->map;
	if (!(mlx->img = mlx_new_image(mlx->ptr, map->dim[1] * map->square[1] + 1,
			map->dim[0] * map->square[0] + 1)))
		ft_error(NULL);
	mlx->wallpaper = mlx_xpm_file_to_image(mlx->ptr, "hotline_filler.xpm", &x, &y);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->wallpaper, 0, 0);
	ft_set_bricks(mlx);
	ft_print_map(mlx);
	ft_info(mlx);
	mlx_key_hook(mlx->win, ft_keys, mlx);
	mlx_loop_hook(mlx->ptr, loop, mlx);
	mlx_loop(mlx->ptr);
	return (0);
}
