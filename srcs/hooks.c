/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 04:55:46 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/04/17 03:43:44 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	hooks(t_win *win)
{
	//mlx_key_hook(win->win_id, key_pressed, win);
	mlx_hook(win->win_id, 2, 0, key_pressed, win);
	mlx_hook(win->win_id, 17, 0, leave_program, win);
}
