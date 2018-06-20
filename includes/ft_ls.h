
#ifndef _FT_LS_H
# define _FT_LS_H

#include "../libft/includes/libft.h"

#include <termios.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>

typedef struct		s_ls
{
	int		il;
	int		irec;
	int		ia;
	int		irev;
	int		it;
  int   icode;
	struct	s_list	*tdir;
}					t_ls;

int		ft_isdir(char *src);
int		ft_isfile(char *src);
int   print_dir(t_ls **mem);
int   print_file(t_ls **mem, char *src);
void	ftls_invalid(char *src);
void  debug_test(t_ls **mem);
void	ftls_invalid_file(char *src);
void	ftls_invalid_flag(char src);
void	ftls_help(void);
void  get_flags(t_ls **ptflags, int argc, char **argv);


#endif
