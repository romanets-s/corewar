#include "corewar.h"
#include <stdio.h>

char		*ft_new_strjoin(char *s1, char const *s2)
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
            ft_strdel(&ptr);
            s1 = NULL;
        }
        if (s2)
            while (*s2)
                *(fresh++) = *(s2++);
        *fresh = '\0';
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
	if (c == ' ' || c == '\t')
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
				if (ft_stn(bin->file[*i]) || bin->file[*i] == '\n')
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

	i = 0;
	while (bin->file[i])
	{
		if (bin->name && bin->comm)
			break ;
		if (ft_stn(bin->file[i]) || bin->file[i] == '\n')
			i++;
		else if (bin->file[i] == '.')
			commands(bin, &i);
		else if (bin->file[i] == COMMENT_CHAR)
			comment(bin, &i);
		else
			error(bin, &i);
	}
	while (ft_stn(bin->file[i]) || bin->file[i] == '\n' || bin->file[i] == COMMENT_CHAR)
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



int    check_op(t_asm *bin)
{
    int n;
    size_t len;

    n = -1;
    while (++n < OPERATIONS_NUM)
    {
        len = ft_strlen(bin->op[n].name);
        if (ft_strnequ(bin->op[n].name, bin->file + bin->i, len) && (ft_stn(bin->file[bin->i + len]) || bin->file[bin->i + len] == DIRECT_CHAR))
        {
            //go to operation func
            bin->tmp = n;
            return (1);
        }
    }
    while (label_chars(bin->file[bin->i]))
        bin->i++;
    if (bin->file[bin->i] == ':')
    {
        //wtf bro, go to label func
        return (1);
    }
    return (0);
}

void	lable(t_asm *bin)
{
	while (bin->file[bin->i])
	{
        if (check_op(bin))
        {

            printf("wtf borooo\n");
            bin->tmp = -1;
            exit(0);
        }
        else
            error(bin, &bin->i);
	}
}

void	op_init(t_asm *bin)
{
	*bin = (t_asm){{
						{"live",	1, {T_DIR}, 0, 1, 4},
						{"ld",		2, {T_DIR | T_IND, T_REG}, 1, 2, 4},
						{"st",		2, {T_REG, T_IND | T_REG}, 1, 3, 0},
						{"add",		3, {T_REG, T_REG, T_REG}, 1, 4, 0},
						{"sub",		3, {T_REG, T_REG, T_REG}, 1, 5, 0},
						{"and",		3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 1, 6, 4},
						{"or",		3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 1, 7, 4},
						{"xor",		3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 1, 8, 4},
						{"zjmp",	1, {T_DIR}, 0, 9, 2},
						{"ldi",		3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 1, 10, 2},
						{"sti",		3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 1, 11, 2},
						{"fork",	1, {T_DIR}, 0, 12, 2},
						{"lld",		2, {T_DIR | T_IND, T_REG}, 1, 13, 4},
						{"lldi",	3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 1, 14, 2},
						{"lfork",	1, {T_DIR}, 0, 15, 2},
						{"aff",		1, {T_REG}, 1, 16, 0},
						{0, 0, 0, 0, 0, 0}
                   }, bin->file, bin->i, bin->code, bin->code_size, .name = bin->name,
			.comm = bin->comm, .file_name = bin->file_name, .head = bin->head};
}

void	asm_init(t_asm *bin)
{
    op_init(bin);
	bin->name = 0;
	bin->comm = 0;
    bin->buff_size = BUFF_SIZE;
    bin->code = (unsigned char *)malloc(sizeof(unsigned char) * bin->buff_size);


	bin->head.magic = COREWAR_EXEC_MAGIC;
//	bin->code_size = sizeof(bin->head.magic) + PROG_NAME_LENGTH + 1 + 4 - ((PROG_NAME_LENGTH + 1) % 4) + 4
//					 + COMMENT_LENGTH + 1 + 4 - ((COMMENT_LENGTH + 1) % 4);
//	bin->code = (unsigned char *)ft_strnew(bin->code_size);
//	write_magic(bin, COREWAR_EXEC_MAGIC);
	name_and_comment(bin);


	printf("%s\n", bin->head.prog_name);
	printf("%s\n", bin->head.comment);

    lable(bin);


}

void	go(int fd, t_asm *bin, char *old_name)
{
	char line[4096];
    ssize_t n;

	bin->file = ft_strnew(0);
    while ((n = read(fd, line, 4096)))
    {
        line[n] = '\0';
        bin->file = ft_new_strjoin(bin->file, line);
    }
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