#include "../includes/ft_ls.h"

int	print_file(t_ls **mem, char *src)
{
	struct stat sb;
	char *		filename;
	//char **		uri;

	if (stat(src, &sb) < 0)
	{
		// error while reading detected files...
	}

	filename = ft_strdup(src);

	//uri = ft_strsplit(src, '/');
	//filename = uri[0];
	if (filename[0] != '.')
		ft_printf("%s\n", src);
	else if ((*mem)->ia && filename[0] == '.')
		ft_printf("%s\n", src);


	return (0);
}
