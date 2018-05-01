/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 07:08:13 by jagarcia          #+#    #+#             */
/*   Updated: 2018/05/01 22:50:44 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <mlx.h>

# define MARGEN_X 50
# define MARGEN_Y 100
# define ESC 53

typedef struct	s_params
{
	int			dim[2];
	char		**players;
}				t_params;

typedef struct	s_mlx
{
	void		*ptr;
	void		*win;
	void		*img;
	void		*addrs;
	t_params	*params;
b}				t_mlx;

#endif
