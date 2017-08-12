cmake_minimum_required(VERSION 3.7)
project(corewar)

set(CMAKE_C_STANDARD 99)

set(LIBFT libft/ft_memset.c libft/ft_bzero.c libft/ft_memcpy.c libft/ft_memccpy.c libft/ft_memmove.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_strlen.c libft/ft_strdup.c libft/ft_strcpy.c libft/ft_strncpy.c libft/ft_strcat.c libft/ft_strncat.c libft/ft_strlcat.c libft/ft_strchr.c libft/ft_strrchr.c libft/ft_strstr.c libft/ft_strnstr.c libft/ft_strcmp.c libft/ft_strncmp.c libft/ft_atoi.c libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_isalnum.c libft/ft_isascii.c libft/ft_isprint.c libft/ft_toupper.c libft/ft_tolower.c libft/ft_memalloc.c libft/ft_memdel.c libft/ft_strnew.c libft/ft_strdel.c libft/ft_strclr.c libft/ft_striter.c libft/ft_striteri.c libft/ft_strmap.c libft/ft_strmapi.c libft/ft_strequ.c libft/ft_strnequ.c libft/ft_strsub.c libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_strsplit.c libft/ft_itoa.c libft/ft_putchar.c libft/ft_putstr.c libft/ft_putendl.c libft/ft_putnbr.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_lstnew.c libft/ft_lstdelone.c libft/ft_lstdel.c libft/ft_lstadd.c libft/ft_lstiter.c libft/ft_lstmap.c libft/ft_pow.c libft/ft_nbrlen.c libft/ft_swap_bits.c libft/ft_wordlen.c libft/ft_wordcount.c)
set(SOURCE_FILES asm.c head.c init.c lib_1.c)
set(PRINTF ft_printf/check_flag.c ft_printf/choice_function.c ft_printf/ft_printf.c ft_printf/function_c.c ft_printf/function_d.c ft_printf/function_o.c ft_printf/function_s.c ft_printf/function_u.c ft_printf/function_wchar_t.c ft_printf/function_x.c ft_printf/function_p.c ft_printf/itoa_base_type.c ft_printf/itoa_base_type_2.c ft_printf/itoa_d_type.c ft_printf/itoa_d_type_2.c ft_printf/libft_min.c ft_printf/libft_min_2.c ft_printf/libft_min_3.c ft_printf/libft_min_4.c ft_printf/libft_min_4.c ft_printf/libft_min_5.c ft_printf/libft_min_6.c ft_printf/libft_min_7.c)



add_executable(corewar ${SOURCE_FILES} ${LIBFT} ${PRINTF})