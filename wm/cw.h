/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 11:37:46 by mkyianyt          #+#    #+#             */
/*   Updated: 2017/08/19 11:39:19 by mkyianyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CW_H
# define CW_H

# include "op.h"
# include "libft/libft.h"

# include <limits.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

# include <stdbool.h>

# include <ncurses.h>
# include <math.h>
# include <time.h>

# define VM_MEM_INLINE	64

# define SUB_MENU	42

typedef struct		s_ch
{
	bool			ischampion;
	char			*file;
	bool			isnum;
	int				num;
	char			*name;
	int				csize;
	char			*cmt;
	char			*cmd;
	unsigned char	*ucmd;
	unsigned int	reg[REG_NUMBER];
	unsigned int	pc;
	bool			carry;
	bool			alive;
	int				live;
	int				load_mem;
	bool			cpause;
	int				cycles;
	short int		color;
	int				fork;
}					t_ch;

typedef struct		s_vm
{
	unsigned char	*mem;
	unsigned int	cycle;
	unsigned int	ctd;
	int				checks;
	bool			isdecr_maxcheck;
	int				nbr_live;
	int				last_live;
}					t_vm;

typedef struct		s_vis
{
	WINDOW			*win;
	int				width;
	int				height;
	int				cps;
	clock_t			cstart;
	int				cycles;
	int				vids;
	bool			pause;
}					t_vis;

typedef struct		s_n
{
	unsigned int	b;
	char			*n;
	unsigned int	**as;
}					t_n;

typedef struct		s_cw
{
	t_ch			*ch;
	int				chcount;
	int				chrc;
	bool			visual;
	bool			isdump;
	int				dump;
	t_vm			vm;
	t_vis			vis;
	t_n				n;
}					t_cw;

void				cw_struct_null(t_cw *cw);
void				cw_read_args(t_cw *cw, int argc, char **argv);
void				cw_read_args_flags(t_cw *cw, int argc, char **argv, int *i);
void				cw_decryptor(t_cw *cw);
char				*cw_decrypt_comment(int fd, t_cw *cw);
void				cw_decrypt_commands(t_cw *cw, int z, int j, int fd);
void				cw_prefight(t_cw *cw, int tmp);
void				cw_pre_visual(t_cw *cw, int i, int col);
void				cw_battle(t_cw *cw);
void				cw_fight(t_cw *cw);
void				cw_the_end(t_cw *cw);
void				cw_vm_live(t_cw *cw, int c);
void				cw_vm_ld(t_cw *cw, int c);
void				cw_vm_st(t_cw *cw, int c);
void				cw_vm_add(t_cw *cw, int c);
void				cw_vm_sub(t_cw *cw, int c);
void				cw_vm_and(t_cw *cw, int c);
void				cw_vm_or(t_cw *cw, int c);
void				cw_vm_xor(t_cw *cw, int c);
void				cw_vm_zjmp(t_cw *cw, int c);
void				cw_vm_ldi(t_cw *cw, int c);
void				cw_vm_sti(t_cw *cw, int c);
void				cw_vm_fork(t_cw *cw, int c);
void				cw_vm_lld(t_cw *cw, int c);
void				cw_vm_lldi(t_cw *cw, int c, int i);
void				cw_vm_lfork(t_cw *cw, int c);
void				cw_vm_aff(t_cw *cw, int c);
void				cw_vm_next(t_cw *cw, int c);
void				cw_decrypt_magic(int fd, t_cw *cw);
char				*cw_decrypt_name(int fd, t_cw *cw);
int					cw_decrypt_cmd_size(int fd, t_cw *cw);
void				cw_output(t_cw *cw);
void				cw_usage(char *error, t_cw *cw);
void				cw_new_ch(t_cw *cw);
unsigned int		cw_get_number(t_cw *cw, unsigned int s, unsigned int e);
unsigned int		cw_real_ptr(unsigned int s);
char				*cw_int_decrypt(unsigned char c);
unsigned int		**cw_get_arg(t_cw *cw, int c, int label, int ind);
void				cw_put_inmem(t_cw *cw, unsigned int w, unsigned int i);
void				cw_set_pause(t_cw *cw, int c, int fcycle);
void				cw_load_reg(t_cw *cw, int c, unsigned int **args, int argn);
void				cw_load_ind(t_cw *cw, int c, unsigned int **args, int argn);
void				cw_create_regs(t_cw *cw, int i);
void				cw_cpy_ch(t_cw *cw, int c, unsigned int where, int ind);
void				cw_vis_output(t_cw *cw, int x, int y);
void				cw_vis_refresh(t_cw *cw);
void				cw_draw_options(t_cw *cw);
void				cw_draw_players(t_cw *cw, int i);
void				cw_vis_cps_up(t_cw *cw);
void				cw_vis_cps_down(t_cw *cw);
void				cw_vis_pc(t_cw *cw);
int					cw_find_index(t_cw *cw, int num);
void				cw_burn_them_all(t_cw *cw, int num);
void				free_args(unsigned int **args);
int					is_pause(t_cw *cw, int c);

#endif
