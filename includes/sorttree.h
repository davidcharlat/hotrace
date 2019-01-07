#ifndef SORTTREE_H
# define SORTTREE_H

# define BITTOSORT 4
/*
** number of bit to sort: 1, 2, 4, or 8
*/
# if BITTOSORT == 1
#  define NUMBEROFLEAVES 2
#  define LEAVESPERCHAR 8
# elif BITTOSORT == 2
#  define NUMBEROFLEAVES 4
#  define LEAVESPERCHAR 4
# elif BITTOSORT == 4
#  define NUMBEROFLEAVES 16
#  define LEAVESPERCHAR 2
# elif BITTOSORT == 8
#  define NUMBEROFLEAVES 256
#  define LEAVESPERCHAR 1
# endif

typedef struct			s_content
{
	char				*content;
	char				*data;
	int					cnt_size;
	int					sz;
}						t_content;

typedef struct			s_sorttree
{
	struct s_content	cont;
	int					level;
	struct s_sorttree	*next[NUMBEROFLEAVES];
}						t_sorttree;

#endif
