/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 20:43:35 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/12 23:32:30 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	put_element(t_mlx *mlx, int i, int j, int piece_dim[2])
{
	int		aux;

	aux = ((i * piece_dim[1]) + j) / 8;
	mlx->pieces[0]->piece[aux] = mlx->pieces[0]->piece[aux] |
		(0x80 >> (((i * piece_dim[1]) + j) % 8));
}

void		ft_get_piece(t_mlx *mlx, int piece_dim[2])
{
	int		j;
	int		flag;
	char	*line;
	int		i;
	
	i = 0;
	while (i < piece_dim[0])
	{
//	ft_printf("pieza de dimensioens %i y %i\n", piece_dim[0], piece_dim[1]);
		line = ft_strnew(piece_dim[1] + 1);
		j = 0;
		if ((flag = read(STDIN_FILENO, line, piece_dim[1] + 1)) < 0)
			ft_error(NULL);
		if (!flag)
			ft_error("Where is the piece?\n");
		line[piece_dim[1]] = 0;
//		ft_printf("LA PIEZA ES @%s@\n",line);
			//		ft_printf("fila %i pieza <%s>\n", i , line);
		while (j < piece_dim[1])
		{
			if (line[j] == '*')
				put_element(mlx, i, j, piece_dim);
			j++;
		}
		free(line);
		i++;
	}
}
