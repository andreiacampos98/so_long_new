# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 16:39:13 by marvin            #+#    #+#              #
#    Updated: 2023/01/16 18:59:23 by anaraujo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ./ft_atoi.c			\
		./ft_bzero.c		\
		./ft_calloc.c		\
		./ft_isalnum.c		\
		./ft_isalpha.c		\
		./ft_isascii.c		\
		./ft_isdigit.c		\
		./ft_isprint.c		\
		./ft_issign.c		\
		./ft_itoa.c			\
		./ft_memchr.c		\
		./ft_memcmp.c		\
		./ft_memcpy.c		\
		./ft_memmove.c		\
		./ft_memset.c		\
		./ft_putchar_fd.c	\
		./ft_putendl_fd.c	\
		./ft_putnbr_fd.c	\
		./ft_putstr_fd.c	\
		./ft_split.c		\
		./ft_strchr.c		\
		./ft_strdup.c		\
		./ft_striteri.c		\
		./ft_strjoin.c		\
		./ft_strlcat.c		\
		./ft_strlcpy.c		\
		./ft_strlen.c		\
		./ft_strmapi.c		\
		./ft_strncmp.c		\
		./ft_strnstr.c		\
		./ft_strrchr.c		\
		./ft_substr.c		\
		./ft_tolower.c		\
		./ft_toupper.c		\
		./ft_strtrim.c		\
		./ft_lstadd_front.c	\
		./ft_lstnew.c		\
		./ft_lstsize.c		\
		./ft_lstlast.c		\
		./ft_lstadd_back.c	\
		./ft_lstdelone.c	\
		./ft_lstclear.c		\
		./ft_lstiter.c		\
		./ft_lstmap.c		\
		./ft_printf.c		\
		./ft_putchar.c		\
		./ft_puthex.c		\
		./ft_putnbr.c		\
		./ft_putstr.c		\
		./ft_putptr.c		\
		./ft_strend_cmp.c	\
		./handle_errors.c	\
		./get_next_line_bonus.c

OBJS = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
