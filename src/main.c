#include "../libft/includes/libft.h"
#include "../includes/ft_ls.h"

t_ls	* init_main_container(void)
{
	t_ls	* mem;

	mem = (t_ls *) malloc(sizeof(t_ls));
	if (!mem)
		return (NULL);
	mem->directories = NULL;
	mem->il = 0;
	mem->irec = 0;
	mem->ia = 0;
	mem->irev = 0;
	mem->it = 0;
	return (mem);
}

int		main(int argc, char **argv)
{
	t_ls	* mem;

	if (argc || argv) {}
	mem = init_main_container();
	if (mem) {}
	ft_putstr("what?--");

	return (0);

}
