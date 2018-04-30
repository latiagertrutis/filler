/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 11:58:02 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/04/30 16:18:56 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	map_reader(t_data *data)
{
	char	*buff;
	int		i;

	if (!(buff = (char *)malloc(sizeof(char) * (data->map_width + 1))))
		return ; //poner error
	i = 0;
	ft_seek(data->fd, 16 + ndigits(data->map_width) + ndigits(data->map_height) + data->map_width);
	while (i < data->map_height)
	{
		read(data->fd, buff, data->map_width + 1);
		update_map(data, i, buff);
		i++;
	}
}
