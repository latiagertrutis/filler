/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 11:58:02 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/02 20:53:24 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static t_mapel		*ini_mapel(int map_width, int map_height)
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

static void			read_map(t_data *data)
{
	int 	i;
	char	*buff;

	if (!(buff = (char *)malloc(sizeof(char) * (data->map_width + 1))))
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
	free(buff);
}

static void			read_piece(t_data *data)
{
	int		i;
	char	*buff;

	if(!(buff = (char *)malloc(sizeof(char) * (data->piece_width + 1))))
		ft_error(NULL);
	buff[data->piece_width] = 0;
	i = 0;
	while (i < data->piece_height)
	{
		read(data->fd, buff, data->piece_width);
		ft_seek(data->fd, 1);
		update_piece(data, i, buff);
		i++;
	}
	free(buff);
}

void				map_reader(t_data *data)
{
	char	*buff;

	get_next_line(data->fd, &buff);
	data->player = ((buff[10] == 2) ? 1 : 0);
	free(buff);
	get_next_line(data->fd, &buff);
	data->map_height = ft_atoi(buff + 8);
	data->map_width = ft_atoi(buff + 8 + ft_ndigits(data->map_height));
	free(buff);
	if (!(data->map = ini_mapel(data->map_width, data->map_height)))
		ft_error(NULL);
	read_map(data);
	get_next_line(data->fd, &buff);
	data->piece_height = ft_atoi(buff + 2);
	data->piece_width = ft_atoi(buff + 2 + ft_ndigits(data->piece_height));
	free(buff);
	read_piece(data);
}
