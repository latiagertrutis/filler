/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 20:36:39 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/01 22:26:30 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int 	main(int argc, char **argv)
{
	(void)argc;

	int i;
	char *buff = NULL;
	t_data	data;

	if ((data.fd = open(argv[1], O_RDONLY)) < 0)
		ft_error(NULL);
	i = 0;
	while (i < 10)
	{
		if (buff)
			free(buff);
		get_next_line(data.fd, &buff);
		i++;
	}
	data.map_height = ft_atoi(buff + 8);
	data.map_width = ft_atoi(buff + 8 + ft_ndigits(data.map_height));
	free (buff);
	map_reader(&data);
	return (0);
}
