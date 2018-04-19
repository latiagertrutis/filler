
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_pressed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 05:00:09 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/04/19 04:14:50 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		key_pressed(int keycode, t_win *win)
{
	double zoom;
	double ang;

	zoom = 2.0;
	ang = 10.0;
	printf("x = (%f, %f, %f)\ny = (%f, %f, %f)\nz = (%f, %f, %f)\n", win->coord_x.x, win->coord_x.y, win->coord_x.z, win->coord_y.x, win->coord_y.y, win->coord_y.z, win->coord_z.x, win->coord_z.y, win->coord_z.z);
	ft_putstr("\033[1;96mKey pressed: ");
	ft_putnbr(keycode);
	ft_putstr("\033[0m\n");
	if (keycode == K_MINUS || keycode == K_PLUS)
	{
		if (keycode == K_MINUS)
		{
			resize_point(&(win->coord_x), -zoom);
			resize_point(&(win->coord_y), -zoom);
			resize_point(&(win->coord_z), -zoom);
		}
		else
		{
			resize_point(&(win->coord_x), zoom);
			resize_point(&(win->coord_y), zoom);
			resize_point(&(win->coord_z), zoom);
		}
		mlx_destroy_image(win->mlx_id, win->img_ptr);
		line_writter(win);
	}
	if (keycode == K_A || keycode == K_W || keycode == K_D || keycode == K_S)
	{
		if (keycode == K_A)
			traslate_point(&(win->origin), -TRASLATION, 0.0);
		else if (keycode == K_W)
			traslate_point(&(win->origin), 0.0, -TRASLATION);
		else if (keycode == K_D)
			traslate_point(&(win->origin), TRASLATION, 0.0);
		else
			traslate_point(&(win->origin), 0.0, TRASLATION);
		mlx_destroy_image(win->mlx_id, win->img_ptr);
		line_writter(win);
	}
	if (keycode == K_L_ARR || keycode == K_U_ARR || keycode == K_R_ARR || keycode == K_D_ARR || keycode == K_POINT || keycode == K_SLASH)
	{		
		if (keycode == K_L_ARR)
		{
			rotate_point(&(win->coord_x), -ang, 0.0, 0.0);
			rotate_point(&(win->coord_y), -ang, 0.0, 0.0);
			rotate_point(&(win->coord_z), -ang, 0.0, 0.0);
		}
		else if (keycode == K_U_ARR)
		{
			rotate_point(&(win->coord_x), 0.0, -ang, 0.0);
			rotate_point(&(win->coord_y), 0.0, -ang, 0.0);
			rotate_point(&(win->coord_z), 0.0, -ang, 0.0);
		}
		else if (keycode == K_R_ARR)
		{
			rotate_point(&(win->coord_x), ang, 0.0, 0.0);
			rotate_point(&(win->coord_y), ang, 0.0, 0.0);
			rotate_point(&(win->coord_z), ang, 0.0, 0.0);
		}
		else if (keycode == K_POINT)
		{
			rotate_point(&(win->coord_x), 0.0, 0.0, -ang);
			rotate_point(&(win->coord_y), 0.0, 0.0, -ang);
			rotate_point(&(win->coord_z), 0.0, 0.0, -ang);
		}
		else if (keycode == K_SLASH)
		{
			rotate_point(&(win->coord_x), 0.0, 0.0, ang);
			rotate_point(&(win->coord_y), 0.0, 0.0, ang);
			rotate_point(&(win->coord_z), 0.0, 0.0, ang);
		}
		else
		{
			rotate_point(&(win->coord_x), 0.0, ang, 0.0);
			rotate_point(&(win->coord_y), 0.0, ang, 0.0);
			rotate_point(&(win->coord_z), 0.0, ang, 0.0);
		}
		mlx_destroy_image(win->mlx_id, win->img_ptr);
		line_writter (win);
	}
	if (keycode == K_ESC) 
	{
		ft_putstr("\033[1;95mLeaving the program\n¯\\_(ツ)_/¯\n\033[0m");
		exit(0);
	}
	/*
	  if (keycode == 5)
	  {
	  pers.d1 -= 100;
	  mlx_destroy_image(win->mlx_id, win->img_ptr);
	  line_interpret(win, win->map, pers);
	  }
	  if (keycode == 16)
	  {
	  pers.d2 -= 100;
	  mlx_destroy_image(win->mlx_id, win->img_ptr);
	  line_interpret(win, win->map, pers);
	  }
	  if (keycode == 38)
	  {
	  pers.d1 += 100;
	  mlx_destroy_image(win->mlx_id, win->img_ptr);
	  line_interpret(win, win->map, pers);
	  }
	  if (keycode == 4)
	  {
	  pers.d2 += 100;
	  mlx_destroy_image(win->mlx_id, win->img_ptr);
	  line_interpret(win, win->map, pers);
	  }
	  if (keycode == K_L_ARR)
	  {
//		pers.d1 -= 100;
pers.c1 -= 100;
mlx_destroy_image(win->mlx_id, win->img_ptr);
line_interpret(win, win->map, pers);
}
if (keycode == K_U_ARR)
{
//		pers.d2 -= 100;
pers.c2 -= 100;
mlx_destroy_image(win->mlx_id, win->img_ptr);
line_interpret(win, win->map, pers);
}
if (keycode == K_R_ARR)
{
//		pers.d1 += 100;
pers.c1 += 100;
mlx_destroy_image(win->mlx_id, win->img_ptr);
line_interpret(win, win->map, pers);
}
if (keycode == 125)
{
//		pers.d2 += 100;
pers.c2 += 100;
mlx_destroy_image(win->mlx_id, win->img_ptr);
line_interpret(win, win->map, pers);
}
if (keycode == K_MINUS)
{
pers.zoom -= 5;
mlx_destroy_image(win->mlx_id, win->img_ptr);
line_interpret(win, win->map, pers);
}
if (keycode == K_PLUS)
{
pers.zoom += 5;
mlx_destroy_image(win->mlx_id, win->img_ptr);
line_interpret(win, win->map, pers);
}
if (keycode == 0)
{
pers.x -= 100;
mlx_destroy_image(win->mlx_id, win->img_ptr);
line_interpret(win, win->map, pers);
}
if (keycode == K_W)
{
pers.y -= 100;
mlx_destroy_image(win->mlx_id, win->img_ptr);
line_interpret(win, win->map, pers);
}
if (keycode == 2)
{
pers.x += 100;
mlx_destroy_image(win->mlx_id, win->img_ptr);
line_interpret(win, win->map, pers);
}
if (keycode == 1)
{
pers.y += 100;
mlx_destroy_image(win->mlx_id, win->img_ptr);
line_interpret(win, win->map, pers);
}
if (keycode == 47)
{
pers.d3 += 10;
mlx_destroy_image(win->mlx_id, win->img_ptr);
line_interpret(win, win->map, pers);
}
if (keycode == 44)
{
pers.d3 -= 10;
if (pers.d3 == 0)
pers.d3 = 15;
mlx_destroy_image(win->mlx_id, win->img_ptr);
line_interpret(win, win->map, pers);
}
if (keycode == 8)
mlx_destroy_image(win->mlx_id, win->img_ptr);
if (keycode == 53)
{
ft_putstr("\033[1;95mLeaving the program\n¯\\_(ツ)_/¯\n\033[0m");
exit(0);
}
	*/
	return (0);
}
