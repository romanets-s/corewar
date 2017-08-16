# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sromanet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/30 17:29:01 by sromanet          #+#    #+#              #
#    Updated: 2017/05/10 22:02:59 by sromanet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test
CC = gcc
#FLAGS = -Wall -Wextra -Werror
SRC = asm.c, head.c, init.c, lib_1.c
OBJECTS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRCO)
	@make -C libft
	@make -C ft_printf
	@gcc $(FLAGS) -o $(NAME) $(SRCO) $(LIBFT)
	@echo "\033[32;1m<lem-in>   | done"

.c.o:
	@gcc $(FLAGS) -c $< -o $@

clean:
	@rm -f $(SRCO)
	@make clean -C libft
	@make clean -C ft_printf
	@echo "\033[32;1m<lem-in>   | clean succes"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft
	@make fclean -C ft_printf
	@echo "\033[32;1m<lem-in>   | fclean succes"

re: fclean all
	@echo "\033[32;1m<lem-in>   | re succes"
