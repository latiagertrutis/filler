/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 11:58:02 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/07 19:49:47 by mrodrigu         ###   ########.fr       */
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
	ft_seek(data->fd, data->map_width + 4);
	while (i < data->map_height)
	{
		ft_seek(data->fd, 5);
		read(data->fd, buff, data->map_width);
		update_map(data, i, buff);
		i++;
	}
		ft_seek(data->fd, 1);
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

int					map_reader(t_data *data)
{
	char	*buff;

	if (get_next_line(data->fd, &buff) < 0)
		return (0);
	if (!buff)
		return (2);
	if (!data->map_width || !data->map_height)
	{
		data->map_height = ft_atoi(buff + 8);
		data->map_width = ft_atoi(buff + 8 + ft_ndigits(data->map_height));
		if (!(data->map = ini_mapel(data->map_width, data->map_height)))
			ft_error(NULL);
	}
//		write_test("#\n");
//		write_test(buff);
//		write_test("\n#\n");
	free(buff);
	read_map(data);
	get_next_line(data->fd, &buff);
		write_test(buff);
		write_test("\n");
	data->piece_height = ft_atoi(buff + 6);
	data->piece_width = ft_atoi(buff + 6 + ft_ndigits(data->piece_height));
	free(buff);
	if (!(data->piece = (char *)ft_memalloc(sizeof(char) *
		ft_roundup((double)(data->piece_width * data->piece_height) / 8.0))))
		ft_error(NULL);
	write_test("&");
	write_test(ft_itoa(data->piece_height));
	write_test(", ");
	write_test(ft_itoa(data->piece_width));
	write_test("&\n");
	read_piece(data);
/*	int i = 0;
	int j = 0;
	while (i < ft_roundup((double)(data->piece_width * data->piece_height) / 8.0))
	{
		j = 0;
		while (j < 8)
		{
			if (!((j) % data->piece_width))
				write_test("\n");
			if (data->piece[i] & (0x80 >> j))
				write_test("*");
			else
				write_test(".");
			j++;
		}
		i++;
	}
	write_test("\n");*/
	return (1);
}
