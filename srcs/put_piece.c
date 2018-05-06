/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 16:59:58 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/06 22:18:30 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		put_piece(t_data *data)
{
	int		i;
	int		pp;

	i = 0;
	pp = piece_point(data);
	if (data->player)
	{
		while (i < (data->map_width * data->map_height))
		{
			if (data->map[i].is_x)
			{
				if (check_position(data, i, pp))
					return(print_solution(data, i, pp));
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
				if (check_position(data, i, pp))
					return(print_solution(data, i, pp));
			}
			i++;
		}
	}
	return (0);
}
