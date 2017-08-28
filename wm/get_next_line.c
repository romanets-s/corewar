/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irepeta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 16:12:54 by irepeta           #+#    #+#             */
/*   Updated: 2016/12/17 16:12:56 by irepeta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_check(char **tmp, char **line, char **buf)
{
	char *ptr;
	char *nov;

	if ((ptr = ft_strchr(*tmp, '\n')))
	{
		*ptr = '\0';
		*line = ft_strdup(*tmp);
		nov = ft_strdup(ptr + 1);
		free(*tmp);
		*tmp = nov;
		ptr = NULL;
		*buf ? free(*buf) : 0;
		return (1);
	}
	return (0);
}

static void		ft_freemepls(char **tmp, char **buf)
{
	*tmp ? free(*tmp) : 0;
	*tmp = NULL;
	*buf ? free(*buf) : 0;
}

int				get_next_line(const int fd, char **line)
{
	static char *tmp = NULL;
	char		*buf;
	int			ret;

	buf = NULL;
	if ((ret = read(fd, buf, 0)) == -1 || (tmp && ft_check(&tmp, line, &buf)))
		return (ret == -1 ? -1 : 1);
	buf = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strrjoin(tmp, buf);
	}
	if (ret == -1 || tmp == NULL || (!(*tmp) && !(*buf)))
	{
		ft_freemepls(&tmp, &buf);
		return (ret == -1 ? -1 : 0);
	}
	if (ft_check(&tmp, line, &buf))
		return (1);
	buf ? free(buf) : 0;
	*line = ft_strdup(tmp);
	free(tmp);
	tmp = NULL;
	return (1);
}
