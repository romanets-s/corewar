/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_put_inmem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:54:06 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/08/19 14:54:08 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

void	cw_put_inmem(t_cw *cw, unsigned int w, unsigned int i)
{
	int j;

	j = -1;
	while (++j < 4)
	{
		cw->vm.mem[cw_real_ptr(w + j)] = (unsigned char)(i >> 24);
		i = i << 8;
	}
}
