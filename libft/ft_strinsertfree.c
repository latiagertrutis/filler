/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertstrfree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 17:56:16 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/04/26 07:10:05 by mrodrigu         ###   ########.fr       */
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
	return (new);
}
