/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_vis_cps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 06:41:12 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/08/21 06:41:13 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

void	cw_vis_cps_up(t_cw *cw)
{
	if (cw->vis.cps == 1000)
		return ;
	++cw->vis.cps;
	mvprintw(cw->vis.vids + cw->chrc * 3 + 10, cw->vis.width - SUB_MENU,
		" CYCLES PER SECOND: %d            ", cw->vis.cps);
}

void	cw_vis_cps_down(t_cw *cw)
{
	if (cw->vis.cps == 1)
		return ;
	--cw->vis.cps;
	mvprintw(cw->vis.vids + cw->chrc * 3 + 10, cw->vis.width - SUB_MENU,
		" CYCLES PER SECOND: %d            ", cw->vis.cps);
}
