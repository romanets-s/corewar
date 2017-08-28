/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sromanet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 20:49:21 by sromanet          #+#    #+#             */
/*   Updated: 2017/08/17 20:49:24 by sromanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				len_digit(char *str, int i)
{
	int len;

	len = 0;
	if (str[i] == '-')
	{
		len++;
		i++;
	}
	while (ft_isdigit(str[i++]))
		len++;
	return (len);
}

unsigned char	codage(t_tmp *tmp)
{
	unsigned char	n;
	int				i;

	i = -1;
	n = 0;
	while (++i < 3)
	{
		if (tmp->arg[i] == T_IND)
			n += tmp->arg[i] - 1;
		else
			n += tmp->arg[i];
		n = n << 2;
	}
	return (n);
}

void			code(t_asm *bin)
{
	while (bin->file[bin->i])
	{
		while (ft_stn(bin->file[bin->i]) || bin->file[bin->i] == '\n')
			bin->i++;
		if (bin->file[bin->i] == COMMENT_CHAR)
			comment(bin, &bin->i);
		if (bin->file[bin->i] == '\0')
			break ;
		if (check_label(bin))
			continue ;
		else if (bin->file[bin->i] == '\n')
			bin->i++;
		else if (bin->file[bin->i] == COMMENT_CHAR)
			comment(bin, &bin->i);
		else
			error(bin, 0, 0);
	}
	if (bin->insert != NULL)
		search_insert(bin);
}

void			go(int fd, t_asm *bin, char *old_name)
{
	char	line[BUFF_SIZE];
	ssize_t	n;

	asm_init(bin);
	bin->file = ft_strnew(0);
	while ((n = read(fd, line, BUFF_SIZE)) > 0)
	{
		line[n] = '\0';
		bin->file = ft_new_strjoin(bin->file, line);
	}
	if (n < 0)
		error(bin, 0, 8);
	close(fd);
	bin->file_name = file_name(old_name, ft_strlen(old_name));
	name_and_comment(bin);
	code(bin);
	if (!bin->code_i && bin->lebels == NULL)
		error(bin, 0, 0);
	write_file(bin, 0);
}

int				main(int c, char **v)
{
	int		fd;
	int		i;
	t_asm	bin[1];

	if (c > 1)
	{
		if ((fd = open(v[c - 1], O_RDONLY)) == -1)
			ft_printf("Can't read source file %s\n", v[c - 1]);
		else
		{
			i = ft_strlen(v[c - 1]);
			if (v[c - 1][i - 1] != 's' && v[c - 1][i - 2] != '.')
				error(bin, 0, 9);
			go(fd, (t_asm *)&bin, v[1]);
			ft_printf("Writing output program to %s\n", bin->file_name);
		}
	}
	else
		ft_printf("Usage: ./asm <sourcefile.s>\n");
	return (0);
}
