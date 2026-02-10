NAME = memAcrobat

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes
CFLAGS += -D__BASE_PATH__="\"$(shell pwd)\""

# Directories
SRC_DIR = src
APP_DIR = $(SRC_DIR)
DATA_DIR = $(SRC_DIR)/data

# Source Files
SRCS = \
	$(APP_DIR)/core/main.c \
	$(APP_DIR)/core/mode_selector.c \
	$(APP_DIR)/core/run_typing_session.c \
	$(APP_DIR)/utils/scoring.c\
	$(APP_DIR)/utils/files_io.c\
	$(APP_DIR)/utils/norminette.c\
	$(APP_DIR)/ui/terminal_display.c\
	$(APP_DIR)/terminal/line_editor.c\
	$(APP_DIR)/free_mode/run_free_mode.c\
	$(DATA_DIR)/string.c \
	$(DATA_DIR)/memory.c \
	$(DATA_DIR)/char.c \
	$(DATA_DIR)/conv.c \
	$(DATA_DIR)/io.c \
	$(DATA_DIR)/bonus.c \
	$(DATA_DIR)/ft_printf_utils.c \
	$(DATA_DIR)/ft_printf_handlers.c \
	$(DATA_DIR)/ft_printf_main.c \
	$(DATA_DIR)/GNL.c \
	$(DATA_DIR)/ft_printf_bonus.c \
	$(DATA_DIR)/ft_printf_bonus_handlers.c \
	$(DATA_DIR)/ft_printf_bonus_utils.c \
	$(DATA_DIR)/exam_rank_02.c \


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
