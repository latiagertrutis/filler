/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   success.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 04:38:59 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/03/04 04:42:19 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	success(char *message)
{
	ft_putstr("\033[1;92mSUCCESS");
	if (message)
	{
		ft_putstr(": ");
		ft_putstr(message);
	}
	ft_putstr("\033[0m\n");
}
