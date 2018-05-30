/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aproach_strat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 19:00:35 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/30 17:54:06 by mrodrigu         ###   ########.fr       */
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

static void			check_piece_pos(t_data *data, t_aproach *apr)
{
	while (apr->j < (data->piece_width * data->piece_height))
	{
		if (data->piece[apr->j / 8] & (0x80 >> (apr->j % 8)))
		{
			apr->pos = cord_piece_to_map(data->piece_width, data->map_width,
			                            apr->k, apr->i, apr->j);
			if (data->player ? data->map[apr->pos].is_x : data->map[apr->pos].is_o)
			{
				if (check_position(data, apr->pos, apr->i))
				{
					if ((apr->aux_diff = check_enemy_points(data, apr->pos)) < apr->diff)
					{
						write_test("pos: ");
						write_test(ft_itoa(apr->pos));
						apr->diff = apr->aux_diff;
						apr->mp = apr->pos;
						apr->pp = apr->i;
					}
				}
			}
		}
		apr->j++;
	}
}

static void		check_map(t_data *data, t_quad quad, t_aproach *apr)
{
	while (apr->k < (quad.quad_width * quad.quad_height))
	{
		apr->i = 0;
		if (data->player ? data->map[apr->k].is_x : data->map[apr->k].is_o)
		{
			while (apr->i < (data->piece_width * data->piece_height))
			{
				if (data->piece[apr->i / 8] & (0x80 >> (apr->i % 8)))
				{
					apr->j = 0;
					check_piece_pos(data, apr);
				}
				apr->i++;
			}
		}
		apr->k++;
		if ((apr->k % data->map_width) >= quad.quad_width)
			apr->k = apr->k + (data->map_width - quad.quad_width);
	}
}

int			aproach_strat(t_data *data, int *mp, int *pp, t_quad quad)
{

	t_aproach	apr;

	apr = (t_aproach){0, 0, quad.quad_start,0, 0, 0, data->map_width * data->map_height, 0};
	check_map(data, quad, &apr);
	*mp = apr.mp;
	*pp = apr.pp;
	if (apr.diff == data->map_width * data->map_height)
		return (0);
	return (apr.diff);
}
