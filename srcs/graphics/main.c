/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 22:41:08 by jagarcia          #+#    #+#             */
/*   Updated: 2018/04/30 07:43:13 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

int		main(int argn, char **argv)
{
	char *line;
	
	while (get_next_line(0, &line))
	{
		ft_putstr(line);
		ft_putchar('\n');
		ft_strdel(&line);
	}
	return (0);
}
