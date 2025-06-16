NAME = type42

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
	$(DATA_DIR)/io.c \
	$(DATA_DIR)/bonus.c \
	$(DATA_DIR)/gnl.c

OBJS = $(SRCS:.c=.o)

# Default Target
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)
	rm -f $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

INSTALL_DIR := $(HOME)/.local/bin
SHELL_PROFILE := $(HOME)/.zshrc

install:
	@mkdir -p $(INSTALL_DIR)
	@cp type42 $(INSTALL_DIR)/
	@echo "✅ Installed 'type42' binary to $(INSTALL_DIR)"
	@echo "Checking if $(INSTALL_DIR) is in PATH..."
	@if ! echo $$PATH | grep -q "$(INSTALL_DIR)"; then \
		echo "🔧 Adding $(INSTALL_DIR) to PATH in $(SHELL_PROFILE)"; \
		echo "\n# Added by Type42 installer" >> $(SHELL_PROFILE); \
		echo "export PATH=\"\$$PATH:$(HOME)/.local/bin/type42\"" >> $(SHELL_PROFILE); \
		echo "✅ Done. Please run: source $(SHELL_PROFILE)"; \
	else \
		echo "✅ $(INSTALL_DIR) is already in PATH"; \
	fi
