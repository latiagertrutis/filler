/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 04:30:01 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/04/19 05:17:39 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	resize_point(t_2dp *p, double cuant)
{
	if (cuant < 0.0)
	{
		p->x /= -cuant;
		p->y /= -cuant;
		p->z /= -cuant;
	}
	else if (cuant > 1.0)
	{
		p->x *= cuant;
		p->y *= cuant;
		p->z *= cuant;
	}
}
