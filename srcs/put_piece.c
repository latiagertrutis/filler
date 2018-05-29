/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 16:59:58 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/29 19:24:54 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	search_ini_point(t_data *data)
{
	int i;

	i = 0;
	data->last_piece_width = 1;
	data->last_piece_height = 1;
	if (data->player)
	{
		while (i < (data->map_width * data->map_height))
		{
			if (data->map[i].is_x)
			{
				data->last_piece_mp = i;
				return ;
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
				data->last_piece_mp = i;
				return ;
			}
			i++;
		}
	}
}

static t_quad	search_quad(t_data *data)
{
	int 	i;
	t_quad	q;

	i = 0;
	q = (t_quad){0, data->map_width, data->map_height};
	while (i < (data->map_width * data->map_height))
	{
		if (data->map[i].is_last)
		{
			if ((i % data->map_width) < (data->map_width / 2))
			{
				q.quad_start = 0;
				q.quad_width = data->map_width / 2;
			}
			else
			{
				q.quad_start = data->map_width / 2;
				q.quad_width = data->map_width;
			}
			if ((i / data->map_height) < (data->map_height / 2 ))
			{
				q.quad_height = data->map_height / 2;
			}
			else
			{
				q.quad_height = data->map_height / 2;
				q.quad_start = q.quad_start + ((data->map_height / 2) * data->map_width);
			}
			break ;
		}
		i++;
	}
	return (q);
}

int		put_piece(t_data *data)
{
	int		mp; //punto del mapa
	int		pp; //punto de la pieza

	mp = 0;

	if (!data->last_piece)
		search_ini_point(data);
	if (aproach_strat(data, &mp, &pp, (t_quad){0, data->map_width, data->map_height}) > 4)
	{
		data->last_piece_mp = mp;
		data->last_piece_pp = pp;
		return (print_solution(data, mp, pp));
	}
	else if (aproach_strat(data, &mp, &pp, search_quad(data)))
	{
		data->last_piece_mp = mp;
		data->last_piece_pp = pp;
		return (print_solution(data, mp, pp));
	}
	else if (aproach_strat(data, &mp, &pp, (t_quad){0, data->map_width, data->map_height}))
	{
		data->last_piece_mp = mp;
		data->last_piece_pp = pp;
		return (print_solution(data, mp, pp));
	}
	else
		ft_printf("0 0\n");
	return (0);
/*	pp = piece_point(data);
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
	return (0);*/
}
