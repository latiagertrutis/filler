/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_piece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 22:20:28 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/08 23:32:02 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	seek2(int fd, int cuant)
{
	char *buff;
	int	flag;
	int realcuant;

	realcuant = cuant;
	if (!(buff = (char *)ft_memalloc(sizeof(char) * cuant)))
		ft_error(NULL);
	while (cuant)
	{
		if ((flag = read(fd, buff, cuant)) < 0)
			ft_error(NULL);
		else if (!flag)
			return ;
		buff[cuant] = 0;
		//	ft_printf("<%s>\n",buff);
		ft_bzero(buff, realcuant);
		cuant -= flag;
	}
	free(buff);
}

static void		jump_map(int dim[2])
{
	int map;
	int plateau;

	plateau = ft_ndigits(dim[0]) + ft_ndigits(dim[1]) + 11;
	plateau = 0;
	map = (dim[0] + 1) * (dim[1] + 5);
	if (dim[0] > 1000)
		map += dim[0] - 1000;
	
	seek2(STDIN_FILENO, map + plateau);
}

void	ft_next_piece(t_mlx *mlx)
{
	if (!ft_jump_piece(mlx))
	{
		jump_map(mlx->params->dim);
		ft_jump_piece(mlx);
	}
}
