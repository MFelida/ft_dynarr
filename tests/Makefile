# Don't run this makefile directly, run mkae test from the project root
CC = cc
CFLAGS = -c -Wall -Wextra -Werror -O0 -gdwarf-2
CPP_FLAGS =  -I. -I../include -I$(LIBFTPATH)

NAME = ft_vector_tests

SRCFILES = exit_test.c \
	   run_tests.c \
	   test_create_delete.c
SRCDIR = src
SRCS = $(addprefix $(SRCDIR)/, $(SRCFILES))

OBJFILES = $(SRCFILES:.c=.o)
OBJDIR = obj
OBJS = $(addprefix $(OBJDIR)/, $(OBJFILES))

LIBFTPATH = /home/mfelida/codam/libft

LDFLAGS = -L.. -lftvector -L$(LIBFTPATH) -lft

run: re
	./$(NAME)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CPP_FLAGS) $(CFLAGS) -o $@ $<

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)
	
fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: run all clean fclean re
