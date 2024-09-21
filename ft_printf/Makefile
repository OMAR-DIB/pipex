NAME = libftprintf.a

SRCS = ft_printf.c ft_putchar.c ft_putnbr.c ft_putnbrhexa.c ft_putnbruns.c ft_putpointer.c ft_putstr.c

OBJS = $(SRCS:.c=.o)

CC = cc 

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean :
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re