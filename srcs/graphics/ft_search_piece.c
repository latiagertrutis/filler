/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_piece.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:28:55 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/07 23:44:33 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		take_pos_player(int piece_pos[2], char *player, char *line)
{
	*player = *(ft_strchr(line, '(') + 1);
	piece_pos[0] = ft_atoi(ft_strchr(line, '[') + 1);
	piece_pos[1] = ft_atoi(ft_strrchr(line, ' ') + 1);
}

static void		jump_map(int dim[2])
{
	int plateau;
	int map;
	
	plateau = 8 + ft_ndigits(dim[0]) + ft_ndigits(dim[1]) + 3;
	plateau = 0;
	map = (dim[0] + 1) * (dim[1] + 5);
	if (dim[0] > 1000)
		map += dim[0] - 1000;
	ft_seek(STDIN_FILENO, plateau + map);
}

int				ft_search_piece(t_mlx *mlx, int piece_pos[2], char *player)
{
	int a;
	char *line;

	a = get_next_line(STDIN_FILENO, &line);
	if (a < 0)
		ft_error(NULL);
	else if (!a)
		return (0);
	if (*line == '<')
	{
		ft_printf("%s\n", line);
		take_pos_player(piece_pos, player, line);
		if (piece_pos[0] == 0 && piece_pos[1] == 0)
			return (0);
		jump_map(mlx->params->dim);
		ft_jump_piece();
		return (1);
	}
	ft_strdel(&line);
	return (0);
}
