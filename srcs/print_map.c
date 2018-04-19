/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 05:34:43 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/04/19 06:04:03 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_map(t_point *map)
{
	t_point	*aux;
	int		i;

	i = 1;
	aux = map;
	ft_putstr("\033[1;93m");
	ft_putstr("=========================== MAP ===========================\n");
	while(aux)
	{
		ft_putstr("(");
		ft_putnbr(aux->x);
		ft_putstr(", ");
		ft_putnbr(aux->y);
		ft_putstr(", ");
		ft_putnbr(aux->z);
		ft_putstr(") ");
		if (!(i++ % 6))
			ft_putstr("\n");
		aux = aux->next;
	}	
	ft_putstr("\n===========================================================");
	ft_putstr("\033[0m\n");
}
