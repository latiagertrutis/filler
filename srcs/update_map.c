/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 20:11:57 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/02 20:11:39 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	update_map(t_data *data, int i, char *buff)
{
	int j;
	(void)i;

	write_test(buff);
	write_test("\n");
	j = 0;
	while (j < data->map_width)
	{
		j++;
	}
}
