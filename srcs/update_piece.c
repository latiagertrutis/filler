/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 20:43:35 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/07 22:33:39 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	put_element(t_data *data, int i, int j)
{
	int		aux;

	aux = ((i * data->piece_width) + j) / 8;
	write_test(ft_itoa(aux));
	data->piece[aux] = data->piece[aux] | (0x80 >> (((i * data->piece_width) + j) % 8));
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
