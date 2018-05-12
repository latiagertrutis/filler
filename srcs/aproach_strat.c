/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aproach_strat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 19:00:35 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/12 15:09:40 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	check_enemy_points(t_data *data, int pos)
{
	int i;
	int diff;
	int aux_diff;

	i = 0;
	diff = data->map_width + data->map_height;
	while (i < (data->map_width * data->map_height))
	{
		if (data->player ? data->map[i].is_o : data->map[i].is_x)
		{
			if ((aux_diff = ft_abs(i / data->map_width - pos / data->map_width) + ft_abs(i % data->map_width - pos % data->map_width)) < diff)
				diff = aux_diff;
		}
	}
	return (diff);
}

int			aproach_strat(t_data *data, int *mp, int *pp)
{
	int i;
	int diff;
	int aux_diff;
	int	pos;

	i = 0;
	diff = -1;
	while (i < (data->last_piece_width * data->last_piece_height))
	{
		pos = cord_piece_to_map(data->last_piece_width, data->map_width,
								data->last_piece_mp, data->last_piece_pp, i);
		if (data->player ? data->map[pos].is_x : data->map[pos].is_o)
		{
			if (diff < 0 || (aux_diff = check_enemy_points(data, pos)) < diff)
			{
				if (check_position(data, pos, i))
				{
					diff = aux_diff;
					*mp = pos;
					*pp = i;
				}
			}
		}
		i++;
	}
	if (diff < 0)
		return (0);
	return (1);
}
