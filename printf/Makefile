# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spawar <spawar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 17:33:36 by spawar            #+#    #+#              #
#    Updated: 2024/04/10 23:32:07 by spawar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc 

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS = ft_hex.c ft_putnbr.c ft_printf.c ft_putchar.c ft_putptr.c ft_putstr.c ft_strlen.c ft_u.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)

fclean:
		$(MAKE) clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re