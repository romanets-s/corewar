# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sromanet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/30 17:29:01 by sromanet          #+#    #+#              #
#    Updated: 2016/12/19 22:03:52 by sromanet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC = check_flag.c choice_function.c ft_printf.c function_c.c function_d.c\
	function_o.c function_s.c function_u.c function_wchar_t.c function_x.c\
	function_p.c itoa_base_type.c itoa_base_type_2.c itoa_d_type.c\
	itoa_d_type_2.c libft_min.c libft_min_2.c libft_min_3.c libft_min_4.c\
	libft_min_4.c libft_min_5.c libft_min_6.c libft_min_7.c
OBJECTS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)

%.o: %.c
	@$(CC) $(FLAGS) -c -o $@ $<

clean:
	@rm -rf $(OBJECTS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
