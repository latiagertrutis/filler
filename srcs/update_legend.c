/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_legend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 03:48:50 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/04/21 04:41:03 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		background(t_win *win)
{
	int		bit_per_pixel = sizeof(int) * 8;
	int		size_line = 170 * sizeof(int);
	int		endian = 0;
	int		i = 0;
	
	win->legend.img = mlx_get_data_addr(win->legend.img_ptr, &bit_per_pixel, &size_line, &endian);
	while (i < 22100)
		((int *)win->legend.img)[i++] = 0x696969;
}

void			update_legend(t_win *win)
{
	if (win->legend.img_ptr)
		mlx_destroy_image(win->mlx_id, win->legend.img_ptr);
	win->legend.img_ptr = mlx_new_image(win->mlx_id, 170, 130);
	background(win);
	mlx_put_image_to_window(win->mlx_id, win->legend.win_id, win->legend.img_ptr, 130, 60);
	mlx_string_put(win->mlx_id, win->legend.win_id, 130, 60, 0xffcc75, "ANGLE X:");
	mlx_string_put(win->mlx_id, win->legend.win_id, 215, 60, 0xffcc75, ft_itoa(win->legend.ang_x));
	mlx_string_put(win->mlx_id, win->legend.win_id, 130, 80, 0xffcc75, "ANGLE Y:");
	mlx_string_put(win->mlx_id, win->legend.win_id, 215, 80, 0xffcc75, ft_itoa(win->legend.ang_y));
	mlx_string_put(win->mlx_id, win->legend.win_id, 130, 100, 0xffcc75, "ANGLE Z:");
	mlx_string_put(win->mlx_id, win->legend.win_id, 215, 100, 0xffcc75, ft_itoa(win->legend.ang_z));
}
