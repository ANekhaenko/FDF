# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anekhaen <anekhaen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/18 20:24:39 by anekhaen          #+#    #+#              #
#    Updated: 2019/09/26 22:59:28 by anekhaen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
HEADER = -I libft.h
CFLAGS	= -Wall -Wextra -Werror
CC = gcc
SRCS = *.c
OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRCS) libft.h
	@gcc -Wall -Wextra -Werror -c $(SRCS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
