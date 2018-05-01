/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 11:58:02 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/01 23:04:15 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

t_mapel		*ini_mapel(int map_width, int map_height)
{
	t_mapel *aux;
	int		i;
	int		size;

	size = map_width * map_height;
	if(!(aux = (t_mapel *)malloc(sizeof(t_mapel) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		aux[i].is_x = 0;
		aux[i].is_o = 0;
		i++;
	}
	return (aux);
}

void		map_reader(t_data *data)
{
	char	*buff;
	int		i;

	if (!(buff = (char *)malloc(sizeof(char) * (data->map_width + 1))) ||
	    !(data->map = ini_mapel(data->map_width, data->map_height)))
		ft_error(NULL);
	buff[data->map_width] = 0;
	i = 0;
	ft_seek(data->fd, data->map_width + 9);
	while (i < data->map_height)
	{
		read(data->fd, buff, data->map_width);
		ft_seek(data->fd, 5);
		update_map(data, i, buff);
		i++;
	}
}
