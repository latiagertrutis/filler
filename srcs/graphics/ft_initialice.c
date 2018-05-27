/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialice.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 20:22:04 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/27 03:52:03 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char		*take_name(char *line)
{
	char *name;

	line[ft_strlen(line) - 1] = 0;
	name = ft_strdup(ft_strrchr(line, '/') + 1);
	return (name);
}

static void		take_dim(char *line, int dim[2], int square[2])
{
	dim[0] = ft_atoi(ft_strchr(line, ' ') + 1);
	dim[1] = ft_atoi(ft_strrchr(line, ' ') + 1);
	square[0] = (RESOLUTION_Y - MARGEN_Y * 2) / dim[0];
	square[1] = (RESOLUTION_X - MARGEN_X * 2) / dim[1];
}

static void		allocate_data(t_mlx *mlx)
{
	mlx->map = (t_map *)ft_memalloc(sizeof(t_map));
	mlx->map->players = (char **)ft_memalloc(sizeof(char *) * 2);
	mlx->piece = (t_piece **)ft_memalloc(sizeof(t_piece *) * 2);
	(mlx->piece)[0] = (t_piece *)ft_memalloc(sizeof(t_piece));
	(mlx->piece)[1] = (t_piece *)ft_memalloc(sizeof(t_piece));
	mlx->piece[1]->shape = NULL;
	mlx->info = (void **)ft_memalloc(sizeof(void *) * 2);
	if (!(mlx->info[0] = mlx_new_image(mlx->ptr, MARGEN_X, 20)))
		ft_error(NULL);
	if (!(mlx->info[1] = mlx_new_image(mlx->ptr, MARGEN_X, 20)))
		ft_error(NULL);
}

void			ft_initialice(t_mlx *mlx)
{
	char		*line;
	int			flag;
	int			i;

	allocate_data(mlx);
	ft_seek(0, 49 * 5);
	i = 0;
	while ((flag = get_next_line(STDIN_FILENO, &line)))
	{
		if (flag < 0)
			ft_error(NULL);
		if (line[0] == '$')
			mlx->map->players[i++] = take_name(line);
		else if (line[0] == 'P')
		{
			take_dim(line, mlx->map->dim, mlx->map->square);
			free(line);
			break ;
		}
		free(line);
	}
	if (!flag)
		ft_error("ERROR Bad Map\n");
	return ;
}
