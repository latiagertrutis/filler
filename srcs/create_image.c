/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 22:10:45 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/04/13 22:33:56 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	create_image(t_win *win)
{
	int		bit_per_pixel = 32;
	int		size_line = W_WIDTH * 4;
	int		endian = 0;

	win->img_ptr = mlx_new_image(win->mlx_id, W_WIDTH, W_HEIGHT);
	win->img = mlx_get_data_addr(win->img_ptr, &bit_per_pixel, &size_line, &endian);
}
