/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 16:59:58 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/28 18:46:26 by mrodrigu         ###   ########.fr       */
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

int		put_piece(t_data *data)
{
	int		mp; //punto del mapa
	int		pp; //punto de la pieza

	mp = 0;

	if (!data->last_piece)
		search_ini_point(data);
	if (aproach_strat(data, &mp, &pp))
	{
		data->last_piece_mp = mp;
		data->last_piece_pp = pp;
		return (print_solution(data, mp, pp));
	}
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
