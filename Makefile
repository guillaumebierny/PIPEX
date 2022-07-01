SRC = main.c child.c pipex_utils.c
OBJ = $(SRC:.c=.o)
CC = gcc $(FLAGS)
FLAGS = -Wall -Wextra -Werror
NAME = pipex
MAIN = main.c
LIBFT = ./libft/libft.a
%.o : %.c
	$(CC) -c $< -o $@

all : $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	$(CC) $(OBJ) $(LIBFT) -o $(NAME)
clean :
	$(MAKE) clean -C ./libft
	rm -f $(OBJ)
fclean : clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re : fclean all

.PHONY : re clean fclean all
