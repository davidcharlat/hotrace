NAME = hotrace

SRCPATH = ./src/

ODIR = ./bin/

TESTDIR = ./.test/

SRCFILES =	get_next_line_with_lenght.c \
			sorttree.c \
			hotrace.c \
			print_data.c
			
FLAGS = -Wall -Wextra -Werror -O3

OBJS = $(addprefix $(ODIR), $(SRCFILES:.c=.o))

TESTFILE = $(addprefix $(TESTDIR), $(SRCFILES:.c=.test.c)) 
TESTBIN = $(addprefix $(SRCPATH), $(SRCFILES:.c=.out))

vpath %.c src/

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(FLAGS) -o $(NAME) $(OBJS)

$(ODIR)%.o: %.c
	gcc $(FLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)
	
re: fclean all

#testft: $(TESTBIN)
#
#$(TESTBIN): $(TESTFILE)
#
#$(TESTFILE): $(addprefix $(SCRPATH), $(SRCFILES)) $(TESTDIR)last $(NAME)
#	gcc $(FLAGS) -o a.out -L -lft ./includes/libft.h $@ 
#	./a.out
#	rm a.out
#	touch $(TESTDIR)last
#	
#$(TESTDIR)last:
#	touch $(TESTDIR)last
