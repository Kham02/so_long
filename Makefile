# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estrong <estrong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 13:59:17 by estrong           #+#    #+#              #
#    Updated: 2022/04/18 18:43:13 by estrong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

OBJ		=	so_long.c	draw_map.c	end_game.c	map_valid.c	mobile_objects.c	mov.c	get_next_line.c	get_next_line_utils.c \
			mini_draw.c

SRCS	=	$(patsubst %.c,%.o,$(OBJ))

HEADER	=	so_long.h

LFT		=	Libft

# INC		=	-I ./inc -I ./Libft -I ./mlx

# LIB		=	-L Libft/libft.a -lft -L ./mlx -lmlx -lXext -lX11 -lm -lbsd

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror -I$(HEADER)

.PHONY :	all clean fclean re

all :	$(NAME)

$(NAME):	$(OBJ) $(HEADER)
	$(MAKE) -C ./Libft
	# $(CC) -c ${FLAGS} ${OBJ} -I Libft/libft.a
	$(CC) -lmlx -framework OpenGL -framework AppKit $(FLAGS) $(OBJ) Libft/libft.a -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean :
	@make clean -C $(LFT)
			rm -rf $(SRCS)

fclean :
	@make fclean -C $(LFT)
			rm -rf $(NAME)

re :		fclean all
