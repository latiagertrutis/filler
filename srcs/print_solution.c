/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 21:36:08 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/28 18:43:38 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int 	print_solution(t_data *data, int mp, int pp)
{
	int fd = open("datos.txt", O_RDWR | O_APPEND);
	int pos = mp + (-(pp / data->piece_width) * data->map_width) - (pp % data->piece_width);
	dprintf(fd, "\nsoy el jugador: %d\n[%d %d]\n",data->player, pos / data->map_width, pos % data->map_width);
	ft_printf("%d %d\n", pos / data->map_width, pos % data->map_width);
	close(fd);
	return (1);
}
