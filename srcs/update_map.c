/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 20:11:57 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/03 16:10:57 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	update_map(t_data *data, int i, char *buff)
{
	int j;

	j = 0;
	while (j < data->map_width)
	{
		if (buff[j] == 'x' || buff[j] == 'X')
			data->map[i * data->map_width + j].is_x = 1;
		else if (buff[j] == 'o' || buff[j] == 'O')
			data->map[i * data->map_width + j].is_o = 1;
		if (data->map[i * data->map_width + j].is_x)
			write_test("x");
		else if (data->map[i * data->map_width + j].is_o)
			write_test("o");
		else
			write_test(".");
	j++;
	}
	write_test("\n");
}
