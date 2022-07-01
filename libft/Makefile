# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbierny <gbierny@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/04 19:55:33 by gbierny           #+#    #+#              #
#    Updated: 2022/05/03 20:47:22 by gbierny          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
POST_CLEAN = rm -f ${NAME}
OBJECTS	= ${SRCS:.c=.o}
OBJECTS_BONUS = ${BONUS:.c=.o}
SRCS = ft_memset.c ft_bzero.c ft_calloc.c ft_memcpy.c \
	ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c \
	ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strchr.c \
	ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
	ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
	ft_strmapi.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	get_next_line_utils.c get_next_line.c ft_substr_cat.c
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstdelone.c ft_lstclear.c \
	ft_lstadd_back.c ft_lstiter.c ft_lstmap.c ft_lstdel.c

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o) 


all: $(NAME)

$(NAME): ${OBJECTS}
	ar rc ${NAME} ${OBJECTS}

bonus: ${OBJECTS_BONUS}
	ar rcs ${NAME} ${OBJECTS_BONUS}

a: $(NAME) bonus
	
clean:
	rm -f ${OBJECTS} ${OBJECTS_BONUS}

fclean: clean
	rm -f ${NAME}

re : fclean all

.PHONY: all clean fclean re main

