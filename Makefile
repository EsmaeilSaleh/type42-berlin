# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

# Executable name
TARGET = libft_master

# Source files
SRCS = main.c utils.c functions.c memory_functions.c string_functions.c \
       char_functions.c conv_functions.c bonus_functions.c

# Object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Link object files into executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files and executable
clean:
	rm -f $(OBJS) $(TARGET)

# Rebuild everything
re: clean all

.PHONY: all clean re
