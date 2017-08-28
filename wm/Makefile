#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irepeta <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/01 18:43:22 by irepeta           #+#    #+#              #
#    Updated: 2017/08/05 17:41:15 by mkyianyt         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = corewar
SRC = main.c \
		cw_error_mess.c \
		cw_new_ch.c \
		cw_read_args.c \
		cw_read_args2.c \
		cw_struct_null.c \
		cw_decryptor.c \
		cw_decrypt_options.c \
		cw_prefight.c \
		cw_battle.c \
		cw_fight.c \
		cw_function_pack1.c \
		cw_function_pack2.c \
		cw_function_pack3.c \
		cw_function_pack4.c \
		cw_get_number.c \
		cw_get_arg.c \
		cw_the_end.c \
		cw_output.c \
		cw_put_inmem.c \
		cw_set_pause.c \
		cw_arg_func.c \
		cw_cpy_ch.c \
		cw_pre_visual.c \
		cw_vis_output.c \
		cw_vis_refresh.c \
		cw_vis_submenu.c \
		cw_vis_cps.c \
		cw_norme.c \
		ft_atoi_base.c \


OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(CC) -o $(NAME) $(OBJ) libft/libft.a -lncurses
	@echo "\033[32;1m<corewar>  | done"

.c.o:
	@$(CC) $(CLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@make -C libft/ clean
	@echo "\033[32;1m<corewar>  | clean succes"

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "\033[32;1m<corewar>  | fclean succes"

re: fclean all
	@echo "\033[32;1m<corewar>  | re succes"

