#include "corewar.h"
#include <stdio.h>

void	new_ft_strjoin_2(char *fresh, char *s2)
{
    char *ptr2;

    if (s2)
    {
        ptr2 = s2;
        while (*s2)
            *(fresh++) = *(s2++);
        free(ptr2);
        s2 = NULL;
    }
}

char		*new_ft_strjoin(char *s1, char *s2)
{
    char	*fresh;
    char	*ptr1;
    char	*tmp;
    int		i;

    tmp = NULL;
    i = 0;
    if (s1)
        i += ft_strlen(s1);
    if (s2)
        i += ft_strlen(s2);
    fresh = ft_strnew(i);
    if (fresh && s1)
    {
        tmp = fresh;
        ptr1 = s1;
        while (*s1)
            *(fresh++) = *(s1++);
        free(ptr1);
        s1 = NULL;
    }
    new_ft_strjoin_2(fresh, s2);
    return (tmp);
}

void    go(int fd, t_asm *bin)
{
    char *line;

    while (get_next_line(fd, &line) == 1)
    {
        asm->file = new_ft_strjoin(bin->file, line);
    }
    printf(">\n%s\n<", bin->file);
}

int main(int c, char **v)
{
    int fd;
    t_asm bin[1];

    if ((fd = open("v[1]", O_RDONLY)) == -1)
    {
        ft_putstr("Can't open file.\n");
    }
    else
        go(fd, &asm);
    return 0;
}