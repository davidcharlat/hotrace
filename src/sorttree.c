#include "../includes/sorttree.h"
#include <stdlib.h>

t_sorttree	*streenew (t_content cont)
{
	int			i;
	t_sorttree	*temp;

	i = -1;
	temp = (t_sorttree*)malloc(sizeof(t_sorttree));
	if (!temp)
		return (NULL);
	temp->cont = cont;
	temp->level = 0;
	while (i++ < NUMBEROFLEAVES - 1)
		temp->next[i] = NULL;
	return (temp);
}

int			split (char *content, int cnt_size, int n)
{
	int	place;
	
	if ((n) > LEAVESPERCHAR * cnt_size)
		return (-1);
	place = (n % LEAVESPERCHAR) * BITTOSORT;
	return ((int)(((int)(content[n / LEAVESPERCHAR])>>place)
		& (NUMBEROFLEAVES - 1)));
}

void		streeins (t_sorttree *root, t_sorttree *node)
{
	t_content	temp;
	int			nxt;

	if (node)
	{
		node->level = root->level;
		nxt = split((node->cont).content, (node->cont).cnt_size, node->level);
		if (root->next[nxt] == NULL)
		{
			root->next[nxt] = node;
			(node->level)++;
		}
		else
		{
			if ((root->next[nxt]->cont).cnt_size > (node->cont).cnt_size)
			{
				temp = (node->cont);
				node->cont = root->next[nxt]->cont;
				root->next[nxt]->cont = temp;
			}
			if (root->level < LEAVESPERCHAR * (node->cont).cnt_size)
				streeins (root->next[nxt], node);
		}
	}
}
