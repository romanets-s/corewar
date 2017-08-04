#ifndef COREWAR_COREWAR_H
#define COREWAR_COREWAR_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include "libft/libft.h"
# define BUFF_SIZE 4096

# define BUFF_SIZE 4096

typedef	struct		s_line
{
    int				fd;
    char			*str;
    struct s_line	*next;
}					t_line;

int				get_next_line(const int fd, char **line);

#endif
