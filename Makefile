CC = cc
CFLAGS = -c -Wall -Wextra -Werror
CPPFLAGS = -Iinclude -I../libft

AR = ar
AFLAGS = -crs

NAME = libftdynarr.a

SRCFILES = create_delete.c\
		   modify.c\
		   access.c
SRCDIR = src
SRCS = $(addprefix $(SRCDIR)/, $(SRCFILES))

OBJFILES = $(SRCFILES:.c=.o)
OBJDIR = obj
OBJS = $(addprefix $(OBJDIR)/, $(OBJFILES))

all: CFLAGS += -O3
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(AFLAGS) $(NAME) $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $<

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
