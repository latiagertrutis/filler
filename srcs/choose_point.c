/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 18:29:24 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/08 18:55:38 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	search_ini_point(t_data *data)
{
	int i;

	i = 0;
	if (data->player)
	{
		while (i < (data->map_width * data->map_height))
		{
			if (data->map[i].is_x)
			{
				data->last_piece_point = i;
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
				data->last_piece_point = i;
				return ;
			}
		}
		i++;
	}
}

void		choose_point(t_data *data, int *mp, int *pp)
{
	if (!data->last_piece)
		search_ini_point(data);

}
