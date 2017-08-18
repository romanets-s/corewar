NAME = asm
SRC = asm.c errors.c head.c init.c insert_label.c labels.c lib_1.c operations.c rdi_functions.c tmp_struct.c write_in_file.c
SRCO = $(SRC:.c=.o)
INCLUDES = lem_in.h
FLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(SRCO)
	@make -C libft
	@make -C ft_printf
	@gcc $(FLAGS) -o $(NAME) $(SRCO) $(LIBFT) $(PRINTF)
	@echo "\033[32;1m<asm>      | done"

.c.o:
	@gcc $(FLAGS) -c $< -o $@

clean:
	@rm -f $(SRCO)
	@make clean -C libft
	@make clean -C ft_printf
	@echo "\033[32;1m<asm>      | clean succes"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft
	@make fclean -C ft_printf
	@echo "\033[32;1m<asm>      | fclean succes"

re: fclean all
	@echo "\033[32;1m<asm>      | re succes"
