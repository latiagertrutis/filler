/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 11:55:00 by mrodrigu          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/04/30 16:00:49 by mrodrigu         ###   ########.fr       */
=======
/*   Updated: 2018/04/30 15:46:12 by mrodrigu         ###   ########.fr       */
>>>>>>> ba49a31da18c3d40a1316a1c8ce8a252b0cbac75
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include <unistd.h>
#include <stdlib.h>
#include "../libft/includes/libft.h"
#include "graphics.h"

typedef struct		s_mapel
{
	unsigned int	is_x : 1;
	unsigned int	is_o : 1;
	unsigned int	is_n : 1;
}					t_mapel;

typedef struct		s_data
{
	int				fd;
	int				map_width;
	int				map_height;
	t_mapel			*map;
}					t_data;
void		ft_seek(int fd, int cuant);
void		*map_reader(void);
int			get_next_line(const int fd, char **line);
int			ndigits(int n);
#endif
