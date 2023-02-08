# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/02 00:30:47 by iwhana            #+#    #+#              #
#    Updated: 2022/05/25 22:34:57 by iwhana21         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRC =	array_utils.c \
	check_builtins.c \
	check_stat_utils.c \
	check_stat_utils2.c \
	check_stat.c \
	core_fork.c \
	create_command_env.c \
	create_commands.c \
	env_utils.c \
	find_functions.c \
	find_path.c \
	free_structs.c \
	ft_cd.c \
	ft_echo.c \
	ft_env.c \
	ft_exit.c \
	ft_export_utils.c \
	ft_export.c \
	ft_pwd.c \
	ft_unset.c \
	functions_launch.c \
	handler.c \
	history.c \
	list_utils.c \
	number_of_pipes.c \
	parser_commands_utils.c \
	parser_commands_utils2.c \
	parser_commands.c \
	parser_commands2.c \
	parser_flags_utils.c \
	parser_flags.c \
	pipe_utils.c \
	press_arrows.c \
	press.c \
	print_errors.c \
	read_terminal.c \
	redirect.c \
	replacement_utils.c \
	replacement.c \
	signals.c \
	split_flags.c \
	start_minishell.c \
	utils.c \
	main.c

OBJ = $(SRC:%.c=%.o)
HEADER = minishell.h
 
# compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror
 
# ft library
FT = ./libft/
FT_LIB = $(addprefix $(FT),libft.a)
FT_INC = -I ./libft
FT_LNK = -L ./libft -l ft
 
all: $(FT_LIB) $(NAME)
 
%.o: %.c $(HEADER) ./libft/libft.h
	$(CC) $(CFLAGS) $(FT_INC) -I $(HEADER) -c $< -o $@
 
$(FT_LIB): ./libft/libft.h
	make -C $(FT) re
 
$(NAME): $(OBJ) $(HEADER) 
	$(CC) $(OBJ) $(FT_LNK) -lm -o $(NAME) -ltermcap
 
clean:
	rm -rf $(OBJ)
	make -C $(FT) clean
 
fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean
 
re: fclean all