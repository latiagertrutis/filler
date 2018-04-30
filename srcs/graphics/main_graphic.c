/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_graphic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 22:41:08 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/30 20:27:48 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	char	*line;
	int		dim[2];
	
	ft_seek(STDIN_FILENO, 49 * 5);
	if (get_next_line(STDIN_FILENO, &line) < 0)
		ft_error(NULL);
	dim[0] = ft_
	while (get_next_line(STDIN_FILENO, &line))
	{
		ft_putchar('<');
		ft_putstr(line);
		ft_putchar('>');
		ft_putchar('\n');
		ft_strdel(&line);
	}
	return (0);
}
