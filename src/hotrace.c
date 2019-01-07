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
	cont.cnt_size = 0;
	cont.data = NULL;
	cont.sz = 0;
	tree = streenew (cont);
	cont.cnt_size++;
	while (cont.cnt_size)
	{
		gnl_len (0, &(cont.content), &(cont.cnt_size));
		if (cont.cnt_size)
		{
			gnl_len (0, &(cont.data), &(cont.sz));
			streeins (tree, streenew (cont));
		}
	}
	while (gnl_len (0, &(cont.content), &(cont.cnt_size)))
	{
		print_data (tree, cont.content, &(cont.cnt_size));
		free (cont.content);
	}
	free_sorttree (tree);
	return (1);
}
