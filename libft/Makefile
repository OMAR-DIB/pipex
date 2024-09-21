NAME = libft.a

CFLAGS = -Wall -Werror -Wextra -std=c99
CC = gcc

all: $(NAME);

SRCS = ft_atoi.c ft_isdigit.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_memset.c ft_strlen.c ft_tolower.c ft_bzero.c ft_isprint.c ft_strchr.c ft_strncmp.c ft_toupper.c ft_calloc.c ft_memchr.c ft_strdup.c ft_strnstr.c ft_isalnum.c ft_memcmp.c ft_strjoin.c ft_strrchr.c ft_isalpha.c ft_memcpy.c ft_strlcat.c ft_isascii.c ft_memmove.c ft_strlcpy.c ft_substr.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c get_next_line.c
OBJS = $(SRCS:.c=.o)

BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o);

ALL_OBJS = $(BONUS_OBJS) $(OBJS)

$(NAME): $(OBJS) 
		ar src $(NAME) $(OBJS)
%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@
bonus: $(OBJS) $(BONUS_OBJS)
	ar src $(NAME) $?
clean:
		rm -f $(OBJS) $(BONUS_OBJS)
fclean: clean
		rm -f $(NAME)
re: fclean all

.PHONY : all bonus clean fclean re
