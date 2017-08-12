#ifndef COREWAR_COREWAR_H
#define COREWAR_COREWAR_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

#define BUFF_SIZE               2048

#define T_REG                   1
#define T_DIR                   2
#define T_IND                   4

# define REG_CODE               1
# define DIR_CODE               2
# define IND_CODE               3

#define COMMENT_CHAR			'#'
#define LABEL_CHAR				':'
#define DIRECT_CHAR				'%'
#define SEPARATOR_CHAR			','

#define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING			".name"
#define COMMENT_CMD_STRING		".comment"

#define REG_NUMBER				16

#define OPERATIONS_NUM          16

# define PROG_NAME_LENGTH       (128)
# define COMMENT_LENGTH         (2048)
# define COREWAR_EXEC_MAGIC     0xea83f3


typedef struct		    s_head
{
    unsigned int		magic;
    char				prog_name[PROG_NAME_LENGTH + 1];
    unsigned int		prog_size;
    char				comment[COMMENT_LENGTH + 1];
}                       t_head;

typedef struct      s_op
{
    char            *name;
    char            argc;
    unsigned char   argv[3];
    char            cod;
    unsigned char   hex;
    char            size;

}                   t_op;

typedef struct      s_lable
{
    char            *name;
    int             start;
    int             end;

}                   t_lable;

typedef struct      s_asm
{
    struct s_op     op[OPERATIONS_NUM + 1];
    char            *file;
    int             i;
    unsigned char   *code;
    unsigned int    code_size;
    unsigned int    buff_size;
    int             name;
    int             comm;
    char            *file_name;
    struct s_head   head;
}                   t_asm;


void    op_init(t_asm *bin);
void    asm_init(t_asm *bin);
void    write_magic(t_asm *bin, unsigned int magic);
void    commands_date(t_asm *bin, int *i, int max_len, char *str);
void    commands(t_asm *bin, int *i);
void    name_and_comment(t_asm *bin);
char    *ft_new_strjoin(char *s1, char const *s2);
char    *file_name(char *name, size_t len);
void    comment(t_asm *bin, int *i);
int     ft_stn(char c);
int     label_chars(char c);



#endif
