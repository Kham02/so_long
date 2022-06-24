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

SRCS		= main.c	draw_map.c	end_game.c	map_valid.c	mobile_objects.c	\
			mov.c	get_next_line.c	get_next_line_utils.c mini_draw.c

SRCS_B		= main_bonus.c	init_bonus.c	destroy_bonus.c	images_bonus.c	map_bonus.c	map_update_bonus.c	\
			window_bonus.c	enemy_bonus.c	animation_bonus.c	./mov/mov_down_bonus.c	./mov/mov_left_bonus.c	\
			./mov/mov_up_bonus.c	./mov/mov_right_bonus.c	./mov/mov_utils_bonus.c get_next_line.c	get_next_line_utils.c

SRCS_DIR	= ./srcs/
SRCS_DIR_B	= ./srcs_b/

OBJS		= ${addprefix ${SRCS_DIR}, ${SRCS:.c=.o}}

OBJS_B		= ${addprefix ${SRCS_DIR_B}, ${SRCS_B:.c=.o}}

NAME		= so_long

B_NAME		= so_long_bonus

HEADER		= ./hdrs/so_long.h
HEADER_B	= ./hdrs/so_long_bonus.h

MLX_LIBS	= -lmlx -lm -L ./minilibx_opengl -framework OpenGL -framework AppKit

LIB			= ./libft/libft.a

CC = cc
RM = rm -f

CFLAGS		= -Wall -Wextra -Werror

# COLORS

