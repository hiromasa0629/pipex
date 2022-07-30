# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyap <hyap@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 14:22:01 by hyap              #+#    #+#              #
#    Updated: 2022/07/29 16:26:48 by hyap             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ${wildcard srcs/*.c}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = pipex

PRINTF = libftprintf.a

GNL = gnl.a

RM = rm -f

LIB = ${wildcard lib/*.a}

OBJ = $(SRCS:.c=.o)

%.o: %.c
	${CC} ${CFLAGS} -I includes -c $< -o $@

all: ${NAME}

${NAME}: ${OBJ}
	$(CC) $(CFLAGS) $(LIB) $(OBJ) -o $(NAME)

clean:
	${RM} $(OBJ)

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean re