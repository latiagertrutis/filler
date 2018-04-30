/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_graphic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 22:41:08 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/30 19:35:54 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	char *line;
//	char buffer[1];
	
	ft_seek(STDIN_FILENO, 49 * 5);
	while (get_next_line(STDIN_FILENO, &line))
	{
		ft_putchar('A');
		ft_putstr(line);
		ft_putchar('A');
		ft_putchar('\n');
		ft_strdel(&line);
	}
	return (0);
}
