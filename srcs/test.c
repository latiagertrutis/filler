/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 20:36:39 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/03 15:56:23 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int 	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_data	data = {0, 0, 0, 0, 0, 0, NULL, NULL};

//	remove("datos.txt");
	map_reader(&data);
	return (0);
}
