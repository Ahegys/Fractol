# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afelipe- <afelipe-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 11:46:20 by afelipe-          #+#    #+#              #
#    Updated: 2022/10/11 00:48:25 by afelipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_utilities.c args.c 

FLAGS = -Wall -Werror -Wextra

OBJS = $(SRC:%.c=%.o)

INCLUDE = ft_printf.h

C = cc

$(NAME):	$(OBJS) $(INCLUDE)

%.o:	%.c
	$(CC) $(FLAGS) -g -c $< -o $@
	ar -rcs $(NAME) $@
all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean:		clean
	rm -rf $(NAME)

re: fclean all
