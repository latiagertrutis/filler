/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_writter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 14:56:28 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/04/18 04:36:37 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_2dpd	esc_prod(t_2dpd v, double p)
{
	v.x *= p;
	v.y *= p;
	v.z *= p;
	return (v);
}

static t_2dpd vectadd(t_2dpd v1, t_2dpd v2, t_2dpd v3, t_2dpd p)
{
	t_2dpd aux;

	aux.x = v1.x + v2.x + v3.x + p.x;
	aux.y = v1.y + v2.y + v3.y + p.y;
	aux.z = v1.z + v2.z + v3.z + p.z;
	return (aux);
}
	

static t_2dpd	new_point(t_win *win, t_2dp p0, t_2dpd p)
{
	t_2dpd pf;

	pf = vectadd(esc_prod(*(win->coord_x), p0.x), esc_prod(*(win->coord_y), p0.y), esc_prod(*(win->coord_z), p0.z), p);
	return (pf);
}

void	line_writter(t_win *win)
{
	int i;
	int j;
	t_2dpd p;

	p.x = (double)win->pers.tx;
	p.y = (double)win->pers.ty;
	p.z = (double)win->pers.tz;
	printf("(%f, %f, %f)\n", win->coord_x->x, win->coord_x->y, win->coord_x->z);
	rotate_point(win, win->coord_x);
	rotate_point(win, win->coord_y);
	rotate_point(win, win->coord_z); 

//	resize_point(win, win->coord_x);
//	resize_point(win, win->coord_y);
//	resize_point(win, win->coord_z);

//	traslate_point(win, win->coord_x);
//	traslate_point(win, win->coord_y);
//	traslate_point(win, win->coord_z);

	printf("(%f, %f, %f)\n", win->coord_x->x, win->coord_x->y, win->coord_x->z);
	create_image(win);
	i = 0;
	ft_putstr("ENTRO");
	while (i < win->map_wid)
	{
		j = 0;
		while (j < win->map_hei)
		{
			if (j + 1 < win->map_hei)
				line_interpret(win, new_point(win, win->map[i][j], p), new_point(win, win->map[i][j + 1], p));
			if (i + 1 < win->map_wid)
				line_interpret(win, new_point(win, win->map[i][j], p), new_point(win, win->map[i + 1][j], p));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(win->mlx_id, win->win_id, win->img_ptr, 0, 0);
	ft_putstr("SALGO");
}
