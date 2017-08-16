#include "asm.h"
#include <stdio.h>

void	error(t_asm *bin, int r, int error)
{
	int k;
	int n;
	int a;

	n = 0;
	k = 1;
	a = bin->i;
	if (error == 1)
		ft_printf("Syntax error in Name");
	else if(error == 2)
		ft_printf("Syntax error in Comment");
	else if(error == 3)
		ft_printf("No Name\n");
	else if(error == 4)
		ft_printf("No Comment\n");
	else if(error == 5)
		ft_printf("Syntax error - unexpected end of input (Perhaps you forgot to end with a newline ?)\n");
	else if(error == 6)
		ft_printf("Invalid parametr for instruction '%s'\n", bin->op[r].name);
	else if (error == 7)
	{
		ft_printf("No such label ");
		write(1, bin->ptr, ft_strlen(bin->ptr));
		ft_printf("\n");
	}
	while (a > -1)
		if (bin->file[a--] == '\n')
			k++;
	while (bin->file[bin->i--] != '\n')
		n++;
	if (error != 3 && error != 4 && error != 5 && error != 6 && error != 7 && error != 1 && error != 2)
		printf("Syntax error at token [%03d:%03d]\n", k, n);
	exit(0);
}

int	 len_label(t_asm *bin, int flag)
{
	int len;

	len = 0;
	bin->kostyl = 0;
	while (label_chars(bin->file[bin->i]))
	{
		bin->i++;
		bin->kostyl++;
		len++;
	}
	if (flag == 1 && bin->file[bin->i] == LABEL_CHAR)
		bin->i++;
	else if (flag == 0)
		return (len);
	else
		error(bin, 0, 0);
	return (len);
}

char	*name_label(t_asm *bin, int flag)
{
	int len;
	char *str;
	int n;

	len = len_label(bin, flag);
	str = ft_strnew((size_t)len);
	n = -1;
	while (len != 0)
		str[++n] = bin->file[bin->i - len-- - flag];
	return (str);
}

t_label *create_label(t_label *first, char *name, int i, int code_i)
{
	t_label *tmp;

	tmp = (t_label *)malloc(sizeof(t_label));
	tmp->name = ft_strdup(name);
	tmp->i = i;
	tmp->code_i = code_i;
	tmp->next = first;
	return (tmp);
}

int search_label(t_label *l, char *name)
{
	while (l != NULL)
	{
		if (ft_strequ(l->name, name))
		{
			ft_strdel(&name);
			return (l->code_i);
		}
		l = l->next;
	}
	ft_strdel(&name);
	return (-1);
}

t_tmp   *create_tmp(int n)
{
	t_tmp   *tmp;
	int	 i;

	if ((tmp = (t_tmp *)malloc(sizeof(t_tmp))) == NULL)
		return (NULL);
	tmp->n = n;
	tmp->argc = 0;
	tmp->arg = (unsigned char *)malloc(sizeof(unsigned char) * 3);
	tmp->val = (unsigned int *)malloc(sizeof(unsigned int) * 3);
	i = -1;
	while (++i < 3)
	{
		tmp->arg[i] = 0;
		tmp->val[i] = 0;
	}
	return (tmp);
}

void	free_tmp(t_tmp *tmp)
{
	if (tmp)
	{
		if (tmp->val)
			free(tmp->val);
		if (tmp->arg)
			free(tmp->arg);
		free(tmp);
	}
}

t_insert	*create_insert(t_insert *first, char *label, int code_i, int arg, t_tmp *op)
{
	t_insert	*insert;
	int		 i;

	insert = (t_insert *)malloc(sizeof(t_insert));
	insert->label = label;
	insert->code_i = code_i;
	insert->arg = arg;
	insert->op = create_tmp(op->n);
	insert->op->argc = op->argc;
	i = -1;
	while (++i < 3)
	{
		insert->op->arg[i] = op->arg[i];
		insert->op->val[i] = op->val[i];
	}
	insert->next = first;
	return (insert);
}

int	 len_digit(char *str, int i)
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

void	reg_func(t_asm *bin, t_tmp *tmp, int s)
{
	if ((bin->op[tmp->n].argv[s] & T_REG) != T_REG)
		error(bin, tmp->n, 6);
	tmp->arg[s] = T_REG;
	if ((tmp->val[s] = (unsigned int)ft_atoi(bin->file + ++bin->i)) > REG_NUMBER)
		error(bin, 0, 0);
	bin->i += len_digit(bin->file, bin->i);
	tmp->argc++;
}

void	dir_func(t_asm *bin, t_tmp *tmp, int s)
{
	int i;

	i = 0;
	if ((bin->op[tmp->n].argv[s] & T_DIR) != T_DIR)
		error(bin, tmp->n, 6);
	tmp->arg[s] = T_DIR;
	if (ft_isdigit(bin->file[++bin->i]) || bin->file[bin->i] == '-')
	{
		tmp->val[s] = (unsigned int)ft_atoi(bin->file + bin->i);
		bin->i += len_digit(bin->file, bin->i);
	}
	else if (bin->file[bin->i++] == LABEL_CHAR)
	{
		if ((i = search_label(bin->lebels, name_label(bin, 0))) != -1)
			tmp->val[s] = i - bin->code_i;
		else
		{
			bin->i -= bin->kostyl;
			bin->insert = create_insert(bin->insert, name_label(bin, 0), bin->code_i, s, tmp);
			tmp->val[s] = 0;
		}
	}
	else
	{
		bin->i -= 2;
		error(bin, 0, 0);
	}
	tmp->argc++;
}

void	ind_func(t_asm *bin, t_tmp *tmp, int s)
{
	int i;

	i = 0;
	if ((bin->op[tmp->n].argv[s] & T_IND) != T_IND)
		error(bin, tmp->n, 6);
	tmp->arg[s] = T_IND;
	if (ft_isdigit(bin->file[bin->i]))
	{
		tmp->val[s] = (unsigned int)ft_atoi(bin->file + bin->i);
		bin->i += len_digit(bin->file, bin->i);
	}
	else if (bin->file[bin->i++] == LABEL_CHAR)
	{
		if ((i = search_label(bin->lebels, name_label(bin, 0))) != -1)
			tmp->val[s] = i - bin->code_i;
		else
		{
			bin->i -= bin->kostyl;
			bin->insert = create_insert(bin->insert, name_label(bin, 0), bin->code_i, s, tmp);
			tmp->val[s] = 0;
		}
	}
	else
		error(bin, 0, 0);
	tmp->argc++;
}


void	write_big_code(t_asm *bin, t_tmp *tmp, int s)
{
	int len;

	len = -1;
	if (bin->op[tmp->n].size == 2 || tmp->arg[s] == T_IND)
	{
		tmp->val[s] = (unsigned short int)tmp->val[s];
		bin->code[bin->code_i++] = (unsigned char)(tmp->val[s] >> 8);
		tmp->val[s] = tmp->val[s] << 24;
		bin->code[bin->code_i++] = (unsigned char)(tmp->val[s] >> 24);
	}
	else
	{
		while (++len < 4)
		{
			bin->code[bin->code_i++] = (unsigned char)(tmp->val[s] >> 24);
			tmp->val[s] = tmp->val[s] << 8;
		}
	}
}


unsigned char codage(t_tmp *tmp)
{
	unsigned char n;
	int i;

	i = -1;
	n = 0;
	while (++i < 3)
	{
		if (tmp->arg[i] == T_IND)
			tmp->arg[i] = 3;
		n += tmp->arg[i];
		n = n << 2;
	}
	return (n);
}

void	write_code(t_asm *bin, t_tmp *tmp)
{
	int s;

	s = -1;
	bin->code[bin->code_i++] = bin->op[tmp->n].hex;
	if (bin->op[tmp->n].cod)
		bin->code[bin->code_i++] = codage(tmp);
	while (++s < bin->op[tmp->n].argc)
	{
		if (tmp->arg[s] == T_REG)
			bin->code[bin->code_i++] = (unsigned char)tmp->val[s];
		else
			write_big_code(bin, tmp, s);
	}
	free_tmp(tmp);
}



void	operations(t_asm *bin, int n)
{
	int s;
	t_tmp *tmp;

	tmp = create_tmp(n);

	s = 0;
	while (bin->file[bin->i] != '\n' && bin->file[bin->i] != COMMENT_CHAR)
	{
		if (ft_stn(bin->file[bin->i]))
			while (ft_stn(bin->file[bin->i]))
				bin->i++;
		else if (bin->file[bin->i] == 'r')
			reg_func(bin, tmp, s);
		else if (bin->file[bin->i] == DIRECT_CHAR)
			dir_func(bin, tmp, s);
		else if ((bin->file[bin->i] == LABEL_CHAR || ft_isdigit(bin->file[bin->i])))
			ind_func(bin, tmp, s);
		else if (bin->file[bin->i] == SEPARATOR_CHAR)
		{
			s++;
			bin->i++;
		}
		else
			bin->file[bin->i] == '\0' ? error(bin, 0, 5) : error(bin, 0, 0);
	}
	tmp->argc == bin->op[n].argc ? 1 : error(bin, 0, 0);
	write_code(bin, tmp);
}

int	 check_op(t_asm *bin)
{
	int n;
	size_t len;

	while (ft_stn(bin->file[bin->i]))
		bin->i++;
	n = -1;
	while (++n < OPERATIONS_NUM)
	{
		len = ft_strlen(bin->op[n].name);
		if (ft_strnequ(bin->op[n].name, bin->file + bin->i, len) && (ft_stn(bin->file[bin->i + len]) || bin->file[bin->i + len] == DIRECT_CHAR))
		{
			bin->i += len;
			operations(bin, n);
			return (1);
		}
	}
	return (0);
}

