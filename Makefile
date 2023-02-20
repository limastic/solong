# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 22:20:37 by nfaust            #+#    #+#              #
#    Updated: 2023/02/20 12:16:02 by nfaust           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wextra -Wall -Werror #-fsanitize=address
ARCHIVE = ar rc
REMOVE = rm -f

NAME = so_long
LIBFTNAME = libft/libft.a
PRINTFNAME = ft_printf/ft_printf.a
MLXNAME = mlx_linux/libmlx_Linux.a

HEADER = libft/libft.h \
		ft_printf/ft_printf.h \

SOURCES = src/so_long.c \

OBJ = $(SOURCES:.c=.o)

# all:	libft ft_printf ${NAME} 

all:	mlx ${NAME} 

libft:
	@$(MAKE) --no-print-directory -C libft

ft_printf:
	@$(MAKE) --no-print-directory -C ft_printf

mlx:
	@$(MAKE) --no-print-directory -C mlx_linux

# ${NAME}:     ${OBJ} ${LIBFTNAME} ${PRINTFNAME}
# 	${CC} ${FLAGS} ${OBJ} ${LIBFTNAME} ${PRINTFNAME} -o ${NAME}

${NAME}:     $(MLXNAME) ${OBJ}
	${CC} ${FLAGS} ${OBJ} $(MLXNAME) -o ${NAME}

clean:
	#@$(MAKE) --no-print-directory clean -C libft
	#@$(MAKE) --no-print-directory clean -C ft_printf
	@$(MAKE) --no-print-directory clean -C mlx_linux
	${REMOVE} ${OBJ}

fclean:	clean
	#@$(MAKE) --no-print-directory fclean -C libft
	#@$(MAKE) --no-print-directory fclean -C ft_printf
	${REMOVE} ${NAME}

keep_o: all clean

%.o : %.c ${HEADER} Makefile 
	${CC} ${FLAGS} -I . -c $< -o $@  

re:    fclean all

.PHONY: re fclean all clean libft keep_o ft_printf