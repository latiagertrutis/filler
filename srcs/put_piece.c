/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 16:59:58 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/04 18:49:22 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		put_piece(t_data *data)
{
	int		i;

	i = 0;
	if (data->player)
	{
		while (i < (data->map_width * data->map_height))
		{
			if (data->map[i].is_x)
			{
				if (check_position(data, i, piece_point(data)))
					return(print_solution(data, i));
			}
			i++;
		}
	}
	else
	{
		while (i < (data->map_width * data->map_height))
		{
			if (data->map[i].is_o)
			{
				if (check_position(data, i))
					return(print_solution(data, i));
			}
			i++;
		}
	}
	return (0);
}
