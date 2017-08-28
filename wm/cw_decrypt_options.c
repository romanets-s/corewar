/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_decrypt_options.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 12:05:42 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/08/19 12:05:44 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

void	cw_decrypt_magic(int fd, t_cw *cw)
{
	unsigned char	*buff;
	int				i;
	int				incr;
	int				magic;

	incr = 1;
	magic = 0;
	buff = ft_ustrnew(sizeof(unsigned char) * 4);
	if ((i = read(fd, buff, 4)) != 4)
		cw_usage("Pustyi file, rlly?\n", cw);
	i = 3;
	while (i > -1)
	{
		magic += (buff[i] % 16) * incr;
		incr *= 16;
		magic += (buff[i] >> 4) * incr;
		incr *= 16;
		--i;
	}
	free(buff);
	if (magic != COREWAR_EXEC_MAGIC)
		cw_usage("GG\n", cw);
}

char	*cw_decrypt_name(int fd, t_cw *cw)
{
	unsigned char	*buff;
	char			*name;
	int				i;

	name = ft_strnew(PROG_NAME_LENGTH + 1);
	buff = ft_ustrnew(sizeof(unsigned char) * PROG_NAME_LENGTH + 1);
	if ((i = read(fd, buff, PROG_NAME_LENGTH + 1)) != PROG_NAME_LENGTH + 1)
		cw_usage("Pustyi file, rlly?\n", cw);
	i = 0;
	while (i < PROG_NAME_LENGTH)
	{
		name[i] = (buff[i] % 16);
		name[i] += (buff[i] / 16) * 16;
		++i;
	}
	name[i] = 0;
	if (buff[i] != 0)
		cw_usage("Friend but last bite of prog's name must be 0\n", cw);
	lseek(fd, 4 - ((PROG_NAME_LENGTH + 1) % 4), SEEK_CUR);
	free(buff);
	return (name);
}

int		cw_decrypt_cmd_size(int fd, t_cw *cw)
{
	unsigned char	*buff;
	int				i;
	int				incr;
	int				csize;

	incr = 1;
	csize = 0;
	buff = ft_ustrnew(sizeof(unsigned char) * 4);
	if ((i = read(fd, buff, 4)) != 4)
		cw_usage("Bad cmd size\n", cw);
	i = 3;
	while (i > -1)
	{
		csize += (buff[i] % 16) * incr;
		incr *= 16;
		csize += (buff[i] / 16) * incr;
		incr *= 16;
		--i;
	}
	free(buff);
	return (csize);
}

char	*cw_decrypt_comment(int fd, t_cw *cw)
{
	unsigned char	*buff;
	char			*cmt;
	int				i;

	cmt = ft_strnew(COMMENT_LENGTH + 1);
	buff = ft_ustrnew(sizeof(unsigned char) * COMMENT_LENGTH + 1);
	if ((i = read(fd, buff, COMMENT_LENGTH + 1)) != COMMENT_LENGTH + 1)
		cw_usage("Bad comment size friend\n", cw);
	i = 0;
	while (i < COMMENT_LENGTH)
	{
		cmt[i] = (buff[i] % 16);
		cmt[i] += (buff[i] / 16) * 16;
		++i;
	}
	cmt[i] = 0;
	if (buff[i] != 0)
		cw_usage("Friend last bite of prog's comment must be 0\n", cw);
	lseek(fd, 4 - ((COMMENT_LENGTH + 1) % 4), SEEK_CUR);
	free(buff);
	return (cmt);
}

void	cw_decrypt_commands(t_cw *cw, int z, int j, int fd)
{
	int				i;
	char			*tab;
	unsigned char	*buff;

	tab = "0123456789abcdef";
	cw->ch[z].cmd = ft_strnew(cw->ch[z].csize * 2 + 1);
	cw->ch[z].ucmd = ft_ustrnew(cw->ch[z].csize + 1);
	buff = ft_ustrnew(sizeof(unsigned char) * cw->ch[z].csize + 1);
	if ((i = read(fd, buff, cw->ch[z].csize + 1)) != cw->ch[z].csize)
		cw_usage("Bad command size friend\n", cw);
	i = 0;
	while (j < cw->ch[z].csize)
	{
		cw->ch[z].ucmd[j] = buff[j];
		cw->ch[z].cmd[i] += tab[buff[j] >> 4];
		cw->ch[z].cmd[i + 1] = tab[buff[j] % 16];
		i += 2;
		j++;
	}
	if (j > CHAMP_MAX_SIZE || buff[j] != 0)
		cw_usage("Your command is to big for me ( ͡° ͜ʖ ͡°)\n", cw);
	cw->ch[z].ucmd[j] = 0;
	cw->ch[z].cmd[i] = 0;
	free(buff);
}
