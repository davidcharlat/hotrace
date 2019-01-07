#ifndef HOTRACE_H
# define HOTRACE_H

void		print_data (t_sorttree *root, char *line, int *line_len);
int			gnl_len (const int fd, char **line, int *line_len);
t_sorttree	*streenew (t_content cont);
void		streeins (t_sorttree *root, t_sorttree *node);
int			split (char *content, int cnt_size, int n);

#endif
