#ifndef GET_NEXT_LINE_LENGHT_H
# define GET_NEXT_LINE_LENGHT_H

# define BUFF_SIZE 4096

int					get_next_line_with_lenght(int const fd, char **line, int *lenght);
typedef struct		s_read
{
	int				size;
	int				index;
	int				fd;
	char			*read;
	struct s_read	*next;
}					t_read;
#endif
