/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_piece.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:28:55 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/12 23:52:55 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		take_pos_player(int piece_pos[2], char *player, char *line)
{
	*player = *(ft_strchr(line, '(') + 1);
	piece_pos[0] = ft_atoi(ft_strchr(line, '[') + 1);
	piece_pos[1] = ft_atoi(ft_strrchr(line, ' ') + 1);
}

int				ft_search_piece(t_mlx *mlx, char *player)
{
	int a;
	char *line;

	a = get_next_line(STDIN_FILENO, &line);
	if (a < 0)
		ft_error(NULL);
	else if (!a)
		return (0);
//	ft_printf("$%s$\n",line);
	if (*line == '<')
	{
//		ft_printf("piece[0] es (%i, %i)\n", mlx->pieces[0]->piece_pos[0], mlx->pieces[0]->piece_pos[1]);
//		ft_printf("piece[1] es (%i, %i)\n", mlx->pieces[1]->piece_pos[0], mlx->pieces[1]->piece_pos[1]);
		((mlx->pieces)[1]->piece_pos)[0] = ((mlx->pieces)[0]->piece_pos)[0];
		((mlx->pieces)[1]->piece_pos)[1] = ((mlx->pieces)[0]->piece_pos)[1];
		take_pos_player(mlx->pieces[0]->piece_pos, player, line);
		ft_strdel(&line);
//		ft_printf("LUEGO piece[0] es (%i, %i)\n", mlx->pieces[0]->piece_pos[0], mlx->pieces[0]->piece_pos[1]);
//		ft_printf("LUEGO piece[1] es (%i, %i)\n", mlx->pieces[1]->piece_pos[0], mlx->pieces[1]->piece_pos[1]);
		return (1);
	}
	ft_strdel(&line);
	return (0);
}
