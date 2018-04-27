/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 11:55:00 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/04/27 11:59:12 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

typedef struct	s_mapel
{
	unsigned int is_x : 1;
	unsigned int is_o : 1;
	unsigned int is_n : 1;
}				t_mapel;

#endif
