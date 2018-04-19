/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_failure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 04:29:35 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/03/04 05:32:28 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	exit_failure(char *motive)
{
	ft_putstr("\033[1;91mERROR: ");
	if (motive)
		ft_putstr(motive);
	else
		ft_putstr(strerror(errno));
	ft_putstr("\033[0\n");
	exit(0);
}
