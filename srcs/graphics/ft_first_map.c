/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 20:22:04 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/01 20:59:51 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char		*take_name(char *line)
{
	line[ft_strlen(line) - 1] = 0;
	return (ft_strrchr(line, '/'));
}

static void		take_dim(char *line, int dim[2])
{
	dim[0] = ft_atoi(ft_strchr(line, ' ') + 1);
	dim[1] = ft_atoi(ft_strrchr(line, ' ') + 1);
}

void	ft_first_map(**params)
{
	char		*line;
	int			flag;
	int			i;
	ft_seek(0, 49 * 5); // saltar cabezera de mapa
	i = 0;
	(*params)->players = (char **)ft_memalloc(sizeof(char *) * 2);
	while ((flag = get_next_line(STDIN_FILEO, &line)) > 0)
	{
		if (flag < 0)
			ft_error(NULL);
		else if (!flag)
			ft_error("Your Filler doesn't work very well");
		if (line[0] == '$')
			(*params)->players[i++] = take_name(line);
		else if (line[0] = 'P')
		{
			take_dim(line, (*params)->dim);
			ft_strdel(&line);
			break ;
		}
		ft_strdel(&line);
	}
	return ;
}
