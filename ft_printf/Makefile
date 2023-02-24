# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 04:52:49 by nfaust            #+#    #+#              #
#    Updated: 2022/12/14 04:59:35 by nfaust           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a
HEADER = ft_printf.h

ARCHIVE = ar rc
REMOVE = rm -f
CC = cc
FLAGS = -Wall -Werror -Wextra

SOURCES = ft_print_u.c \
	ft_printf.c \
	print_functions.c

OBJ = $(SOURCES:.c=.o)

all:	${NAME}

${NAME}:    ${OBJ}
	${ARCHIVE} ${NAME} ${OBJ}

clean:
	${REMOVE} ${OBJ}

fclean:	clean
	${REMOVE} ${NAME}

%.o : %.c ${HEADER} Makefile
	${CC} ${FLAGS} -c $< -o $@ -I . 

re:    fclean all

.PHONY: re fclean all clean