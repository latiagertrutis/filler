/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seek.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 13:09:54 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/07 22:30:27 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_seek(int fd, int cuant)
{
	char *buff;
	int	flag;
	int i;
	
	if (!(buff = (char *)ft_memalloc(sizeof(char) * cuant)))
		ft_error(NULL);
	i = 0;
	while (i < cuant)
	{
		if ((flag = read(fd, buff, cuant)) < 0)
			ft_error(NULL);
		else if (!flag)
			return ;
		i += flag;
	}
	free(buff);
}
