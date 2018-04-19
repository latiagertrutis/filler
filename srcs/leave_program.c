/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leave_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 05:15:23 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/03/04 05:17:42 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		leave_program(int keycode, t_win *win)
{
	(void)keycode;
	(void)win;
	ft_putstr("\033[1;95mLeaving the program\n¯\\_(ツ)_/¯\n\033[0m");
	exit(0);
}
