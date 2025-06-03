NAME = libft_master
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

SRC = main.c functions.c utils.c
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

run: $(NAME)
	./$(NAME)
