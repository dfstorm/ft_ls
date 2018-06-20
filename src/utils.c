#include "../includes/ft_ls.h"

int		ft_isfile(char *src)
{
	struct dirent *data;
	struct stat sb;

	if (stat(src, &sb) < 0)
		return (0);
	return (1);
}

int		ft_isdir(char *src)
{
	DIR *directory;

	directory = opendir(src);
	if (directory)
		return (1);
	return (0);
}
