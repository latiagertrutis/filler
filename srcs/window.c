/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 04:03:14 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/04/19 06:25:01 by mrodrigu         ###   ########.fr       */
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
			p[i][j].z = aux->z;
			map_max_min(aux->z, win);
			aux = aux->next;
			j++;
		}
		i++;
	}
	return (p);
}

static int		convert_to_color(int color)
{	
	color *= 35;
	if (color < 0)
	{
		color = -color;
		if (color > 0xFF)
			return (0xFFFF - (color - 0xFF));
		return (0xFF + (color << 8));
	}
	if (color > 0xFF)
		return (0xFF00FF - (color - 0xFF));
	return (0xFF + (color << 16));
}

static void		put_max_min(t_win *win, void *w_id)
{
	if (win->map_max == win->map_min)		
		mlx_string_put(win->mlx_id, w_id, 63, 19 + (14 - win->map_max) * 5, convert_to_color(win->map_max), "<-FLOOR");
	else
	{
		if (win->map_max < 14)
			mlx_string_put(win->mlx_id, w_id, 63, 19 + (14 - win->map_max) * 5, convert_to_color(win->map_max), "<-MAX");
		else if (win->map_max >= 14)			
			mlx_string_put(win->mlx_id, w_id, 63, 19, 0xFF0000, "<-MAX");
		if (win->map_min > -14)
			mlx_string_put(win->mlx_id, w_id, 63, 89 - win->map_min * 5, convert_to_color(win->map_min), "<-MIN");
		else if (win->map_min <= -14)
			mlx_string_put(win->mlx_id, w_id, 63, 159, 0x00FF00, "<-MIN");
	}
	mlx_string_put(win->mlx_id, w_id, 130, 19, 0xFFFFFF, "Max: ");
	mlx_string_put(win->mlx_id, w_id, 175, 19, 0xFFFFFF, ft_itoa(win->map_max));
	mlx_string_put(win->mlx_id, w_id, 130, 40, 0xFFFFFF, "Min: ");
	mlx_string_put(win->mlx_id, w_id, 175, 40, 0xFFFFFF, ft_itoa(win->map_min));
}

static void		put_lejend(t_win *win)
{
	int color;
	int i;
	int j;
	void *w_id;
	
	if (!(w_id = mlx_new_window(win->mlx_id, 300, 200, "Legend")))
		exit_failure("Can not create window");
	success("Window created");
	i = 20;
	j = 30;
	color = 14;
	while (color >= -14)
	{
		i = 20;
		while (i < 61)
		{
			mlx_pixel_put(win->mlx_id, w_id, i, j, convert_to_color(color));
			mlx_pixel_put(win->mlx_id, w_id, i, j + 1, convert_to_color(color));
			mlx_pixel_put(win->mlx_id, w_id, i, j + 2, convert_to_color(color));
			mlx_pixel_put(win->mlx_id, w_id, i, j + 3, convert_to_color(color));
			mlx_pixel_put(win->mlx_id, w_id, i, j + 4, convert_to_color(color));
			i++;
		}
		j += 5;
		color--;
	}
	put_max_min(win, w_id);
}

t_win	*window(void *mlx_id, t_point *map)
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
	win->coord_x.x = 5.0;
	win->coord_x.y = 0.0;
	win->coord_x.z = 0.0;
	win->coord_y.x = 0.0;
	win->coord_y.y = 5.0;
	win->coord_y.z = 0.0;
	win->coord_z.x = 0.0;
	win->coord_z.y = 0.0;
	win->coord_z.z = 5.0;
	win->map = initialize_map(map, win);
	printf("anchura: %d\naltura: %d", map->x, map->y);
	line_writter(win);
	put_lejend(win);
	return (win);
}
