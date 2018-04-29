# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jagarcia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 17:20:08 by jagarcia          #+#    #+#              #
#    Updated: 2018/04/29 14:23:21 by mrodrigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : man norme all clean fclean re

NAME = jagarcia.filler

CFLAGS = -Wall -Wextra -Werror

MAIN_FUNCS = 


LIBFT_NAME = libft.a
LIBFT_ABREV = ft
LIBFT_DIR = ./libft/


HEADERS = fdf.h
INCLUDES_DIR = includes/
HEADER_PATH = $(patsubst %.h, $(INCLUDES_DIR)%.h, $(HEADERS))


MAIN_DIR = srcs/
MAIN_OBJ = $(patsubst %.c, $(OBJ_DIR)%.o,$(MAIN_FUNCS))


OBJ_DIR = objects/
OBJ = $(MAIN_OBJ)


all : $(NAME)

$(NAME) : $(MAINS_OBJ) $(LIBFT_DIR)$(LIBFT_NAME)
	gcc $(OBJ) -L $(LIBFT_DIR) -l$(LIBFT_ABREV) -lftprintf -I $(INCLUDES_DIR) $(FLAGS) -o $(NAME)

$(LIBFT_DIR)$(LIBFT_NAME):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)%.o : $(MAINS_DIR)%.c $(HEADER_PATH)
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
