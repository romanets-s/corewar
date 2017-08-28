/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_read_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:54:29 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/08/19 14:54:30 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

static int	cw_get_min_num(t_cw *cw)
{
	int i;
	int j;
	int min;
	int tmp;

	min = -1;
	i = -1;
	while (++i < cw->chcount)
	{
		tmp = min;
		j = -1;
		while (++j < cw->chcount)
		{
			if (cw->ch[j].isnum && cw->ch[j].num == min)
			{
				--min;
				if (min == MAX_PLAYERS)
					cw_usage("Lol, idk why this happens\n", cw);
				break ;
			}
		}
		if (tmp == min)
			return (min);
	}
	return (min);
}

static void	cw_set_numbers(t_cw *cw)
{
	int i;

	i = cw->chcount - 1;
	while (i > -1)
	{
		if (!cw->ch[i].isnum)
		{
			cw->ch[i].num = cw_get_min_num(cw);
			cw->ch[i].isnum = 1;
		}
		--i;
	}
}

static void	cw_check_numb(t_cw *cw)
{
	int i;
	int j;
	int num;
	int temp;

	i = -1;
	num = -1;
	while (++i < cw->chcount)
	{
		temp = num;
		j = -1;
		while (++j < cw->chcount)
		{
			if (num == cw->ch[j].num)
			{
				--num;
				break ;
			}
		}
		if (temp == num)
			cw_usage("All bots must be in order (-1, -2, -3 etc.)\n", cw);
	}
}

void		cw_read_args(t_cw *cw, int argc, char **argv)
{
	int i;

	i = 1;
	if (argc == 1)
		cw_usage("Usage: corewar [-v] [-dump nbr_cycle] [[-n prog_number] "
						"prog_name]\n", cw);
	while (argv[i])
	{
		if (*argv[i] == '-')
			cw_read_args_flags(cw, argc, argv, &i);
		else
		{
			cw_new_ch(cw);
			cw->ch[cw->chcount - 1].file = argv[i];
		}
		i++;
	}
	if (!cw->chcount)
		cw_usage("Friend, we need champions!\n", cw);
	cw_set_numbers(cw);
	cw_check_numb(cw);
}
