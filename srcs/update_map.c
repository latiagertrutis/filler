/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 20:11:57 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/07 21:38:26 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	update_map(t_data *data, int i, char *buff)
{
	int j;
	char *aux;

	j = 0;
	aux = buff + 4;
	while (j < data->map_width)
	{
		if (aux[j] == 'x' || aux[j] == 'X')
			data->map[i * data->map_width + j].is_x = -1;
		else if (aux[j] == 'o' || aux[j] == 'O')
			data->map[i * data->map_width + j].is_o = -1;
/*		if (data->map[i * data->map_width + j].is_x)
			write_test("x");
		else if (data->map[i * data->map_width + j].is_o)
			write_test("o");
		else
		write_test(".");*/
	j++;
	}
//	write_test("\n");
}
