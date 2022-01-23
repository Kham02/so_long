# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estrong <estrong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 13:59:17 by estrong           #+#    #+#              #
#    Updated: 2022/01/23 19:34:47 by estrong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

OBJ		=	so_long.c	draw_map.c	end_game.c	map_valid.c	mobile_objects.c	mov.c

SRCS	=	$(patsubst %.c,%.o,$(OBJ))

HEADER	=	so_long.h

LFT		=	libft

INC		=	-I ./inc -I ./libft -I ./mlx

LIB		=	-L ./libft -lft -L ./mlx -lmlx -lXext -lX11 -lm -lbsd

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror -I$(HEADER)

.PHONY :	all clean fclean re

all :	$(NAME)

$(NAME):	$(OBJ) $(HEADER)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean :
	@make clean -C $(LFT)#
			rm -rf $(SRCS)

fclean :
	@make fclean -C $(LFT)#
			rm -rf $(NAME)

re :		fclean all
