
#include "../includes/ft_ls.h"

t_ls	* init_main_container(void)
{
	t_ls	* mem;

	mem = (t_ls *) malloc(sizeof(t_ls));
	if (mem == NULL || mem == 0)
		return (NULL);
	mem->tdir = NULL;
	mem->il = 0;
	mem->irec = 0;
	mem->ia = 0;
	mem->irev = 0;
	mem->it = 0;
	mem->icode = 0;
	return (mem);
}

int		is_help(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (ft_strlen(argv[i]) == 6)
		{
			if (argv[i][1] == '-' && argv[i][2] == 'h' && argv[i][3] == 'e' &&
				 argv[i][0] == '-' && argv[i][4] == 'l' && argv[i][5] == 'p')
			{
				ftls_help();
				return (1);
			}
		}
	}
	return (0);
}

void	add_relative_if_none(t_ls **ptmem)
{
	t_list	*listitem;
	char	*c;

	if ((*ptmem)->tdir == NULL)
	{
		c = ft_strnew(1);
		c[0] = '.';
		listitem = ft_lstnew(c, sizeof(char));
		ft_lstadd(&(*ptmem)->tdir, listitem);
	}
}

int		main(int argc, char **argv)
{
	t_ls	* mem;
	int		istatus;

	istatus = 0;
	if (is_help(argc, argv) == 1)
		return (0);
	mem = init_main_container();
	if (argc > 1)
		get_flags(&mem, argc, argv);
	debug_test(&mem);
	if (mem->icode == 0)
	{
		add_relative_if_none(&mem);
		istatus = print_dir(&mem);
	}


	return (0);

}
