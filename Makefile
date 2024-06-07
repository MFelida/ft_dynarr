CC = cc
CFLAGS = -c -Wall -Wextra -Werror
CPPFLAGS = -Iinclude

AR = ar
AFLAGS = -crs

NAME = libftvector.a

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

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR) .submodules_init
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ $<

.submodules_init:
	@git submodule update --init --recursive
	@cd include && ln -s ../libft/libft.h
	@touch .submodules_init

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
