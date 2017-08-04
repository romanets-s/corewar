#include "corewar.h"
#include <stdio.h>
# define PROG_NAME_LENGTH       (128)
# define COMMENT_LENGTH         (2048)
# define COREWAR_EXEC_MAGIC     0xea83f3

typedef struct prova {
    int first;
    int second;
} prova_t;


void    go(int fd)
{
    unsigned char *line;

    line = (unsigned char *)malloc(sizeof(unsigned char)*5600);
    int n;

    printf("wft");
    if ((n = read(fd, line, 5600))) {
        printf("%d wft\n", n);
    }
    else
        printf("WTF bro\n");

    int i = -1;
    printf(">>%x<<\n", COREWAR_EXEC_MAGIC);
    printf("|%x|\n", line[2]+256+line[3]);
    while (++i < n)
    {
        printf("|%x|", line[i]);
    }
    printf("\n");
    //ft_putstr(line);
    int fd2 = open("test", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IWGRP | S_IWOTH);
    i = -1;
    while (++i < n)
    {
        write(fd2, &line[i], 1);
    }

    printf("|><|\n");
}
#include <sys/stat.h> // For fstat()
#include <unistd.h>   // For lseek()
int main(int c, char **v)
{
    int fd;

    if ((fd = open(v[1], O_RDONLY)) == -1)
    {
        printf("error open\n");
    }
    else
    {
        go(fd);
    }






    return 0;


}