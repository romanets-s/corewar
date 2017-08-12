#include "asm.h"
#include <stdio.h>

void	error(t_asm *bin, int *i)
{
	printf("wtf bro\n");



	exit(0);
}

void    labels(t_asm *bin)
{

}



int     op_byte(t_asm *bin, int n)
{

}

void    operations(t_asm *bin, int n)
{

}

int     chech_op(t_asm *bin)
{
    int n;
    size_t len;

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

int    check_label(t_asm *bin)
{
    if (chech_op(bin))
        return (1);
    while (label_chars(bin->file[bin->i]))
        bin->i++;
    if (bin->file[bin->i] == LABEL_CHAR)
    {
        labels(bin);
        return (1);
    }
    return (0);
}

void	code(t_asm *bin)
{
	while (bin->file[bin->i])
	{
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