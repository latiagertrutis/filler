/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seek.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 13:09:54 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/04/30 17:10:00 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_seek(int fd, int cuant)
{
	char *buff;

	if (!(buff = (char *)malloc(sizeof(char) * cuant)))
		ft_error(NULL);
	if (read(fd, buff, cuant) < 0)
		ft_error(NULL);
	free(buff);
}
