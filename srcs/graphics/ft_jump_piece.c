/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jump_piece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 19:21:23 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/08 22:37:39 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	ft_jump_piece(t_mlx *mlx)
{
	int		a;
	char	*line;

	a = get_next_line(STDIN_FILENO, &line);
	if (a < 0)
		ft_error(NULL);
	else if (!a)
		ft_error("ERROR\n");
	if (*(line + 1) == 'l')
		return (0);
	mlx->params->piece_dim[0] = ft_atoi(ft_strchr(line, ' ') + 1);
	mlx->params->piece_dim[1] = ft_atoi(ft_strrchr(line, ' ') + 1);
	free(line);
	ft_strdel(&mlx->params->piece);
	mlx->params->piece = ft_strnew((mlx->params->piece_dim[0] *
		mlx->params->piece_dim[1]) / 8 + ((mlx->params->piece_dim[0] *
		mlx->params->piece_dim[1]) % 8 ? 1 : 0));
	ft_get_piece(mlx, mlx->params->piece_dim);
	return (1);
}
