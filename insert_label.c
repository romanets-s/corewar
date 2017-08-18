/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_label.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 20:49:50 by sromanet          #+#    #+#             */
/*   Updated: 2017/08/17 20:49:51 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_insert	*create_insert(t_insert *first, char *label, int code_i, t_tmp *op)
{
	t_insert	*insert;
	int			i;

	insert = (t_insert *)malloc(sizeof(t_insert));
	insert->label = label;
	insert->code_i = code_i;
	insert->i = 0;
	insert->arg = op->s;
	insert->op = create_tmp(op->n);
	insert->op->flag = op->flag;
	insert->op->argc = op->argc;
	i = -1;
	while (++i < 3)
	{
		insert->op->arg[i] = op->arg[i];
		insert->op->val[i] = op->val[i];
	}
	insert->next = first;
	return (insert);
}

void		insert_code(t_asm *bin, t_insert *tmp, int label_i)
{
	unsigned int	val;
	int				len;

	val = (unsigned int)label_i - tmp->code_i;
	len = -1;
	if (bin->op[tmp->op->n].size == 2 || tmp->op->arg[tmp->arg] == T_IND)
	{
		val = (unsigned short int)val;
		bin->code[tmp->i++] = (unsigned char)(val >> 8);
		val = val << 24;
		bin->code[tmp->i] = (unsigned char)(val >> 24);
	}
	else
	{
		while (++len < 4)
		{
			bin->code[tmp->i++] = (unsigned char)(val >> 24);
			val = val << 8;
		}
	}
}

void		search_insert(t_asm *bin)
{
	t_insert	*tmp;
	int			i;

	i = 0;
	tmp = bin->insert;
	while (tmp != NULL)
	{
		if ((i = search_label(bin->lebels, tmp->label)) != -1)
			insert_code(bin, tmp, i);
		else
		{
			bin->ptr = tmp->label;
			error(bin, 0, 7);
		}
		tmp = tmp->next;
	}
}
