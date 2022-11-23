NAME		= libft.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

AR			= ar rcs

INCLUDES	= -I./includes

SRCDIR		= ./srcs/

SRCS		= $(SRCDIR)ft_split.c $(SRCDIR)ft_strjoin.c $(SRCDIR)ft_strlen.c \
			  $(SRCDIR)ft_strncmp.c $(SRCDIR)ft_substr.c $(SRCDIR)ft_putendl_fd.c

OBJS		= $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
