NAME = fractol

CC := cc
CFLAGS := -O2 -Wall -Wextra -Werror
CPPFLAGS := -Iinc -Ilib/minilibx-linux -Ilib/libft
LDFLAGS := -Llib/minilibx-linux
LDLIBS := -lmlx -lft -lXext -lX11

INCDIR = inc
SRCDIR = src
OBJDIR = build
MLXDIR = lib/minilibx-linux
LIBFTDIR = lib/libft

SRCS = \
	$(SRCDIR)/main.c \
	$(SRCDIR)/parse.c \
	$(SRCDIR)/init.c \
	$(SRCDIR)/render.c \
	$(SRCDIR)/render_mandelbrot.c \
	$(SRCDIR)/render_julia.c \
	$(SRCDIR)/color.c \
	$(SRCDIR)/events.c \
	$(SRCDIR)/cleanup.c \
	$(SRCDIR)/pixel.c \
	$(SRCDIR)/utils.c

OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFTDIR)
	-$(MAKE) -C $(MLXDIR)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFTDIR) $(LDFLAGS) $(LDLIBS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)
	$(MAKE) -C $(LIBFTDIR) clean
	@if [ -f $(MLXDIR)/Makefile.gen ]; then $(MAKE) -C $(MLXDIR) clean; fi

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

norm:
	norminette $(SRCDIR) $(INCDIR) $(LIBFTDIR)

.PHONY: all re clean fclean norm
