# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estrong <estrong@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/05 11:35:47 by estrong           #+#    #+#              #
#    Updated: 2022/03/12 15:47:42 by estrong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIST =	ft_isalnum.c	ft_isalpha.c	ft_isascii.c	\
		ft_isdigit.c	ft_isprint.c	ft_memset.c		\
		ft_strchr.c		ft_strlcat.c	ft_strlcpy.c	\
		ft_strlen.c		ft_strncmp.c	ft_strnstr.c	\
		ft_strrchr.c	ft_tolower.c	ft_toupper.c	\
		ft_memmove.c	ft_memcpy.c		ft_memcmp.c		\
		ft_memchr.c		ft_atoi.c		ft_bzero.c		\
		ft_calloc.c		ft_strdup.c		ft_substr.c		\
		ft_strjoin.c	ft_strtrim.c	ft_itoa.c		\
		ft_split.c		ft_putchar_fd.c	ft_putstr_fd.c	\
		ft_putendl_fd.c	ft_putnbr_fd.c	ft_strmapi.c	\
		ft_striteri.c	\
		ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c	\
		ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c	\
		ft_lstclear.c	ft_lstiter.c		ft_lstmap.c

HEADER	=	libft.h

OBJ = $(patsubst %.c,%.o,$(LIST))

CC = gcc
FLAGS = -Wall -Wextra -Werror -I$(HEADER)

all: $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	ar rcs $(NAME) $?

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@ 

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re