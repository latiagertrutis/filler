/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_addrs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 14:41:02 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/03 14:45:24 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*ft_get_addrs(t_mlx *mlx)
{
	int sizeline;
	int bits;
	int endian;

	sizeline = RESOLUTION_X - MARGEN_X * 2;
	bits = BITS;
	endian = ENDIAN;

	return (mlx_get_data_addrs(mlx->img, sizeline, bits, endian));
}
