/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialice.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 20:22:04 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/12 21:29:24 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char		*take_name(char *line)
{
	char *name;
	
	line[ft_strlen(line) - 1] = 0;
	name = ft_strdup(ft_strrchr(line, '/') + 1);
	name[ft_strlen(name) - 1] = 0;
	return (name);
}

static void		take_dim(char *line, int dim[2], int square[2])
{
	dim[0] = ft_atoi(ft_strchr(line, ' ') + 1);
	dim[1] = ft_atoi(ft_strrchr(line, ' ') + 1);
	square[0] = (RESOLUTION_Y - MARGEN_Y * 2) / dim[0];
	square[1] = (RESOLUTION_X - MARGEN_X * 2) / dim[1];
}

void			ft_initialice(t_mlx *mlx)
{
	char		*line;
	int			flag;
	int			i;
	t_params	*par;
	
	ft_seek(0, 49 * 5);
	i = 0;
	mlx->params = (t_params *)ft_memalloc(sizeof(t_params));
	mlx->params->players = (char **)ft_memalloc(sizeof(char *) * 2);
	mlx->pieces = (t_piece **)ft_memalloc(sizeof(t_piece *) * 2);
	(mlx->pieces)[0] = (t_piece *)ft_memalloc(sizeof(t_piece));
	(mlx->pieces)[1] = (t_piece *)ft_memalloc(sizeof(t_piece));
	par = mlx->params;
	while ((flag = get_next_line(STDIN_FILENO ,&line)) > 0)
	{
		if (flag < 0)
			ft_error(NULL);
		else if (!flag)
			ft_error("Your Filler doesn't work very well");
		if (line[0] == '$')
			par->players[i++] = take_name(line);
		else if (line[0] == 'P')
		{
			take_dim(line, par->dim, par->square);
			ft_strdel(&line);
			break ;
		}
		ft_strdel(&line);
	}
	return ;
}
