/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vis_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 06:42:03 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/08/21 06:42:04 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

void	cw_vis_output(t_cw *cw, int x, int y)
{
	int		i;
	int		xx;

	i = 0;
	while (i < MEM_SIZE)
	{
		xx = x;
		while ((i + 1) % VM_MEM_INLINE != 0)
		{
			attron(COLOR_PAIR(9));
			mvprintw(y, xx, "%.2x ", cw->vm.mem[i]);
			attroff(COLOR_PAIR(9));
			xx += 3;
			i++;
		}
		if (i >= MEM_SIZE)
			return ;
		attron(COLOR_PAIR(9));
		mvprintw(y, xx, "%.2x ", cw->vm.mem[i]);
		attroff(COLOR_PAIR(9));
		y += 1;
		++i;
	}
	cw_vis_pc(cw);
	refresh();
}
