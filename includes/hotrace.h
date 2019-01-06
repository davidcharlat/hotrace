#ifndef HOTRACE_H
# define HOTRACE_H

void		print_data (t_sorttree *root, char *line, int *line_len);
int			get_next_line_with_lenght (const int fd, char **line, int *line_len);
t_sorttree	*streenew (t_content cont);
void		streeins (t_sorttree *root, t_sorttree *node);
int			nth_char_to_sbitchar (char *content, int content_size, int n);

#endif
