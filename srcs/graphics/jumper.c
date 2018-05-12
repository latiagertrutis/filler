/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jumper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 18:31:17 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/12 23:38:01 by mrodrigu         ###   ########.fr       */
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
//		ft_printf("<%s>",buff);
		ft_bzero(buff, realcuant);
		cuant -= flag;
	}
	free(buff);
}

void			ft_jump_map(int dim[2])
{
	int map;

	map = (dim[0] + 1) * (dim[1] + 5);
	if (dim[0] > 1000)
		map += dim[0] - 1000;
	seek2(STDIN_FILENO, map);
}

static int		size_array(t_piece *pieces)
{
	int a;

	a = (pieces->piece_dim[0] * pieces->piece_dim[1]) / 8 +
	        ((pieces->piece_dim[0] * pieces->piece_dim[1]) % 8 ? 1 : 0);
//	ft_printf("a vale %i\n", a);
	return (a);
}

int				ft_jump_piece(t_mlx *mlx)
{
	int		a;
	char	*line;

	a = get_next_line(STDIN_FILENO, &line);
	if (a < 0)
		ft_error(NULL);
	else if (!a)
		ft_error("ERROR\n");
//	ft_printf("[%s]\n",line);
	if (*(line + 1) == 'l')
	{
//		ft_putstr("PLATEAU\n");
		return (0);
	}
	else if (*line == '=')
		return (-1);
	mlx->pieces[1]->piece_dim[0] = mlx->pieces[0]->piece_dim[0];
	mlx->pieces[1]->piece_dim[1] = mlx->pieces[0]->piece_dim[1];
	mlx->pieces[0]->piece_dim[0] = ft_atoi(ft_strchr(line, ' ') + 1);
	mlx->pieces[0]->piece_dim[1] = ft_atoi(ft_strrchr(line, ' ') + 1);
	int b;

	b = (mlx->pieces[0]->piece_dim[0] * mlx->pieces[0]->piece_dim[1]) / 8 +
	        ((mlx->pieces[0]->piece_dim[0] * mlx->pieces[0]->piece_dim[1]) % 8 ? 1 : 0);
	if (b < 0)
	{
		
//		ft_printf("ERROR pieza de tamanyo [%i , %i]\n line = <%s>\n", mlx->pieces[0]->piece_dim[0], mlx->pieces[0]->piece_dim[0], line);
	}
//	ft_printf("a vale %i\n", b);
	free(line);
//	if (mlx->pieces[1]->piece)
//	{
	//	ft_putchar('A');
		ft_strdel(&(mlx->pieces[1]->piece));
		mlx->pieces[1]->piece = mlx->pieces[0]->piece;
		mlx->pieces[1]->piece = ft_strnew(size_array(mlx->pieces[1]));
		ft_memcpy(mlx->pieces[1]->piece, mlx->pieces[0]->piece, size_array(mlx->pieces[1]));
// 	}
	ft_strdel(&(mlx->pieces[0]->piece));
	mlx->pieces[0]->piece = ft_strnew(size_array(mlx->pieces[0]));
	ft_get_piece(mlx, mlx->pieces[0]->piece_dim);
	return (1);
}
