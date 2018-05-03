/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 20:43:35 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/03 16:58:09 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	put_element(t_data *data, int i, int j)
{
	int		aux;

	aux = ft_roundup((double)(i * j) / 8.0) - 1;
	data->piece[aux] = data->piece[aux] | (0x80 >> ((i * j) % 8));
}

void		update_piece(t_data *data, int i, char *buff)
{
	int		j;

	j = 0;
	while (j < data->piece_width)
	{
		if (buff[j] == '*')
			put_element(data, i, j);
		j++;
	}
}
