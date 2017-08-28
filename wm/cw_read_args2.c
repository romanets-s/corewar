/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_read_args2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 16:19:43 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/08/19 16:19:44 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

static void	cw_flags_n_checkall(t_cw *cw, int num)
{
	int i;

	i = 0;
	while (i < cw->chcount)
	{
		if (cw->ch[i].isnum && cw->ch[i].num == num)
			cw_usage("Already there is a champion with this number\n", cw);
		++i;
	}
}

static void	cw_check_int(char *argv, t_cw *cw)
{
	int				i;
	long long int	test;

	i = 0;
	test = 0;
	if (*argv == '+' || *argv == '-')
		++i;
	while (ft_isdigit(argv[i]))
	{
		test = test * 10 + argv[i] - '0';
		if (test > INT_MAX)
			cw_usage("Too big number\n", cw);
		i++;
	}
	if (argv[i] || i > 10)
		cw_usage("Wrong number, try again later\n", cw);
}

static void	init_dump(t_cw *cw, int *i, int argc, char **argv)
{
	if (++*i >= argc)
		cw_usage("Syntax error, pls set dump\n", cw);
	cw_check_int(argv[*i], cw);
	cw->isdump = 1;
	cw->dump = ft_atoi(argv[*i]);
}

void		cw_read_args_flags(t_cw *cw, int argc, char **argv, int *i)
{
	int num;

	num = 0;
	if (ft_strequ(argv[*i], "-v"))
		cw->visual = 1;
	else if (ft_strequ(argv[*i], "-n"))
	{
		if (++*i >= argc)
			cw_usage("Syntax error, pls set number\n", cw);
		cw_check_int(argv[*i], cw);
		if ((num = ft_atoi(argv[*i])) >= 0 || num < -MAX_PLAYERS)
			cw_usage("Too many champions\n", cw);
		cw_flags_n_checkall(cw, num);
		if (++*i >= argc)
			cw_usage("Syntax error, pls set champ name\n", cw);
		cw_new_ch(cw);
		cw->ch[cw->chcount - 1].isnum = 1;
		cw->ch[cw->chcount - 1].file = argv[*i];
		cw->ch[cw->chcount - 1].num = num;
	}
	else if (ft_strequ(argv[*i], "-dump"))
		init_dump(cw, i, argc, argv);
}
