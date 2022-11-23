NAME		= pipex

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

INCLUDES	= -I./includes

SRCDIR		= ./srcs/

SRCS		= $(SRCDIR)pipex.c $(SRCDIR)children.c

OBJS		= $(SRCS:.c=.o)

LIBFTPATH	= ./libft/
LIBFTMAKE	= $(MAKE) -C $(LIBFTPATH)
LIBFT		= -L$(LIBFTPATH) -lft


all: $(NAME)

$(NAME): $(OBJS)
	@echo $(CURSIVE)$(GRAY) "     - Making libft..." $(NONE)
	$(LIBFTMAKE)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIBFT)
	@echo $(GREEN)"- Compiled -"$(NONE)

.c.o:
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	$(LIBFTMAKE) clean
	$(RM) $(OBJS)

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	$(LIBFTMAKE) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'