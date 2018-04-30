# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 17:20:08 by jagarcia          #+#    #+#              #
#    Updated: 2018/04/30 16:30:31 by mrodrigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re graf

NAME = jagarcia.filler

GRAF_NAME = interface

CFLAGS = -Wall -Wextra -Werror

MAIN_FUNCS = ft_seek.c

GRAPHIC_FUNCS = main_graphic.c

OBJ_DIR = objects/
LIBFT_DIR = ./libft/
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
	gcc $(MAIN_OBJ) $(GRAPHIC_OBJ) -L$(LIBFT_DIR) -l$(LIBFT_ABREV) -I$(INCLUDES_DIR) $(FLAGS) -o $(GRAF_NAME)

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
