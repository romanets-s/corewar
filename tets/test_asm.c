#include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define BUFF 6144
# define PROG_NAME_LENGTH	   (128)
# define COMMENT_LENGTH		 (2048)

int	main(int c, char **v)
{
	int fd1, fd2;
	unsigned char code1[BUFF], code2[BUFF];

	if (c == 3)
	{
		if ((fd1 = open(v[1], O_RDONLY)) == -1 || (fd2 = open(v[2], O_RDONLY)) == -1)
			printf("Cannot open file\n");
		else
		{
			for (int i = 0; i < BUFF; ++i)
			{
				code1[i] = 0;
				code2[i] = 0;
			}

			read(fd1, code1, BUFF);
			read(fd2, code2, BUFF);
			for (int i = 0; i < BUFF; ++i)
			{
				if (code1[i] != code2[i])
					printf("wrong byte code own|%02x| != asm|%02x| - %d\n", code1[i], code2[i], i - 4 - PROG_NAME_LENGTH - 8 - COMMENT_LENGTH - 4);
			}
			printf("finish\n");
		}
	}
}