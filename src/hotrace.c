#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../includes/sorttree.h"
#include "../includes/get_next_line_with_lenght.h"
#include "../includes/hotrace.h"

void	free_sorttree (t_sorttree *tree)
{
	int i;
	
	i = -1;
	if (tree)
	{
		while (i++ < NUMBEROFLEAVES - 1)
		{
			if (tree->next[i])
				free_sorttree (tree->next[i]);
		}
		free ((tree->cont).content);
		free ((tree->cont).data);
		free (tree);
	}
}

int		main (void)
{
	static t_sorttree	*tree;
	t_content			cont;

	cont.content = NULL;
	cont.content_size = 0;
	cont.data = NULL;
	cont.data_size = 0;
	tree = streenew (cont);
	cont.content_size++;
	while (cont.content_size)
	{
		get_next_line_with_lenght (0, &(cont.content), &(cont.content_size));
		if (cont.content_size)
		{
			get_next_line_with_lenght (0, &(cont.data), &(cont.data_size));
			streeins (tree, streenew (cont));
		}
	}
	while (get_next_line_with_lenght (0, &(cont.content), &(cont.content_size)))
	{
		print_data (tree, cont.content, &(cont.content_size));
		free (cont.content);
	}
	free_sorttree (tree);
	return (1);
}
