/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 17:56:16 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/02/14 03:19:25 by jagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strinsert(char *dst, char *str, int pos)
{
	char	*new;

	if (!(new = ft_strnew(ft_strlen(dst) + ft_strlen(str))) || !dst || !str)
		return (NULL);
	ft_strncpy(new, dst, pos);
	ft_strcpy(new + pos, str);
	ft_strcat(new, dst + pos);
	return(new);
}
