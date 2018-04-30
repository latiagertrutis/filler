/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seek.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 13:09:54 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/04/30 19:37:24 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_seek(int fd, int cuant)
{
	char *buff;
	int	a;
	
	if (!(buff = (char *)malloc(sizeof(char) * cuant)))
		ft_error(NULL);
//	if ((a = read(fd, buff, cuant)) < 0)
//		ft_error(NULL);
//	ft_printf("a = %i\n", a);

	while ((a = read(fd, buff, cuant)) > 0 && a < cuant)
	{
		if (a < 0)
			ft_error(NULL);
		cuant -= a;
	}
	
	
	free(buff);
}
