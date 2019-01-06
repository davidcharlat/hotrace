#include <stdlib.h>
#include <unistd.h>
#include "../includes/sorttree.h"
#include "../includes/hotrace.h"

int	ft_unendedstr2cmp(const char *s1, const char *s2)
{
	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (-1024);
	if (!s2)
		return (1023);
	while (*(s1) && *(s1) == *(s2))
	{
		s1++;
		s2++;
	}
	return ((int)*(s1));
}

void		print_data (t_sorttree *root, char *line, int *line_len)
{
	int nextletter;
		
	while (root && *line_len > (root->cont).content_size )
	{
		nextletter = nth_char_to_sbitchar(line, *line_len, root->level);
		root = root->next[nextletter];
	}
	while (root && ft_unendedstr2cmp (line, (root->cont).content) 
		&& *line_len == (root->cont).content_size)
	{
		nextletter = nth_char_to_sbitchar(line, *line_len, root->level);
		root = root->next[nextletter];
	}
	if (root && *line_len == (root->cont).content_size 
		&& !ft_unendedstr2cmp (line, (root->cont).content))
	{
		if (write (1, (root->cont).data, (root->cont).data_size) + write (1, "\n", 1))
			return;
	}
	else if (write (1, line, *line_len) + write (1, ": Not found.\n", 13))
		return;
}
