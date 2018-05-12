/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jagarcia <jagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 07:08:13 by jagarcia          #+#    #+#             */
/*   Updated: 2018/05/11 19:27:45 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <mlx.h>
#include <math.h>

# define MARGEN_X 300
# define MARGEN_Y 100
# define RESOLUTION_X 1920
# define RESOLUTION_Y 1080
# define ESC 53
# define ENDIAN 0
# define BITS 32
# define LINE_COLOR 0xFFFFFF

typedef struct	s_params
{
	int			dim[2];
	char		**players;
	int			square[2];
	int			img_pos[2];
	char		*piece;
	int			piece_dim[2];
}				t_params;

typedef struct	s_mlx
{
	void		*ptr;
	void		*win;
	void		*img;
	void		**bricks;
	t_params	*params;
}				t_mlx;

void	ft_initialice(t_params **params);
void	ft_print_map(t_mlx *mlx);
char	*ft_get_addrs(void *img, int sizeline);
void	ft_place_image(t_mlx *mlx, int img_dim[2]);
int		ft_search_piece(t_mlx *mlx, int piece_pos[2], char *player);
int		ft_jump_piece(t_mlx *mlx);
void	ft_jump_map(int dim[2]);
void	ft_get_piece(t_mlx *mlx, int piece_dim[2]);
void	ft_place_brick(t_mlx *mlx, int row, int col, char player);
void	ft_place_piece(t_mlx *mlx, int piece_pos[2], char player);
void	ft_next_piece(t_mlx *mlx);
void	ft_info(t_mlx *mlx);
#endif
