# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbaudot <vbaudot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 10:33:26 by vbaudot           #+#    #+#              #
#    Updated: 2017/12/10 13:30:34 by vbaudot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Werror -Wextra
NAME=libft.a
NAME_P=$(shell echo $(NAME) | tr ' ' '\n' | sed "s/\.[acoh]$///g" | tr '\n' ' ' | sed "s/ $///g")
SRC=\
ft_abs.c ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
ft_isdigit.c ft_islower.c ft_isprint.c ft_isupper.c ft_itoa.c\
ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c\
ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c\
ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c\
ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_lstprint.c ft_lstappend.c\
ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c\
ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c\
ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c\
ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c\
ft_toupper.c ft_strreverse.c get_next_line.c ft_split_whitespaces.c\
ft_print_words_tables.c ft_putfnbr.c
# $(shell find . | grep "\.c" | sed "s/^\.\///" | tr "\n" " ")
OBJ=$(SRC:.c=.o)
# $(shell find . | grep "\.c" | sed "s/^\.\///g" | sed  "s/\.c/\.o/g" | tr "\n" " ")

YEL="\\033[33m"
BLU="\\033[34m"
RED="\\033[31m"
NC="\\033[0m"
CYA="\\033[36m"
GRE="\\033[32m"
BOL="\\033[1m"
CHE="\\xE2\\x9C\\x94"
OK="$(GRE)$(CHE)$(NC)"

all : $(NAME)

$(NAME) : $(OBJ)
	@printf "\n[$(NAME_P)] doing ar rc $(BOL)$(CYA)$@$(NC)"
	@ar rc $@ $^
	@printf '\t\t\t'$(OK)'\n'
	@printf "[$(NAME_P)] doing ranlib $(BOL)$(CYA)$@$(NC)"
	@ranlib	$@
	@printf '\t\t\t'$(OK)'\n'

%.o: %.c
	@printf "\r\033[0K[$(NAME_P)] compile $(BOL)$(YEL)$<$(NC)..."
	@$(CC) $(CFLAGS) -o $@ -c $<
	@printf '\t\t\t'$(OK)

clean :
	@printf "[$(NAME_P)] rm all $(BOL)$(RED) obj file$(NC)"
	@rm -f $(OBJ)
	@printf '\t\t\t'$(OK)'\n'

fclean : clean
	@printf "rm $(BOL)$(CYA)$(NAME)$(NC)"
	@rm -f $(NAME)
	@printf '\t'$(OK)'\n'

cleanf :
	@printf "[$(NAME)] rm $(BOL)$(CYA)$(NAME)$(NC)"
	@rm -f $(NAME)
	@printf '\t\t\t\t'$(OK)'\n'

proper : all clean

re : fclean all

.PHONY: proper re cleanf
