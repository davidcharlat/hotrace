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

int		nth_char_to_sbitchar (char *content, int content_size, int n)
{
	int	place;
	
	if ((n) > LEAVESPERCHAR * content_size)
		return (-1);
	place = (n % LEAVESPERCHAR) * BITTOSORT;
	return ((int)(((int)(content[n / LEAVESPERCHAR])>>place) & (NUMBEROFLEAVES - 1)));	
}

void		streeins (t_sorttree *root, t_sorttree *node)
{
	t_content	temp;
	int			nextletter;

	if (node)
	{
		node->level = root->level;
		nextletter = nth_char_to_sbitchar((node->cont).content, (node->cont).content_size, node->level);
		if (root->next[nextletter] == NULL)
		{
			root->next[nextletter] = node;
			(node->level)++;
		}
		else
		{
			if ((root->next[nextletter]->cont).content_size > (node->cont).content_size)
			{
				temp = (node->cont);
				node->cont = root->next[nextletter]->cont;
				root->next[nextletter]->cont = temp;
			}
			if (root->level < LEAVESPERCHAR * (node->cont).content_size)
				streeins (root->next[nextletter], node);
		}
	}
}
