NAME = fractol

INCDIR = inc
SRCDIR = src
OBJDIR = build

SRCS = $(SRCDIR)/main.c
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CC := cc
CFLAGS := -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I $(INCDIR) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
