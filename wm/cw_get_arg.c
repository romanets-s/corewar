/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 13:25:19 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/08/19 13:25:27 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

static void		check_args(t_cw *cw, int i)
{
	if (!(cw->n.as = (unsigned int**)malloc(sizeof(unsigned int*) * 2)))
		cw_usage("lol lol wtf malloc crashed [cw_get_arg]\n", cw);
	if (!(cw->n.as[0] = (unsigned int*)malloc(sizeof(unsigned int) * 4)))
		cw_usage("lol lol wtf malloc crashed [cw_get_arg]\n", cw);
	if (!(cw->n.as[1] = (unsigned int*)malloc(sizeof(unsigned int) * 4)))
		cw_usage("lol lol wtf malloc crashed [cw_get_arg]\n", cw);
	while (++i < 4)
	{
		cw->n.as[0][i] = 0;
		cw->n.as[1][i] = 0;
	}
}

static void		put_t_reg(t_cw *cw, int i, int c)
{
	unsigned int reg;

	cw->n.as[0][i] = T_REG;
	reg = cw_get_number(cw, cw->ch[c].pc + cw->n.b,
		cw->ch[c].pc + cw->n.b + 1) - 1;
	if (reg >= REG_NUMBER)
		cw->n.as[0][i] = 0;
	cw->n.as[1][i] = reg;
	++(cw->n.b);
}

static void		put_t_dir(t_cw *cw, int i, int c, int dir)
{
	cw->n.as[0][i] = T_DIR;
	cw->n.as[1][i] = cw_get_number(cw, cw->ch[c].pc + cw->n.b,
		cw->ch[c].pc + cw->n.b + dir);
	cw->n.b += dir;
}

static void		put_t_ind(t_cw *cw, int i, int c, int ind)
{
	cw->n.as[0][i] = T_IND;
	cw->n.as[1][i] = cw_real_ptr(cw->ch[c].pc + (cw_get_number(cw,
		cw->ch[c].pc + cw->n.b, cw->ch[c].pc + cw->n.b + IND_SIZE)
		% (ind ? IDX_MOD : 1)));
	cw->n.b += 2;
}

unsigned int	**cw_get_arg(t_cw *cw, int c, int dir, int ind)
{
	int		i;

	check_args(cw, -1);
	i = -1;
	cw->n.n = cw_int_decrypt(cw->vm.mem[cw->ch[c].pc + 1]);
	cw->n.b = 2;
	while (++i < 3)
	{
		if (!cw->n.n[i * 2] && cw->n.n[i * 2 + 1] == 1)
			put_t_reg(cw, i, c);
		else if (cw->n.n[i * 2] == 1 && !cw->n.n[i * 2 + 1])
			put_t_dir(cw, i, c, dir);
		else if (cw->n.n[i * 2] == 1 && cw->n.n[i * 2 + 1] == 1)
			put_t_ind(cw, i, c, ind);
	}
	free(cw->n.n);
	cw->n.as[0][3] = 0;
	cw->n.as[1][3] = cw->n.b;
	return (cw->n.as);
}
