/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 04:03:14 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/04/21 03:15:03 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		map_max_min(int z, t_win *win)
{
	if (win->map_max < z)
		win->map_max = z;
	else if (win->map_min > z)
		win->map_min = z;
}

static t_2dpi	**initialize_map(t_point *map, t_win *win)
{
	int		i;
	int		j;
	t_point	*aux;
	t_2dpi	**p;

	if (!(p = (t_2dpi **)ft_memalloc(sizeof(t_2dpi *) * ((map->x) + 1))))
		exit_failure(NULL);
	i = 0;
	aux = map->next;
	while (aux)
	{
		j = 0;
		if (!(p[i] = (t_2dpi *)ft_memalloc(sizeof(t_2dpi) * ((map->y) + 1))))
			exit_failure(NULL);
		while (j <= map->y && aux)
		{
			p[i][j].x = aux->x;
			p[i][j].y = aux->y;
			p[i][j++].z = aux->z;
			map_max_min(aux->z, win);
			aux = aux->next;
		}
		i++;
	}
	return (p);
}

static double	ini_size(t_win *win)
{
	double x;

	x = ((double)W_WIDTH - 1.0) / ((double)win->map_wid);
	if (x * (double)win->map_hei <= (double)W_HEIGHT)
		return (x);
	return (((double)W_HEIGHT - 1.0) / ((double)win->map_hei));
	
}

t_win			*window(void *mlx_id, t_point *map)
{
	t_win	*win;

	if (!(win = (t_win *)ft_memalloc(sizeof(t_win))))
		exit_failure(NULL);
	if (!(win->win_id = mlx_new_window(mlx_id, W_WIDTH, W_HEIGHT, "FDF")))
		exit_failure("Can not create window");
	success("Window created");
	win->mlx_id = mlx_id;
	win->map_wid = map->x + 1;
	win->map_hei = map->y + 1;
	win->map_max = 0;
	win->map_min = 0;
	win->coord_x.x = ini_size(win);
	win->coord_x.y = 0.0;
	win->coord_x.z = 0.0;
	win->coord_y.x = 0.0;
	win->coord_y.y = win->coord_x.x;
	win->coord_y.z = 0.0;
	win->coord_z.x = 0.0;
	win->coord_z.y = 0.0;
	win->coord_z.z = win->coord_x.x;
	win->map = initialize_map(map, win);
	line_writter(win);
	put_legend(win);
	return (win);
}
