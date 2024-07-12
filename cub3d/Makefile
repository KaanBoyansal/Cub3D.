# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mboyansa <mboyansa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 04:10:56 by mboyansa          #+#    #+#              #
#    Updated: 2024/02/29 15:15:01 by mboyansa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c \
		utils.c \
		split.c \
		utils2.c \
		map.c \
		map2.c \
		validity.c \
		utils3.c \
		error.c \
		mlx.c \
		mlxUtils.c \
		mlxGame.c \
		raycast.c \
		validity2.c \
		raycasting.c \
		raycastUtils.c \
		raycastUtils2.c \
		validity3.c \
		mlx2.c \
		map3.c \
		mlx3.c \

NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LFLAGS = -framework AppKit -framework OpenGL -L./mlx -lmlx
MLX = ./mlx/libmlx.a
GET_NEXT_LINE = ./get_next_line/next_line.a
RM = rm -rf
LIBC = ar -rcs

all: $(NAME)

$(NAME): $(SRCS) $(MLX) $(GET_NEXT_LINE)
	@gcc $(CFLAGS) $(LFLAGS) $(SRCS) $(GET_NEXT_LINE) -o $(NAME)
	@echo "-*-*-*- OK -*-*-*-"

$(MLX) :
	@make -C ./mlx 2>/dev/null

$(GET_NEXT_LINE) :
	@make -C ./get_next_line

clean:

fclean: clean
	@rm -rf $(NAME)
	@make clean -C ./mlx
	@make fclean -C ./get_next_line

re: fclean all

.PHONY: all bonus clean fclean re .c.o