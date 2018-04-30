/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_graphic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 22:41:08 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/30 18:11:30 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	char *line;
	
	ft_seek(STDOUT_FILENO, 1);
	ft_seek(STDOUT_FILENO, 1);
	ft_seek(STDOUT_FILENO, 1);
	ft_seek(STDOUT_FILENO, 1);
	ft_seek(STDOUT_FILENO, 1);
	while (get_next_line(STDOUT_FILENO, &line))
	{
		ft_putchar('A');
		ft_putstr(line);
		ft_putchar('A');
		ft_putchar('\n');
		ft_strdel(&line);
	}
	return (0);
}
