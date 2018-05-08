/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 16:59:58 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/08 18:56:15 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		put_piece(t_data *data)
{
	int		mp; //punto del mapa
	int		pp; //punto de la pieza

	mp = 0;

	pp = piece_point(data);
	if (data->player)
	{
		while (mp < (data->map_width * data->map_height))
		{
			if (data->map[mp].is_x)
			{
				if (check_position(data, mp, pp))
					return(print_solution(data, mp, pp));
			}
			mp++;
		}
	}
	else
	{
		while (mp < (data->map_width * data->map_height))
		{
			if (data->map[mp].is_o)
			{
				if (check_position(data, mp, pp))
					return(print_solution(data, mp, pp));
			}
			mp++;
		}
	}
	return (0);
}
