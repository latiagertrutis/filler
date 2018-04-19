/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_interpret.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 01:38:11 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/03/06 03:24:38 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	line_interpret(t_win *win, int **map)
{
	int		i;
	int		j;
	int 	x;
	int		y;
	t_line	l;
	int		bool;

	i = 1;
	y = 50;
	bool = 0;
	while (i < map[0][0])
	{
		x = 500;
		j = 0;
		while (j < map[0][1])
		{
			if (!bool)
			{
				l.x0 = x + i - 1 - ((map[i][j] * 300) / 10);
				l.y0 = y + j - ((map[i][j] * -300) / 10);
				bool = 1;
			}
			else
			{
				l.xf = x + i - 1 - ((map[i][j] * 300) / 10);
				l.yf = y + j - ((map[i][j] * -300) / 10);
				draw_line(win, &l);
				bool = 0;
			}
//			mlx_pixel_put(win->mlx_id, win->win_id,x + i - 1 - ((map[i][j] * 300) / 10),y + j - ((map[i][j] * -300) / 10), 121163219);
			j++;
			x += 20;
		}
		i++;
		y += 20;
	}
}
