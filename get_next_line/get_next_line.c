/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 21:26:55 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/03/01 00:41:44 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static int		check_line(char *buff, size_t size)
{
	size_t i;

	i = 0;
	while (buff[i] && buff[i] != END_OF_LINE && i < size)
		i++;
	if (i == size)
		return (-1);
	return (i);
}

static int		read_file(int fd, char *buff, char **line, char **lines)
{
	int	rd;

	if (!(rd = read(fd, buff, BUFF_SIZE)))
	{
		ft_strdel(&(lines[fd]));
		if (**line)
			return (1);
	}
	return (rd);
}

static int		read_line(char **lines, int fd, char **line)
{
	char	buff[BUFF_SIZE + 1];
	int		rd;
	char	*aux;
	int		pos;

	while (1)
	{
		ft_memset(buff, 0, BUFF_SIZE + 1);
		if ((rd = read_file(fd, buff, line, lines)) <= 0)
			return (rd);
		if ((pos = check_line(buff, BUFF_SIZE)) >= 0)
		{
			aux = ft_strnjoin(*line, buff, pos);
			ft_strdel(line);
			*line = aux;
			if (buff[pos + 1])
				lines[fd] = ft_strsub(buff, pos + 1, rd - pos - 1);
			return ((*line) ? 1 : -1);
		}
		aux = ft_strjoin(*line, buff);
		ft_strdel(line);
		*line = aux;
	}
	return (-1);
}

int				get_next_line(const int fd, char **line)
{
	static char		*lines[FD_SETSIZE] = {0};
	int				pos;
	char			*aux;

	if (fd >= FD_SETSIZE || fd < 0 || !line || !(*line = ft_strnew(0)))
		return (-1);
	if (lines[fd])
	{
		if ((pos = check_line(lines[fd], ft_strlen(lines[fd]))) >= 0)
		{
			aux = ft_strnjoin(*line, lines[fd], pos);
			ft_strdel(line);
			*line = aux;
			aux = ft_strsub(lines[fd], pos + 1, ft_strlen(lines[fd]) - pos - 1);
			ft_strdel(&(lines[fd]));
			lines[fd] = aux;
			return ((*line) ? 1 : -1);
		}
		aux = ft_strjoin(*line, lines[fd]);
		ft_strdel(line);
		*line = aux;
		ft_strdel(&(lines[fd]));
	}
	return (read_line(lines, fd, line));
}
