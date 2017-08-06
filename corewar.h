#ifndef COREWAR_COREWAR_H
#define COREWAR_COREWAR_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include "libft/libft.h"

# define BUFF_SIZE 4096

typedef	struct		s_line
{
    int				fd;
    char			*str;
    struct s_line	*next;
}					t_line;

int				get_next_line(const int fd, char **line);

typedef struct      s_asm
{
    char            *file;
    unsigned char   *code;
}                   t_asm;

#define T_REG					1
#define T_DIR					2
#define T_IND					4

#define COMMENT_CHAR			'#'
#define LABEL_CHAR				':'
#define DIRECT_CHAR				'%'
#define SEPARATOR_CHAR			','

#define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING			".name"
#define COMMENT_CMD_STRING		".comment"

#define REG_NUMBER				16

# define PROG_NAME_LENGTH       (128)
# define COMMENT_LENGTH         (2048)
# define COREWAR_EXEC_MAGIC     0xea83f3

typedef struct		header_s
{
    unsigned int		magic;
    char				prog_name[PROG_NAME_LENGTH + 1];
    unsigned int		prog_size;
    char				comment[COMMENT_LENGTH + 1];
}



#endif
