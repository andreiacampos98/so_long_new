# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/12 18:23:18 by anaraujo          #+#    #+#              #
#    Updated: 2023/01/29 13:27:29 by anaraujo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

CC := cc
CFLAGS := -Wall -Werror -Wextra -g
MLXFLAGS := -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11

LIBFT := ./libft/libft.a

SRCS := main.c				\
			map_check.c		map_check_2.c		\
			map_read.c		utils.c				\
			game_init.c		game_handler.c		\
			game_move.c		game_images.c	

OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft
	echo "\033[1m LIBFT done \033[0m"

$(MINILIBX):
	$(MAKE) -C ./minilibx-linux
	echo "\033[1m MiniLibX done \033[0m"

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) -lm $(OBJS) $(MLXFLAGS) $(LIBFT) $(MINILIBX) -o $(NAME)
	echo "\033[1m $(NAME) ready \033[0m"

clean:
		$(MAKE) clean -C ./libft
		rm -rf $(OBJS)
		echo "OBJS deleted"

fclean: clean
		$(MAKE) fclean -C ./libft
		rm -rf $(NAME)
		echo "$(NAME) deleted"

re: fclean all

.SILENT: