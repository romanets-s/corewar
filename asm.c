#include "asm.h"
#include <stdio.h>

void	error(t_asm *bin, int *i)
{
    printf("wtf bro\n");

    exit(0);
}


int     len_label(t_asm *bin, int flag)
{
    int len;

    len = 0;
    while (label_chars(bin->file[bin->i]))
    {
        bin->i++;
        len++;
    }
    if (flag == 1 && bin->file[bin->i] == LABEL_CHAR)
        bin->i++;
    else if (flag == 0)
        return (len);
    else
        error(bin, &bin->i);
    return (len);
}

char    *name_label(t_asm *bin, int flag)
{
//    int len;
//    char *str;
//    int n;
//
//    len = len_rev(bin->file, bin->i);
//    str = ft_strnew((size_t)len);
//    n = -1;

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

void    reg_func(t_asm *bin, t_tmp *tmp, int s)
{
    tmp->arg[s] = T_REG;
    tmp->val[s] = (unsigned int)ft_atoi(bin->file + ++bin->i);
}

int     len_digit(char *str, int i)
{
    int len;

    len = 0;
    while (ft_isdigit(str[i++]))
        len++;
    return (len);
}

void    dir_func(t_asm *bin, t_tmp *tmp, int s)
{
    int i;

    i = 0;
    tmp->arg[s] = T_DIR;
    if (ft_isdigit(bin->file[++bin->i]))
    {
        tmp->val[s] = (unsigned int)ft_atoi(bin->file + bin->i);
        bin->i += len_digit(bin->file, bin->i);
    }
    else if (bin->file[bin->i] == LABEL_CHAR)
    {
        if ((i = search_label(bin->lebels, name_label(bin, 0))) != -1)
            tmp->val[s] = bin->code_i - i;
        else
            ;
    }
    else
        error(bin, &bin->i);
}

void    ind_func(t_asm *bin, t_tmp *tmp, int s)
{
    tmp->arg[s] = T_IND;
    if (ft_isdigit(bin->file[++bin->i]))
        tmp->val[s] = (unsigned int)ft_atoi(bin->file + bin->i);
    else if (bin->file[bin->i] == LABEL_CHAR)
    {
        if (search_label(bin->lebels, name_label(bin, 0)) != -1)
            ;
        else
            ;
    }
    else
        error(bin, &bin->i);
}

unsigned char codage(t_tmp *tmp)
{

}

void    write_big_code(t_asm *bin, t_tmp *tmp, int n)
{
    unsigned short int a;

    if (bin->op[tmp->n].size == 2 || tmp->arg[n] == T_IND)
    {

    }
    else
        ;
}

void    write_code(t_asm *bin, t_tmp *tmp)
{
    int n;

    n = -1;
    bin->code[bin->code_i++] = bin->op[tmp->n].hex;
    if (bin->op[tmp->n].cod)
        bin->code[bin->code_i++] = codage(tmp);
    while (++n < bin->op[tmp->n].argc)
    {
        if (tmp->arg[n] == T_REG)
            bin->code[bin->code_i++] = (unsigned char)tmp->val[n];
        else
            ;

    }
}

void    operations(t_asm *bin, int n)
{
    int s;
    t_tmp tmp[1];

    tmp->n = n;
    s = 0;
    while (bin->file[bin->i] != '\n' && bin->file[bin->i] != COMMENT_CHAR)
    {
        if (ft_stn(bin->file[bin->i]))
            while (ft_stn(bin->file[bin->i]))
                bin->i++;
        else if (bin->file[bin->i] == 'r' && (bin->op[n].argv[s] & T_REG) == T_REG)
            reg_func(bin, (t_tmp *)&tmp, s);
        else if (bin->file[bin->i] == DIRECT_CHAR && (bin->op[n].argv[s] & T_DIR) == T_DIR)
            dir_func(bin, (t_tmp *)&tmp, s);
        else if ((bin->file[bin->i] == LABEL_CHAR || ft_isdigit(bin->file[bin->i])) && (bin->op[n].argv[s] & T_IND) == T_IND)
            ind_func(bin, (t_tmp *)&tmp, s);
        else if (bin->file[bin->i] == SEPARATOR_CHAR)
        {
            s++;
            bin->i++;
        }
        else
            error(bin, &bin->i);
    }
    write_code(bin, (t_tmp *)&tmp);
}

int     check_op(t_asm *bin)
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

int    labels(t_asm *bin)
{
    bin->lebels = create_label(bin->lebels, name_label(bin, 1), bin->i, bin->code_i);

    if (check_op(bin))
        return (1);
    else if (bin->file[bin->i] == COMMENT_CHAR)
        comment(bin, &bin->i);
    else
        error(bin, &bin->i);
    return (0);
}

int    check_label(t_asm *bin)
{
    if (check_op(bin))
        return (1);
    if (label_chars(bin->file[bin->i]))
        return (labels(bin));
//    if (bin->file[bin->i] == LABEL_CHAR && )
//        return (1);
    return (0);
}

void	code(t_asm *bin)
{
	while (bin->file[bin->i])
	{
        while (ft_stn(bin->file[bin->i]))
            bin->i++;
        if (check_label(bin))
        {

            printf("wtf borooo\n");

            exit(0);
        }
        else
            error(bin, &bin->i);
	}
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
	name_and_comment(bin);


	printf("%s\n", bin->head.prog_name);
	printf("%s\n", bin->head.comment);

	code(bin);
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