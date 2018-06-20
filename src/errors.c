#include "../includes/ft_ls.h"

void	ftls_invalid_file(char *src)
{
	ft_printf("ft_ls: impossible d'accéder à '%s': No such file or directory\n", src);
}
void	ftls_invalid_flag(char src)
{
	ft_printf("ft_ls: invalid option -- '%c'\nSaisissez « ls --help » pour plus d'informations.\n", src);
}
void	ftls_help(void)
{
	ft_printf("ft_ls\n");
	ft_printf("l	: use a long listing format\n");
	ft_printf("R	: Recursive.\n");
	ft_printf("a	: Affiche aussi les entité commencant par '.'.\n");
	ft_printf("r	: Reverse\n");
	ft_printf("t	: Sort by modification time, newest first\n");

}
/*
 * 2	lflag	il		l	: use a long listing format.
 * 3	recflag	irec	R	: Recursive.
 * 4	aflag	ia		a	: Affiche aussi les entité commencant par ".".
 * 5	revflag	irev	r	: Reverse
 * 6	tflag	it		t	: Sort by modification time, newest first
 **/
