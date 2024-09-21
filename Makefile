NAME = pipex

SRC = pipex_utils.c pipex.c
OBJ := $(SRC:%.c=%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Ilibft -Ift_printf

.PHONY: all clean fclean re libft ft_printf

all: libft ft_printf $(NAME)

libft:
	make -C libft

ft_printf:
	make -C ft_printf

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $(NAME) -Llibft -lft -Lft_printf -lftprintf

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ)
	make clean -C libft
	make clean -C ft_printf

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft
	make fclean -C ft_printf

re: fclean all
