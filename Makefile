# **************************************************************************** #
#                                                                             #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouzkra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/13 13:54:56 by abouzkra          #+#    #+#              #
#    Updated: 2025/10/26 23:41:56 by abouzkra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = src/
SRC_FILES = ft_printf ft_putnbr ft_putptr ft_puthex

SRCS = $(addprefix $(SRCDIR), $(addsuffix .c, $(SRC_FILES)))
OBJS = $(addprefix $(SRCDIR), $(addsuffix .o, $(SRC_FILES)))
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)

%.o: %.c include/ft_printf.h
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@
	ar rcs $(NAME) $@

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all