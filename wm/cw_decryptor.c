/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_decryptor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 11:56:52 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/08/19 11:56:55 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

void	cw_decryptor(t_cw *cw)
{
	int		i;
	int		fd;
	char	*tmp;

	i = 0;
	while (i < cw->chcount)
	{
		if ((fd = open(cw->ch[i].file, O_RDONLY)) == -1)
			cw_usage("Bad file, my friend\n", cw);
		cw_decrypt_magic(fd, cw);
		tmp = cw_decrypt_name(fd, cw);
		cw->ch[i].name = ft_strdup(tmp);
		free(tmp);
		cw->ch[i].csize = cw_decrypt_cmd_size(fd, cw);
		tmp = cw_decrypt_comment(fd, cw);
		cw->ch[i].cmt = ft_strdup(tmp);
		free(tmp);
		cw_decrypt_commands(cw, i, 0, fd);
		if (close(fd) == -1)
			cw_usage("NO NO NO\n", cw);
		++i;
	}
}
