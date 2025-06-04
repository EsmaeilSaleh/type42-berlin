NAME = core

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

# Directories
SRC_DIR = src
APP_DIR = $(SRC_DIR)/app
DATA_DIR = $(SRC_DIR)/data

# Source Files
SRCS = \
	$(APP_DIR)/main.c \
	$(APP_DIR)/mode_runner.c \
	$(APP_DIR)/utils.c \
	$(APP_DIR)/typing_modes.c \
	$(DATA_DIR)/string.c \
	$(DATA_DIR)/memory.c \
	$(DATA_DIR)/char.c \
	$(DATA_DIR)/conv.c \
	$(DATA_DIR)/bonus.c \
	$(DATA_DIR)/gnl.c

OBJS = $(SRCS:.c=.o)

# Default Target
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
