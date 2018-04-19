/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertstrfree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 17:56:16 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/02/14 04:55:06 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strinsertfree(char *dst, char *str, int pos)
{
	char	*new;

	if (!(new = ft_strnew(ft_strlen(dst) + ft_strlen(str))) || !dst || !str)
		return (NULL);
	ft_strncpy(new, dst, pos);
	ft_strcpy(new + pos, str);
	ft_strcat(new, dst + pos);
	ft_strdel(&dst);
	ft_strdel(&str);
	return(new);
}
