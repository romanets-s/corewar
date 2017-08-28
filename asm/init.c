/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 20:50:30 by sromanet          #+#    #+#             */
/*   Updated: 2017/08/17 20:50:32 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	op_init(t_asm *bin)
{
	*bin = (t_asm){{
		{"live", 1, {T_DIR}, 0, 1, 4},
		{"ld", 2, {T_DIR | T_IND, T_REG}, 1, 2, 4},
		{"st", 2, {T_REG, T_IND | T_REG}, 1, 3, 0},
		{"add", 3, {T_REG, T_REG, T_REG}, 1, 4, 0},
		{"sub", 3, {T_REG, T_REG, T_REG}, 1, 5, 0},
		{"and", 3, {T_REG | T_DIR | T_IND, T_REG
					| T_IND | T_DIR, T_REG}, 1, 6, 4},
		{"or", 3, {T_REG | T_IND | T_DIR, T_REG
				| T_IND | T_DIR, T_REG}, 1, 7, 4},
		{"xor", 3, {T_REG | T_IND | T_DIR, T_REG
						| T_IND | T_DIR, T_REG}, 1, 8, 4},
		{"zjmp", 1, {T_DIR}, 0, 9, 2},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 1, 10, 2},
		{"sti", 3, {T_REG, T_REG | T_DIR
				| T_IND, T_DIR | T_REG}, 1, 11, 2},
		{"fork", 1, {T_DIR}, 0, 12, 2},
		{"lld", 2, {T_DIR | T_IND, T_REG}, 1, 13, 4},
		{"lldi", 3, {T_REG | T_DIR | T_IND,
				T_DIR | T_REG, T_REG}, 1, 14, 2},
		{"lfork", 1, {T_DIR}, 0, 15, 2},
		{"aff", 1, {T_REG}, 1, 16, 0},
		{0, 0, {0}, 0, 0, 0}
			}, .code = NULL, .code_i = 0, .lebels = NULL, .insert = NULL,
			.name = 0, .comm = 0, .file_name = NULL, .kostyl = 0, .ptr = NULL};
}

void	asm_init(t_asm *bin)
{
	op_init(bin);
	bin->buff_size = BUFF_SIZE;
	bin->i = 0;
	bin->code = (unsigned char *)malloc(sizeof(unsigned char) * bin->buff_size);
	bin->head.magic = COREWAR_EXEC_MAGIC;
	ft_bzero(bin->head.prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(bin->head.comment, COMMENT_LENGTH + 1);
}