GREEN	= \033[0;32m
YELO	= \033[0;33m
BLUE	= \033[0;34m
NEW		= \033[0;35m
SHALLOW = \033[0m

# END COLORS

.PHONY: all clean fclean re bonus norm libft minilibx

all:		${NAME}

minilibx:	
			${MAKE} -C ./minilibx_opengl 2> /dev/null

%.o:%.c		${HEADER}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

libft:		
			${MAKE} -C ./libft/

${NAME}:	${OBJS} ${HEADER}
			${MAKE} -C ./libft/
			${MAKE} -C ./minilibx_opengl 2> /dev/null
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIB} ${MLX_LIBS}
			@echo "${GREEN}${NAME} compile!${SHALLOW}"

bonus:		${B_NAME}

${B_NAME}:	${OBJS_B} ${HEADER_B}
			make -C ./libft/
			make -C ./minilibx_opengl 2> /dev/null
			${CC} ${CFLAGS} -o ${B_NAME} ${OBJS_B} ${LIB} ${MLX_LIBS}
			@echo "${NEW}${B_NAME} compile!${SHALLOW}"

norm:
			@echo "${GREEN}|-----Chek NORMs!-----|${NEW}"
			@norminette ./srcs/
			@norminette ./head_cub.h
			@norminette ./libft/
			@echo "${GREEN}|-----Chek ended!-----|${SHALLOW}"

clean:		
			@${RM} ${OBJS} ${OBJS_B}
			@make clean -C ./libft/
			@make -C minilibx_opengl/ clean
			@echo "${BLUE}clean done!${SHALLOW}"

fclean:		
			@${RM} ${OBJS} ${OBJS_B} ${NAME} ${B_NAME}
			@make fclean -C ./libft/
			@make -C minilibx_opengl/ clean
			@echo "${YELO}fclean done!${SHALLOW}"

re:			fclean all



# NAME	=	so_long

# NAME_B	=	so_long_bonus

# SRCS	=	srcs/main.c	srcs/draw_map.c	srcs/end_game.c	srcs/map_valid.c	srcs/mobile_objects.c	\
# 			srcs/mov.c	srcs/get_next_line.c	srcs/get_next_line_utils.c srcs/mini_draw.c

# SRCS_B	=	srcs_b/main_bonus.c	srcs_b/init_bonus.c	srcs_b/destroy_bonus.c	srcs_b/images_bonus.c	srcs_b/map_bonus.c	srcs_b/mp_update_bonus.c	\
# 			srcs_b/window_bonus.c	srcs_b/enemy_bonus.c	srcs_b/animation_bonus.c	srcs_b/mov_down_bonus.c	srcs_b/mov_left_bonus.c	\
# 			srcs_b/mov_up_bonus.c	srcs_b/mov_right_bonus.c	srcs_b/mov_utils_bonus.c

# OBJ	=	$(patsubst %.c,%.o,$(SRCS))
# OBJ_B	=	$(patsubst %.c,%.o,$(SRCS_B))

# HEADER	=	hdrs/so_long.h
# HEADER_B	=	hdrs/so_long_bonus.h

# LFT		=	Libft

# MLX		=	minilibx_opengl_20191021/libmlx.a

# CC		=	cc

# FLAGS	=	-Wall -Wextra -Werror -I$(HEADER)

# .PHONY :	all clean fclean re bonus

# all :	$(NAME)

# $(NAME):	$(OBJ)
# 	$(MAKE) -C ./minilibx_opengl_20191021
# 	$(MAKE) -C ./Libft
# # $(CC) -c ${FLAGS} ${OBJ} -I Libft/libft.a
# 	$(CC) -lmlx -framework OpenGL -framework AppKit $(FLAGS) $(OBJ) $(MLX) Libft/libft.a -o $(NAME)

# %.o: %.c $(HEADER)
# 	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

# .bonus	:	$(OBJ_B)
# 	$(MAKE) -C ./minilibx_opengl_20191021
# 	$(MAKE) -C ./libft
# 	$(CC) -lmlx -framework OpenGL -framework AppKit $(FLAGS) $(OBJ_B) $(MLX) Libft/libft.a -o $(NAME)
	

# clean :
# 	@make clean -C $(LFT)
# 	@make clean -C $(MLX)
# 			rm -rf $(OBJ)
# 			rm -rf $(OBJ_B)

# fclean :
# 	@make fclean -C $(LFT)
# 	@make clean -C $(MLX)
# 			rm -rf $(NAME)
# 			rm -rf $(NAME_B)

# re :		fclean all

# # CC			=	cc
# # FLAGS		=
# # FLAGS_MLX	=	-framework OpenGL -framework AppKit
# # OPTFLAGS	=	-O2
# # BON_FLG1	=	-D BONUS=1

# # RM			=	rm -rf
# # AR			=	ar rcs

# # # ------------------------------------------------------------------------------

# # NAME 	=	so_long
# # NAME_B	=	so_long_bonus
# # LIB		=	libmlx.a
# # LIB1	=	libft.a
# # LIB2	=	so_long.a
# # LIB3	=	so_long_b.a

# # HDRS	=	so_long.h
# # HDRS_B	=	so_long_b.h

# # FLDR_S	=	srcs/
# # FLDR_B	=	srcs_b/
# # FLDR_H	=	hdrs/

# # MAIN	=	main.c

# # SRCS	=	draw_map.c	end_game.c	map_valid.c	\
# # 			mobile_objects.c	mov.c	get_next_line.c	\
# # 			get_next_line_utils.c mini_draw.c	\


# # SRC		=	$(addprefix ${FLDR_S},${SRCS})
# # SRCB	=	$(addprefix ${FLDR_B},${SRCS})
# # HDR		=	$(addprefix ${FLDR_H},${HDRS})
# # HDR_B	=	$(addprefix ${FLDR_H},${HDRS_B})
# # OBJS	=	${SRC:%.c=%.o}
# # OBJS_B	=	${SRCB:%.c=%.o}

# # # ------------------------------------------------------------------------------

# # READY	=	So_long ready to be launched
# # READYB	=	So_long_bonus ready to be launched
# # SWEPT	=	Directory was cleaned
# # _GREEN	=	\e[32m
# # _YELLOW	=	\e[33m
# # _CYAN	=	\e[36m
# # _END	=	\e[0m

# # # ------------------------------------------------------------------------------

# # %.o:		%.c	${HDR}
# # 			@${CC} ${FLAGS} ${OPTFLAGS} -c -o $@ $<


# # ${NAME}: 	${OBJS}
# # 			@${MAKE} -C mlx
# # 			@cp mlx/libmlx.a ${LIB}
# # 			@${MAKE} -C libft
# # 			@cp libft/libft.a ${LIB1}
# # 			@${AR} ${LIB2} $?
# # 			@${CC} ${FLAGS_MLX} ${FLAGS} ${OPTFLAGS} ${MAIN} ${LIB} ${LIB1} ${LIB2} -o ${NAME}
# # 			@printf "${_GREEN}${READY}${_END}\n"


# # all:		${NAME}

# # clean:
# # 			@${MAKE} fclean -C libft
# # 			@${MAKE} clean -C mlx
# # 			@${RM} ${OBJS} ${OBJS_B} ${LIB} ${LIB1} ${LIB2} ${LIB3} mlx/libmlx.a
# # 			@printf "${_YELLOW}${SWEPT}${_END}\n"

# # fclean:		clean
# # 			@${RM} ${NAME} ${NAME_B}

# # re:			fclean all

# # bonus:		${OBJS_B}
# # 			@${MAKE} -C mlx
# # 			@cp mlx/libmlx.a ${LIB}
# # 			@${MAKE} -C libft
# # 			@cp libft/libft.a ${LIB1}
# # 			@${AR} ${LIB3} $?
# # 			@${CC} ${FLAGS_MLX} ${FLAGS} ${OPTFLAGS} ${MAIN} ${LIB} ${LIB1} ${LIB3} -o ${NAME_B}
# # 			@printf "${_GREEN}${READYB}${_END}\n"

# # norm:
# # 			@norminette ${MAIN} ${FLDR_H} ${FLDR_S} ${FLDR_B} libft

# # .PHONY: re all clean fclean bonus