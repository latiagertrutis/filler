# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 17:20:08 by jagarcia          #+#    #+#              #
#    Updated: 2018/04/29 22:38:25 by jagarcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : man norme all clean fclean re

NAME = interface

UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	FLAGS = -lm -L/usr/lib/X11 -lmlx -lXext -lX11
else
	FLAGS = -lmlx -framework OpenGL -framework AppKit
endif

CFLAGS = -Wall -Wextra -Werror

MAIN_FUNCS = 


MAINS_DIR = srcs/
MAINS_OBJ = $(patsubst %.c, $(OBJ_DIR)%.o,$(MAIN_FUNCS))


LIBFT_NAME = /libft.a
LIBFT_ABREV = ft
LIBFT_DIR = ../libft


INCLUDES_DIR = includes/
INCLUDES_MLX = /usr/local/include
HEADERS = graphics.h


OBJ_DIR = ../objects/
OBJ = $(MAINS_OBJ)

all : $(NAME)

$(NAME) : $(MAINS_OBJ) $(LIBFT_DIR)$(LIBFT_NAME)
	gcc $(OBJ) -L $(LIBFT_DIR) -l$(LIBFT_ABREV) -I $(INCLUDES_DIR) $(FLAGS) -o $(NAME)

$(LIBFT_DIR)$(LIBFT_NAME):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)%.o : $(MAINS_DIR)%.c $(INCLUDES_DIR)$(HEADERS)
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
