#include "corewar.h"
#include <stdio.h>

char	*strjoin_and_free(char *s1, char *s2)
{
	char *fresh;
	char *ptr;
	char *tmp;

	tmp = NULL;
	fresh = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (fresh)
	{
		tmp = fresh;
		ptr = s1;
		while (*s1)
			*(fresh++) = *(s1++);
		*(fresh++) = '\n';
		ft_strdel(&ptr);
		ptr = s2;
		s1 = NULL;
		while (*s2)
			*(fresh++) = *(s2++);
		*fresh = '\0';
		ft_strdel(&ptr);
		s2 = NULL;
	}
	return (tmp);
}

char	*file_name(char *name, size_t len)
{
	char	*tmp;
	int	 i;

	tmp = ft_strnew(len + 3);
	i = -1;
	while (++i < len - 1)
		tmp[i] = name[i];
	tmp[i] = 'c';
	tmp[++i] = 'o';
	tmp[++i] = 'r';
	return (tmp);
}


void	write_magic(t_asm *bin, unsigned int magic)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		bin->code[i] = (unsigned char)(magic >> 24);
		magic = magic << 8;
	}
}

void	error(t_asm *bin, int *i)
{
	printf("wtf bro\n");



	exit(0);
}

void	comment(t_asm *bin, int *i)
{
	while (bin->file[*i] != '\n')
		(*i)++;
}

int	 ft_stn(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

void	commands_date(t_asm *bin, int *i, int max_len, char *str)
{
	int n;

	while (ft_stn(bin->file[*i]) && bin->file[*i] != '\n')
		(*i)++;
	n = -1;
	if (bin->file[*i] == '"')
	{
		while (bin->file[++(*i)] != '"' && ++n < max_len)
			str[n] = bin->file[*i];
		str[++n] = '\0';
		if (bin->file[*i] == '"')
		{
			while (bin->file[*i])
			{
				if (bin->file[(*i)++] == '\n')
					return ;
				if (ft_stn(bin->file[*i]))
					continue ;
				else if (bin->file[*i] == COMMENT_CHAR)
					comment(bin, i);
				else
					break ;
			}
		}
	}
	error(bin, i);
}

void	commands(t_asm *bin, int *i)
{
	if (ft_strnequ(bin->file + *i, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) && !bin->name)
	{
		*i += ft_strlen(NAME_CMD_STRING);
		bin->name = 1;
		commands_date(bin, i, PROG_NAME_LENGTH, (char *)&bin->head.prog_name);
	}
	else if (ft_strnequ(bin->file + *i, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)) && !bin->comm)
	{
		*i += ft_strlen(COMMENT_CMD_STRING);
		bin->comm = 1;
		commands_date(bin, i, COMMENT_LENGTH, (char *)&bin->head.comment);
	}
	else
		error(bin, i);
}

void	name_and_comment(t_asm *bin)
{
	int i;

	i = 1;
	while (bin->file[i])
	{
		if (bin->name && bin->comm)
			break ;
		if (ft_stn(bin->file[i]))
			i++;
		else if (bin->file[i] == '.')
			commands(bin, &i);
		else if (bin->file[i] == COMMENT_CHAR)
			comment(bin, &i);
		else
			error(bin, &i);
	}
	while (ft_stn(bin->file[i]) || bin->file[i] == COMMENT_CHAR)
	{
		if (bin->file[i] == COMMENT_CHAR)
			comment(bin, &i);
		i++;
	}
	bin->i = i;
}

int	 label_chars(char c)
{
	if (ft_strchr(LABEL_CHARS, c) != NULL)
		return (1);
	return (0);
}

void	operations(t_asm *bin)
{
	while (bin->file[bin->i])
	{
		while (label_chars(bin->file[bin->i]))
			bin->i++;
		if (bin->file[bin->i] == LABEL_CHAR)
			;
		else
			error(bin, &bin->i);
	}
}

void	op_init(t_asm *bin)
{
	*bin = (t_asm){{
						{"live", 1, (char**)(&"T_DIR"), 0, 1, 4},
						{"live", 1, (char**)(&"T_DIR"), 0, 1, 4},
						{"live", 1, (char**)(&"T_DIR"), 0, 1, 4},
						{"live", 1, (char**)(&"T_DIR"), 0, 1, 4},
						{"live", 1, (char**)(&"T_DIR"), 0, 1, 4},
						{"live", 1, (char**)(&"T_DIR"), 0, 1, 4},
						{"live", 1, (char**)(&"T_DIR"), 0, 1, 4},
						{"live", 1, (char**)(&"T_DIR"), 0, 1, 4},
						{"live", 1, (char**)(&"T_DIR"), 0, 1, 4},
						{"live", 1, (char**)(&"T_DIR"), 0, 1, 4},
						{"live", 1, (char**)(&"T_DIR"), 0, 1, 4},
						{"live", 1, (char**)(&"T_DIR"), 0, 1, 4},
						{"live", 1, (char**)(&"T_DIR"), 0, 1, 4},
						{"live", 1, (char**)(&"T_DIR"), 0, 1, 4},
						{"live", 1, (char**)(&"T_DIR"), 0, 1, 4},
						{"live", 1, (char**)(&"T_DIR"), 0, 1, 4},
						{0, 0, 0, 0, 0, 0}
				   }, bin->file, bin->i, bin->code, bin->code_size, .name = bin->name,
			.comm = bin->comm, .file_name = bin->file_name, .head = bin->head};
}

void	asm_init(t_asm *bin)
{
	bin->name = 0;
	bin->comm = 0;

	bin->head.magic = COREWAR_EXEC_MAGIC;
//	bin->code_size = sizeof(bin->head.magic) + PROG_NAME_LENGTH + 1 + 4 - ((PROG_NAME_LENGTH + 1) % 4) + 4
//					 + COMMENT_LENGTH + 1 + 4 - ((COMMENT_LENGTH + 1) % 4);
//	bin->code = (unsigned char *)ft_strnew(bin->code_size);
//	write_magic(bin, COREWAR_EXEC_MAGIC);
	name_and_comment(bin);
	op_init(bin);

	printf("%s\n", bin->head.prog_name);
	printf("%s\n", bin->head.comment);

	operations(bin);


}

void	go(int fd, t_asm *bin, char *old_name)
{
	char *line;

	line = NULL;
	bin->file = ft_strnew(0);
	while (get_next_line(fd, &line) == 1)
		bin->file = strjoin_and_free(bin->file, line);
	close(fd);



	printf("%s\n<==============>\n", bin->file);


	bin->file_name = file_name(old_name, ft_strlen(old_name));
	asm_init(bin);
}

int main(int c, char **v)
{
	int fd;
	t_asm bin[1];

	if ((fd = open(v[1], O_RDONLY)) == -1)
	{
		ft_putstr("Can't open file.\n");
	}
	else
		go(fd, (t_asm *)&bin, v[1]);
	return 0;
}