int	labels(t_asm *bin)
{
	bin->lebels = create_label(bin->lebels, name_label(bin, 1), bin->i, bin->code_i);

	if (check_op(bin))
		return (1);
	else if (bin->file[bin->i] == COMMENT_CHAR)
	{
		comment(bin, &bin->i);
		if (bin->file[bin->i] == '\0' && bin->file[bin->i - 1] != '\n')
			error(bin, 0, 0);
		return (1);
	}
	else if (bin->file[bin->i] == '\n')
		return (1);
	else
		error(bin, 0, 0);
	return (0);
}

int	check_label(t_asm *bin)
{
	if (check_op(bin))
		return (1);
	if (label_chars(bin->file[bin->i]))
		return (labels(bin));
	return (0);
}

void	insert_code_2(t_asm *bin, t_insert *tmp, int tab, unsigned int val)
{
	int len;

	len = -1;
	if (bin->op[tmp->op->n].size == 2 || tmp->op->arg[tmp->arg] == T_IND)
	{
		val = (unsigned short int)val;
		bin->code[tmp->code_i++ + tab] = (unsigned char)(val >> 8);
		val = val << 24;
		bin->code[tmp->code_i + tab] = (unsigned char)(val >> 24);
	}
	else
	{
		while (++len < 4)
		{
			bin->code[tmp->code_i++ + tab] = (unsigned char)(val >> 24);
			val = val << 8;
		}
	}
}

void	insert_code_1(t_asm *bin, t_insert *tmp, int label_i)
{
	unsigned int val;
	int		 tab;
	int		 n;

	val = (unsigned int)label_i - tmp->code_i;
	tab = 1;
	if (tmp->arg != 0)
		tab++;
	if (bin->op[bin->insert->op->n].cod == 1)
		tab++;
	n = -1;
	while (++n < tmp->arg)
	{
		if (tmp->op->arg[n] == T_REG)
			tab++;
		else if (tmp->op->arg[n] == T_IND || (tmp->op->arg[n] == T_DIR && bin->op[tmp->op->n].size == 2))
			tab += 2;
		else if (tmp->op->arg[n] == T_DIR && bin->op[tmp->op->n].size == 4)
			tab += 4;
	}
	insert_code_2(bin, tmp, tab, val);
}

void search_insert(t_asm *bin)
{
	t_insert *tmp;
	int	 i;

	i = 0;
	tmp = bin->insert;
	while (tmp != NULL)
	{
		if ((i = search_label(bin->lebels, tmp->label)) != -1)
		{
			insert_code_1(bin, tmp, i);
		}
		else
		{
			bin->ptr = tmp->label;
			error(bin, 0, 7);
		}
		tmp = tmp->next;
	}
}

void	code(t_asm *bin)
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
		{
			continue ;
		}
		else
			error(bin, 0, 0);
	}
	if (bin->insert != NULL)
		search_insert(bin);
}

void	write_int( unsigned int i, int fd)
{
	int n;
	unsigned char tmp;

	n = -1;
	while (++n < 4)
	{
		tmp = (unsigned char)(i >> 24);
		write(fd, &tmp, 1);
		i = i << 8;
	}
}

void	write_file(t_asm *bin, int tmp)
{
	int fd;
	int i;
	int zero;

	zero = 0;
	if ((fd = open(bin->file_name, O_CREAT|O_WRONLY, 0666)) == -1)
	{
		ft_putstr("Can't create file.\n");
		exit (0);
	}
	write_int(COREWAR_EXEC_MAGIC, fd);
	write(fd, bin->head.prog_name, PROG_NAME_LENGTH + 1);
	i = -1;
	if ((tmp = 4 - (PROG_NAME_LENGTH + 1) % 4) != 4)
		while (++i < tmp)
			write(fd, &zero, 1);
	write_int(bin->code_i, fd);
	write(fd, bin->head.comment, COMMENT_LENGTH + 1);
	i = -1;
	if ((tmp = 4 - (PROG_NAME_LENGTH + 1) % 4) != 4)
		while (++i < tmp)
			write(fd, &zero, 1);
	write(fd, bin->code, bin->code_i);
	close(fd);
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
	bin->file_name = file_name(old_name, ft_strlen(old_name));
	asm_init(bin);
	name_and_comment(bin);
	code(bin);
    if (!bin->code_i && bin->lebels == NULL)
        error(bin, 0, 0);
	write_file(bin, 0);
}

int main(int c, char **v)
{

	int fd;
	t_asm bin[1];

    if (c > 1)
    {
        if ((fd = open(v[c - 1], O_RDONLY)) == -1)
            ft_printf("Can't read source file %s\n", v[c - 1]);
        else
        {
            go(fd, (t_asm *)&bin, v[1]);
            ft_printf("Writing output program to %s\n", v[c - 1]);
        }
    }
    else
        ft_printf("Usage: ./tmp/asm [-a] <sourcefile.s>\n    -a : Instead of creating a .cor file, "
                          "outputs a stripped and annotated version of the code to the standard output\n");
	return 0;
}
