/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 11:55:00 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/05/04 17:35:32 by mrodrigu         ###   ########.fr       */
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
}					t_mapel;

typedef struct		s_data
{
	int				fd;
	int				map_width;
	int				map_height;
	int				piece_width;
	int				piece_height;
	int				player : 1;
	t_mapel			*map;
	char			*piece;
}					t_data;

void		ft_seek(int fd, int cuant);
void		map_reader(t_data *data);
int			ft_ndigits(int n);
void		update_map(t_data *data, int i, char *buff);
void		update_piece(t_data *data, int i, char *buff);
void 		write_test(char *str);
int			ft_roundup(double d);
int			put_piece(t_data *data);
int			check_position(t_data *data, int i, int pp);
int			piece_point(t_data *data);

#endif
