/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 20:36:39 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/12 14:51:24 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int		ini_player(t_data *data)
{
	char	*buff;

	if (get_next_line(data->fd, &buff) < 0)
		return (1);
	data->player = ((buff[10] == '2') ? 1 : 0);
	return (0);
}
int 			main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int		ret;
	t_data	data = {0, 0, 0, 0, 0, 0, -1, 0, 0, 0, NULL, NULL, NULL};
	if (ini_player(&data))
		return(0);
	while ((ret = map_reader(&data)))
	{
		if (ret == 1)
		{
			if (!put_piece(&data))
				return(0);
		}
		if (ret == 2)
			continue ;
	}
	return (0);
}
