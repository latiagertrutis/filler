/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 02:48:17 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/04/20 23:36:30 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_point	*locate_point(t_point *coord, char *line, int n, int i)
{
	t_point	*aux;
	int		j;

	if (!coord)
		aux = NULL;
	else
		aux = coord;
	j = 0;
	while (j < n)
	{
		if (!(coord = (t_point *)ft_memalloc(sizeof(t_point))))
			return (NULL);
		coord->x = i;
		coord->y = j;
		coord->z = ft_atoi(line);
		coord->next = aux;
		aux = coord;
		while (*line == ' ' && *line)
			line++;
		while ((ft_isdigit(*line) || *line == '-') && *line)
			line++;
		j++;
	}
	return (coord);
}

static int		check_line(char *line)
{
	int		n;

	n = 0;
	while (*line)
	{
		if (ft_isdigit(*line))
		{
			n++;
			while (ft_isdigit(*line) && *line)
				line++;
		}
		if (*line == ' ')
		{
			while (*line == ' ' && *line)
				line++;
		}
		else if (*line == '-' && ft_isdigit(*(line + 1)))
			line++;
		else
			return ((*line) ? -1 : n);
	}
	return (n);
}

static t_point	*put_header(t_point *coord)
{
	t_point	*aux;

	aux = coord;
	if (!(coord = (t_point *)ft_memalloc(sizeof(t_point))))
		exit_failure(NULL);
	coord->x = aux->x;
	coord->y = aux->y;
	coord->z = aux->z;
	coord->next = aux;
	return (coord);
}

t_point			*input_reader(char *file)
{
	int		fd;
	char	*line;
	t_point	*coord;
	int		n;
	int		i;

	i = 0;
	n = 0;
	coord = NULL;
	if ((fd = open(file, O_RDONLY)) < 0)
		exit_failure(NULL);
	while ((get_next_line(fd, &line)) > 0)
	{
		if (!line || (n = check_line(line)) < 0)
			exit_failure(NULL);
		coord = locate_point(coord, line, n, i++);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	coord = put_header(coord);
	return (coord);
}
