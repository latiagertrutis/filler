# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 17:20:08 by jagarcia          #+#    #+#              #
#    Updated: 2018/05/08 23:27:52 by mrodrigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re graf

NAME = jagarcia.filler

GRAF_NAME = interface

CFLAGS =

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

TEST = srcs/test.c

MAIN_FUNCS = ft_seek.c \
			 ft_ndigits.c \
			 map_reader.c \
			 update_map.c \
			 write_test.c \
			 update_piece.c \
			 ft_roundup.c \
			 put_piece.c \
			 check_position.c \
			 piece_point.c \
			 print_solution.c \
			 cord_piece_to_map.c

GRAPHIC_FUNCS = main_graphic.c \
				ft_print_map.c \
				ft_get_addrs.c \
				ft_initialice.c \
				ft_place_image.c \
				ft_place_starts.c \
				ft_jump_piece.c \
				ft_search_piece.c \
				ft_place_piece.c

OBJ_DIR = objects/
LIBFT_DIR = libft/
MAIN_DIR = srcs/
INCLUDES_DIR = includes/
GRAPHIC_DIR = srcs/graphics/


LIBFT_NAME = libft.a
LIBFT_ABREV = ft
HEADERS = filler.h \
			graphics.h

HEADER_PATH = $(patsubst %.h, $(INCLUDES_DIR)%.h,$(HEADERS))
MAIN_OBJ = $(patsubst %.c, $(OBJ_DIR)%.o,$(MAIN_FUNCS))
GRAPHIC_OBJ = $(patsubst %.c, $(OBJ_DIR)%.o,$(GRAPHIC_FUNCS))

OBJ = $(MAIN_OBJ)


all : $(NAME)

$(NAME) : $(MAIN_OBJ) $(LIBFT_DIR)$(LIBFT_NAME)
	gcc $(OBJ) -L$(LIBFT_DIR) -l$(LIBFT_ABREV) -I$(INCLUDES_DIR) $(FLAGS) -o $(NAME)

$(GRAF_NAME): $(MAIN_OBJ) $(GRAPHIC_OBJ) $(LIBFT_DIR)$(LIBFT_NAME)
	gcc $(MAIN_OBJ) $(GRAPHIC_OBJ) $(MLXFLAGS) -L$(LIBFT_DIR) -l$(LIBFT_ABREV) -I$(INCLUDES_DIR) $(CFLAGS) -o $(GRAF_NAME)

$(LIBFT_DIR)$(LIBFT_NAME):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)%.o : $(MAIN_DIR)%.c $(HEADER_PATH)
	gcc $(CFLAGS) -c -I $(INCLUDES_DIR) $<
	mkdir -p $(OBJ_DIR)
	mv -f $(@F) $(OBJ_DIR)

$(OBJ_DIR)%.o : $(GRAPHIC_DIR)%.c $(HEADER_PATH)
	gcc $(CFLAGS) -c -I $(INCLUDES_DIR) $<
	mkdir -p $(OBJ_DIR)
	mv -f $(@F) $(OBJ_DIR)

clean:
	rm -f $(OBJ_SRC)
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean
	make

graf: $(GRAF_NAME)

test: $(MAIN_OBJ) $(LIBFT_DIR)$(LIBFT_NAME)
	gcc $(CFLAGS) $(TEST) $(MAIN_OBJ) -l$(LIBFT_ABREV) -L$(LIBFT_DIR)
	rm datos.txt
	touch datos.txt
	resources/filler_vm -f resources/maps/map00 -p1 resources/players/carli.filler -p2 ./a.out
