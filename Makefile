# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 22:20:37 by nfaust            #+#    #+#              #
#    Updated: 2023/03/07 12:00:54 by nfaust           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wextra -Wall -Werror
MLXFLAGS = -Lmlx_linux -Lusr/lib -lmlx -lXext -lX11 -lm -lz
ARCHIVE = ar rc	
REMOVE = rm -f

NAME = so_long
LIBFTNAME = libft/libft.a
PRINTFNAME = ft_printf/ft_printf.a
MLXNAME = mlx_linux/libmlx_Linux.a

HEADER = libft/libft.h \
		 ft_printf/ft_printf.h

SOURCES = src/so_long.c \
		  src/parsing.c \
		  src/utils.c \
		  src/check_map_feasibility.c \
		  src/get_map.c \
		  src/get_reachable_map.c \
		  src/exec_utils.c \
		  src/mooves.c \
		  src/game_over.c \
		  src/get_centered_map.c \
		  src/map_rendering.c

OBJ = $(SOURCES:.c=.o)

all:	mlx libft ft_printf ${NAME} 

libft:
	@$(MAKE) --no-print-directory -C libft

ft_printf:
	@$(MAKE) --no-print-directory -C ft_printf

mlx:
	@$(MAKE) --no-print-directory -C mlx_linux

${NAME}:     $(MLXNAME) ${OBJ}
	${CC} ${FLAGS} ${OBJ} ${LIBFTNAME} ${PRINTFNAME} -o ${NAME} $(MLXNAME) $(MLXFLAGS)

clean:
	@$(MAKE) --no-print-directory clean -C libft
	@$(MAKE) --no-print-directory clean -C ft_printf
	@$(MAKE) --no-print-directory clean -C mlx_linux
	${REMOVE} ${OBJ}

fclean:	clean
	@$(MAKE) --no-print-directory fclean -C libft
	@$(MAKE) --no-print-directory fclean -C ft_printf
	${REMOVE} ${NAME}

keep_o: all clean

%.o : %.c ${HEADER} Makefile 
	${CC} ${FLAGS} -I . -c $< -o $@  

re:    fclean all

.PHONY: re fclean all clean libft keep_o ft_printf