# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 08:32:05 by vbaudot           #+#    #+#              #
#    Updated: 2017/12/20 11:51:53 by vbaudot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = ft_ls
SRC = main.c\
		ft_ls.c\
		print_usage.c\
		options_init.c\
		sort_files.c\
		check_params.c\
		option_l.c\
		init_padding.c\
		print_files.c\
		option_r.c\
		count.c\
		error.c\
		help_norm.c\
		check_padding.c\
		ok_files.c\
		check_params_2.c\

OBJ = $(SRC:.c=.o)
DEBUG = #-g3 -fsanitize=address

CFLAGS = -Wall -Werror -Wextra
LIBFT = -L./libft -lft

YEL="\\033[33m"
BLU="\\033[34m"
RED="\\033[31m"
NC="\\033[0m"
MAG="\\033[35m"
CYA="\\033[36m"
GRE="\\033[32m"
BOL="\\033[1m"
CHE="\\xE2\\x9C\\x94"
OK="$(GRE)$(CHE)$(NC)"

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@printf "\n[$(NAME)] linking $(CYA)$(BOL)$(OBJ)$(NC)\n"
	@printf "to make the binary $(MAG)$(BOL)$(NAME)$(NC)"
	@gcc $(CFLAGS) $(OBJ) $(LIBFT) $(DEBUG) -o $(NAME)
	@printf '\t\t'$(OK)'\n'

%.o: %.c
	@printf "\r\033[0K[$(NAME)] compile $(BOL)$(YEL)$<$(NC)..."
	@$(CC) $(CFLAGS) -I./libft -c $<
	@printf '\t'$(OK)

clean:
	@make -C libft clean
	@printf "[$(NAME)] rm all $(BOL)$(RED) obj file$(NC)"
	@rm -rf $(OBJ)
	@printf '\t\t'$(OK)'\n'

fclean: clean
	@make -C libft fclean
	@printf "[$(NAME)] rm $(BOL)$(CYA)$(NAME)$(NC)"
	@rm -rf $(NAME)
	@printf '\t\t'$(OK)'\n'

re: fclean all

proper: all clean

.PHONY: re proper
