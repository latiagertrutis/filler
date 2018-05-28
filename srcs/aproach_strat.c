/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aproach_strat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 19:00:35 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/28 19:30:02 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	check_enemy_points(t_data *data, int pos)
{
	int i;
	int diff;
	int aux_diff;

	i = 0;
	diff = data->map_width * data->map_height;
	while (i < (data->map_width * data->map_height))
	{
		if (data->player ? data->map[i].is_o : data->map[i].is_x)
		{
			if ((aux_diff = (int)sqrt(pow(i / data->map_width - pos / data->map_width, 2) + pow(i % data->map_width - pos % data->map_width, 2))) < diff)
				diff = aux_diff;
		}
		i++;
	}
	return (diff);
}

int			aproach_strat(t_data *data, int *mp, int *pp)
{
	int i, j, k;
	int diff;
	int aux_diff;
	int	pos;

	diff = data->map_width * data->map_height;
	k = 0;
	while (k < (data->map_width * data->map_height))
	{
		i = 0;
		if (data->player ? data->map[k].is_x : data->map[k].is_o)
		{
			while (i < (data->piece_width * data->piece_height))
			{
				if (data->piece[i / 8] & (0x80 >> (i % 8)))
				{
					j = 0;
					while (j < (data->piece_width * data->piece_height))
					{
						if (data->piece[j / 8] & (0x80 >> (j % 8)))
						{
							pos = cord_piece_to_map(data->piece_width, data->map_width,
							                        k, i, j);
							if (data->player ? data->map[pos].is_x : data->map[pos].is_o)
							{
								if ((aux_diff = check_enemy_points(data, pos)) < diff)
								{
									write_test("pos: ");
									write_test(ft_itoa(pos));
									if (check_position(data, pos, i))
									{
										diff = aux_diff;
										*mp = pos;
										*pp = i;
									}
								}
							}
						}
						j++;
					}
				}
				i++;
			}
		}
		k++;
	}
	if (diff == data->map_width * data->map_height)
		return (0);
	return (1);
}
