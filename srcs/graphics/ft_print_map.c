/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 07:51:31 by jagarcia          #+#    #+#             */
/*   Updated: 2018/05/03 14:56:19 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_print_map(t_mlx *mlx)
{
	char	*addrs;
	int		i;
	
	addrs = ft_get_addrs(mlx);
	i = 0;
	while (i < RESOLUTION_Y - MARGEN_Y * 2)
	{
		ft_line();
		i += mlx->square[1];
	}
	i = 0;
	while (i < RESOLUTION_X - MARGEN_X * 2)
	{
		ft_line();
		i += mlx->square[0];
	}
}
