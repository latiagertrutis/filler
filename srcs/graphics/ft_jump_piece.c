/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jump_piece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 19:21:23 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/07 23:28:00 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	seek2(int fd, int cuant)
{
	char *buff;
	int	a;
	int flag;
	
	flag = 0;
	ft_printf("cuant = %i\n", cuant);
	while (flag < cuant)
	{
	if (!(buff = (char *)ft_memalloc(sizeof(char) * cuant + 1)))
		ft_error(NULL);

		a = read(fd, buff, cuant);
		if (a < 0)
			ft_error(NULL);
		if (a == 0)
			ft_error("TA VACIO");
		buff[cuant] = 0;
		ft_printf("<%s>\n",buff);
		flag += a;
		ft_strdel(&buff);
	}
//	free(buff);
}

void	ft_jump_piece(void)
{
	int		a;
	char	*line;
	int		piece_dim[2];

	a = get_next_line(STDIN_FILENO, &line);
	if (a < 0)
		ft_error(NULL);
	else if (!a)
		ft_error("ERROR\n");
	piece_dim[0] = ft_atoi(ft_strchr(line, ' ') + 1);
	piece_dim[1] = ft_atoi(ft_strrchr(line, ' ') + 1);
	ft_seek(STDIN_FILENO, piece_dim[0] * piece_dim[1] + 1);
	free(line);
	return ;
}
