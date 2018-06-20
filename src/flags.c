
#include "../includes/ft_ls.h"

void	align_flags(t_ls **mem, int instruction)
{
	if (instruction == 2)
		(*mem)->il = 1;
	if (instruction == 3)
		(*mem)->irec = 1;
	if (instruction == 4)
		(*mem)->ia = 1;
	if (instruction == 5)
		(*mem)->irev = 1;
	if (instruction == 6)
		(*mem)->it = 1;
}

int		get_flag_type_by_char(char c)
{
	if (c == 'l')
		return (2);
	else if (c == 'R')
		return (3);
	else if (c == 'a')
		return (4);
	else if (c == 'r')
		return (5);
	else if (c == 't')
		return (6);
	else
		return (-1);
}

/*
 * Return value:
 * -1	Nothing.
 * 0	File
 * 1	dir
 * 2	lflag	il		l	: use a long listing format.
 * 3	recflag	irec	R	: Recursive.
 * 4	aflag	ia		a	: Affiche aussi les entité commencant par ".".
 * 5	revflag	irev	r	: Reverse
 * 6	tflag	it		t	: Sort by modification time, newest first
*/

void	scan_for_flags(t_ls **ptmem, char *str)
{
	int	i;
	int	iflag;

	i = ft_strlen(str);
	if (i > 1)
	{
		if (str[0] != '-')
		{
			ftls_invalid_file(str);
			(*ptmem)->icode = 1;
		}
		else
		{
			while (--i > 0 && !(*ptmem)->icode)
			{
				iflag = get_flag_type_by_char(str[i]);
				if (iflag < 0)
				{
					ftls_invalid_flag(str[i]);
					(*ptmem)->icode = 1;
				}
				else
					align_flags(ptmem, iflag);
			}
		}
	}
	else
	{
		ftls_invalid_file(str);
		(*ptmem)->icode = 1;
	}

}

void	get_flags(t_ls **ptmem, int argc, char **argv)
{
	int		i;
	int 	itype;
	t_list	*lstitem;

	i = 0;
	while (++i < argc)
	{
		if (ft_isfile(argv[i]) == 1 || ft_isdir(argv[i]) == 1)
		{
			lstitem = ft_lstnew(argv[i], sizeof(char) * ft_strlen(argv[i]));
			ft_lstadd(&(*ptmem)->tdir, lstitem);
		}
		else if (ft_isfile(argv[i]) == 0 && ft_isfile(argv[i]) == 0)
			scan_for_flags(ptmem, argv[i]);
	}

}
