#include "../includes/ft_ls.h"

char	*safe_joint(char *dir, char *add)
{
	int ilen;

	ilen = ft_strlen(dir);

	if (ilen == 0)
	{

	}
}

t_list *	getsorteditem(t_ls **mem, DIR *directory)
{
	struct dirent *data;
	t_list *dirs;
	t_list *rdir;
	t_list *tmp;

	dirs = (t_list *) malloc (sizeof(t_list));
	rdir = (t_list *) malloc (sizeof(t_list));
	while ((data = readdir(directory)))
	{
		ft_lstadd(&dirs, ft_lstnew(data->d_name, sizeof(char) * ft_strlen(data->d_name)));
	}

	tmp = dirs;
	ft_printf("did i ?");
	while (tmp->next != NULL)
	{
		ft_printf("[%s]",tmp->content);
		ft_lstadd(&rdir, ft_lstnew(tmp->content, sizeof(char) * ft_strlen(tmp->content)));
		tmp = tmp->next;
	}

	free(tmp);
	return (dirs);
}

int	print_dir(t_ls **mem)
{
	DIR				*directory;
	struct dirent	*data;
	char			*src;
	t_list			*lstdir;

	directory = opendir((char *)(*mem)->tdir->content);
	if (directory)
	{
		if (ft_lstcount(&(*mem)->tdir) > 1 || (*mem)->irec)
		{
			ft_printf("%s:\n", (*mem)->tdir->content);
		}

		lstdir = getsorteditem(mem, directory);

		while (lstdir != NULL)
		{
			print_file(mem, lstdir->content);
			lstdir = lstdir->next;
		}

	}
	else
	{
		print_file(mem, (*mem)->tdir->content);
	}

	if ((*mem)->tdir->next != NULL)
	{
		ft_printf("\n");
		(*mem)->tdir = (*mem)->tdir->next;
		print_dir(mem);
	}


	return (0);
}
