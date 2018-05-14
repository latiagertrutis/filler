/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_piece.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:28:55 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/14 19:54:40 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		take_pos_player(int piece_pos[2], char *player, char *line)
{
	*player = *(ft_strchr(line, '(') + 1);
	piece_pos[0] = ft_atoi(ft_strchr(line, '[') + 1);
	piece_pos[1] = ft_atoi(ft_strrchr(line, ' ') + 1);
}

void			ft_search_piece(t_mlx *mlx)
{
	int		a;
	char	*line;

	a = get_next_line(STDIN_FILENO, &line);
	if (a < 0)
		ft_error(NULL);
	else if (!a)
		ft_error("LEIDO MAL EN SEARCH\n");
	if (line[0] == '<')
	{
		take_pos_player(mlx->pieces[0]->piece_pos, &(mlx->pieces[0]->player), line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
}
