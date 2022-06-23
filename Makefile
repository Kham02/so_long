# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estrong <estrong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 13:59:17 by estrong           #+#    #+#              #
#    Updated: 2022/06/18 14:28:20 by estrong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

NAME_B	=	so_long_bonus

SRCS	=	main.c	draw_map.c	end_game.c	map_valid.c	mobile_objects.c	mov.c	get_next_line.c	get_next_line_utils.c \
			mini_draw.c

SRCS_B	=	main_bonus.c	init_bonus.c	destroy_bonus.c	images_bonus.c	map_bonus.c	mp_update_bonus.c	\
			window_bonus.c	enemy_bonus.c	animation_bonus.c	mov_down_bonus.c	mov_left_bonus.c	\
			mov_up_bonus.c	mov_right_bonus.c	mov_utils_bonus.c

OBJ	=	$(patsubst %.c,%.o,$(SRCS))
OBJ	=	$(patsubst %.c,%.o,$(SRCS_B))

HEADER	=	../hdrs/so_long.h
HEADER_B	=	../hdrs/so_long_bonus.h

LFT		=	../Libft

# INC		=	-I ./inc -I ./Libft -I ./mlx

# LIB		=	-L Libft/libft.a -lft -L ./mlx -lmlx -lXext -lX11 -lm -lbsd

CC		=	cc

FLAGS	=	-Wall -Wextra -Werror -I$(HEADER)

.PHONY :	all clean fclean re bonus

all :	$(NAME)

$(NAME):	$(SRCS) $(HEADER)
	$(MAKE) -C .././Libft
	# $(CC) -c ${FLAGS} ${SRCS} -I ../Libft/libft.a
	$(CC) -lmlx -framework OpenGL -framework AppKit $(FLAGS) $(SRCS) ../Libft/libft.a -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

.bonus	:	$(OBJ_B)
	

clean :
	@make clean -C $(LFT)
			rm -rf $(OBJ)

fclean :
	@make fclean -C $(LFT)
			rm -rf $(NAME)

re :		fclean all

# CC			=	cc
# FLAGS		=
# FLAGS_MLX	=	-framework OpenGL -framework AppKit
# OPTFLAGS	=	-O2
# BON_FLG1	=	-D BONUS=1

# RM			=	rm -rf
# AR			=	ar rcs

# # ------------------------------------------------------------------------------

# NAME 	=	so_long
# NAME_B	=	so_long_bonus
# LIB		=	libmlx.a
# LIB1	=	libft.a
# LIB2	=	so_long.a
# LIB3	=	so_long_b.a

# HDRS	=	so_long.h
# HDRS_B	=	so_long_b.h

# FLDR_S	=	srcs/
# FLDR_B	=	srcs_b/
# FLDR_H	=	hdrs/

# MAIN	=	main.c

# SRCS	=	draw_map.c	end_game.c	map_valid.c	\
# 			mobile_objects.c	mov.c	get_next_line.c	\
# 			get_next_line_utils.c mini_draw.c	\


# SRC		=	$(addprefix ${FLDR_S},${SRCS})
# SRCB	=	$(addprefix ${FLDR_B},${SRCS})
# HDR		=	$(addprefix ${FLDR_H},${HDRS})
# HDR_B	=	$(addprefix ${FLDR_H},${HDRS_B})
# OBJS	=	${SRC:%.c=%.o}
# OBJS_B	=	${SRCB:%.c=%.o}

# # ------------------------------------------------------------------------------

# READY	=	So_long ready to be launched
# READYB	=	So_long_bonus ready to be launched
# SWEPT	=	Directory was cleaned
# _GREEN	=	\e[32m
# _YELLOW	=	\e[33m
# _CYAN	=	\e[36m
# _END	=	\e[0m

# # ------------------------------------------------------------------------------

# %.o:		%.c	${HDR}
# 			@${CC} ${FLAGS} ${OPTFLAGS} -c -o $@ $<


# ${NAME}: 	${OBJS}
# 			@${MAKE} -C mlx
# 			@cp mlx/libmlx.a ${LIB}
# 			@${MAKE} -C libft
# 			@cp libft/libft.a ${LIB1}
# 			@${AR} ${LIB2} $?
# 			@${CC} ${FLAGS_MLX} ${FLAGS} ${OPTFLAGS} ${MAIN} ${LIB} ${LIB1} ${LIB2} -o ${NAME}
# 			@printf "${_GREEN}${READY}${_END}\n"


# all:		${NAME}

# clean:
# 			@${MAKE} fclean -C libft
# 			@${MAKE} clean -C mlx
# 			@${RM} ${OBJS} ${OBJS_B} ${LIB} ${LIB1} ${LIB2} ${LIB3} mlx/libmlx.a
# 			@printf "${_YELLOW}${SWEPT}${_END}\n"

# fclean:		clean
# 			@${RM} ${NAME} ${NAME_B}

# re:			fclean all

# bonus:		${OBJS_B}
# 			@${MAKE} -C mlx
# 			@cp mlx/libmlx.a ${LIB}
# 			@${MAKE} -C libft
# 			@cp libft/libft.a ${LIB1}
# 			@${AR} ${LIB3} $?
# 			@${CC} ${FLAGS_MLX} ${FLAGS} ${OPTFLAGS} ${MAIN} ${LIB} ${LIB1} ${LIB3} -o ${NAME_B}
# 			@printf "${_GREEN}${READYB}${_END}\n"

# norm:
# 			@norminette ${MAIN} ${FLDR_H} ${FLDR_S} ${FLDR_B} libft

# .PHONY: re all clean fclean bonus