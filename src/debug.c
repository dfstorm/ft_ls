#include "../includes/ft_ls.h"

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

void debug_test(t_ls **mem)
{
	t_list	*tmp;

	tmp = (*mem)->tdir;

	ft_printf("il:%i, irec:%i, ia:%i, irev:%i, it:%i\nTODO_dirs:",
			  (*mem)->il, (*mem)->irec, (*mem)->ia, (*mem)->irev,(*mem)->it);
	while (tmp != NULL)
	{
		ft_printf("[%s]", tmp->content);
		tmp = tmp->next;
	}
	ft_printf("\n");
}
