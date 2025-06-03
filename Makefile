# === Compiler and flags ===
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -Iincludes
NAME    = libft_master

# === Source files ===
SRCS    = main.c functions.c session.c utils.c
OBJS    = $(SRCS:.c=.o)

# === Default target ===
all: $(NAME)

# === Link the binary ===
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# === Compile .c to .o ===
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# === Clean object files ===
clean:
	rm -f $(OBJS)

# === Clean everything ===
fclean: clean
	rm -f $(NAME)

# === Full rebuild ===
re: fclean all

# === Run the program ===
run: all
	./$(NAME)

.PHONY: all clean fclean re run
