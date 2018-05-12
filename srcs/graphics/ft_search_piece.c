/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_piece.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:28:55 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/11 16:34:00 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		take_pos_player(int piece_pos[2], char *player, char *line)
{
	*player = *(ft_strchr(line, '(') + 1);
	piece_pos[0] = ft_atoi(ft_strchr(line, '[') + 1);
	piece_pos[1] = ft_atoi(ft_strrchr(line, ' ') + 1);
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
		take_pos_player(piece_pos, player, line);
		ft_strdel(&line);
		return (1);
	}
	ft_strdel(&line);
	return (0);
}
