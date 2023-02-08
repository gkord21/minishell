# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/16 19:19:48 by iwhana            #+#    #+#              #
#    Updated: 2022/04/19 21:36:10 by iwhana21         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = $(shell ls | grep -E "ft_.+\.c") \
get_next_line.c get_next_line_utils.c get_next_line_utils2.c
HEADER = libft.h get_next_line.h
OBJ = $(SRC:%.c=%.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	ar rcs $(NAME) $(OBJ) $?

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all
