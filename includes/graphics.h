/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 07:08:13 by jagarcia          #+#    #+#             */
/*   Updated: 2018/05/03 14:56:31 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <mlx.h>

# define MARGEN_X 50
# define MARGEN_Y 100
# define RESOLUTION_X 1366
# define RESOLUTION_Y 768
# define ESC 53
# define ENDIAN 0
# define BITS 32

typedef struct	s_params
{
	int			dim[2];
	char		**players;
	int			square[2];
}				t_params;

typedef struct	s_mlx
{
	void		*ptr;
	void		*win;
	void		*img;
	t_params	*params;
}				t_mlx;

void	ft_initialice(t_params **params);
void	ft_print_map(t_mlx *mlx);
char	*ft_get_addrs(t_mlx *mlx);

#endif
