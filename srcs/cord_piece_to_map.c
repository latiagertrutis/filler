/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cord_piece_to_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 22:01:22 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/08 22:12:34 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		cord_piece_to_map(int p_width, int m_width, int mp, int pp, int p)
{
	return (mp + (((p / p_width) - (pp / p_width)) * m_width) + ((p % p_width) - (pp % p_width)));
}
