/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 19:14:09 by sromanet          #+#    #+#             */
/*   Updated: 2017/08/02 19:14:40 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static char		*ft_new_strjoin(char *s1, char const *s2)
{
	char *fresh;
	char *ptr;
	char *tmp;

	tmp = NULL;
	fresh = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (fresh)
	{
		tmp = fresh;
		if (s1)
		{
			ptr = s1;
			while (*s1)
				*(fresh++) = *(s1++);
			free(ptr);
			s1 = NULL;
		}
		if (s2)
			while (*s2)
				*(fresh++) = *(s2++);
		*fresh = '\0';
	}
	return (tmp);
}

static int		search_line(char **line, t_line *lst, char *buf, int flag)
{
	char *ptr;
	char *new;

	ptr = NULL;
	if (!lst->str || (!(*lst->str) && !(*buf)))
		return (0);
	if ((ptr = ft_strchr(lst->str, '\n')) && flag == 0)
	{
		*ptr = '\0';
		*line = ft_strdup(lst->str);
		new = ft_strdup(ptr + 1);
		free(lst->str);
		lst->str = new;
		ptr = NULL;
		return (1);
	}
	else if (flag == 1)
	{
		*line = ft_strdup(lst->str);
		free(lst->str);
		lst->str = NULL;
		return (1);
	}
	return (0);
}

static int		next_line(t_line *lst, char **line, const int fd, char buf[])
{
	size_t	n;

	if (search_line(line, lst, buf, 0))
		return (1);
	while ((n = read(fd, buf, BUFF_SIZE)))
	{
		buf[n] = '\0';
		if (!lst->str)
			lst->str = ft_strnew(ft_strlen(buf));
		if (!(lst->str = ft_new_strjoin(lst->str, buf)))
			return (-1);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (search_line(line, lst, buf, 0))
		return (1);
	else if (n < BUFF_SIZE && (!lst->str || ft_strlen(lst->str) == 0))
		return (0);
	else if (search_line(line, lst, buf, 1))
		return (1);
	return (0);
}

static t_line	*ft_create_new_list(t_line *lst, const int fd)
{
	t_line *tmp;

	tmp = (t_line *)malloc(sizeof(t_line));
	tmp->fd = fd;
	tmp->str = NULL;
	tmp->next = lst;
	lst = tmp;
	return (lst);
}

int				get_next_line(const int fd, char **line)
{
	static t_line	*lst = NULL;
	t_line			*tmp;
	char			buf[BUFF_SIZE + 1];

	if (read(fd, buf, 0) < 0)
		return (-1);
	tmp = lst;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (next_line(lst, line, fd, buf));
		tmp = tmp->next;
	}
	if (!tmp)
		lst = ft_create_new_list(lst, fd);
	return (next_line(lst, line, fd, buf));
}
