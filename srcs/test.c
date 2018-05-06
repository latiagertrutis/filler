/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 20:36:39 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/07 00:07:49 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int 	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int		ret;
	t_data	data = {0, 0, 0, 0, 0, 0, NULL, NULL, 0};
//	remove("datos.txt");
	while ((ret = map_reader(&data)))
	{
		if (ret == 1)
		{
			put_piece(&data);
		}
		if (ret == 2)
			continue ;
	}
	return (0);
}
