
#ifndef _FT_LS_H
# define _FT_LS_H

#include <termios.h>
#include <sys/ioctl.h>
#include <sys/types.h>

typedef struct		s_ls
{
	int		il;
	int		irec;
	int		ia;
	int		irev;
	int		it;
	struct	s_list	*directories;
}					t_ls;

#endif
