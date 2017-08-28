/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 07:10:08 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/08/21 07:10:09 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

int		main(int argc, char **argv)
{
	t_cw	cw;

	cw_struct_null(&cw);
	cw_read_args(&cw, argc, argv);
	cw_decryptor(&cw);
	cw_prefight(&cw, 0);
	if (cw.visual)
		cw_pre_visual(&cw, -1, MEM_SIZE / VM_MEM_INLINE);
	cw_battle(&cw);
	return (0);
}
