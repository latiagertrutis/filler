/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 21:31:25 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/02/26 19:34:03 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../srcs/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE 1000
# define END_OF_LINE '\n'

int				get_next_line(const int fd, char **line);

#endif
