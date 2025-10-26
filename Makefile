# **************************************************************************** #
#                                                                             #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 13:54:56 by abouzkra          #+#    #+#              #
#    Updated: 2025/10/26 15:46:19 by abouzkra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = include
LIBFT = libft
SRCDIR = src/
SRC_FILES = ft_printf ft_putnbr ft_putptr ft_puthex

SRCS = $(addprefix $(SRCDIR), $(addsuffix .c, $(SRC_FILES)))
OBJS = $(addprefix $(SRCDIR), $(addsuffix .o, $(SRC_FILES)))
RM = rm -f

all: $(NAME) clean

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@mv ./libft/libft.a $(NAME)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

test: main.c libftprintf.a
	$(CC) $< -L. -lftprintf && ./a.out
