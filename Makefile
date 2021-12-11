CC = gcc -Iinclude/

CPPFLAGS = -MMD -D__NO_INLINE__
CFLAGS = -Wall -Wextra -std=c99 -O1 -g -fsanitize=address -Wno-unknown-pragmas
LDLFLAGS = -lm -lpthread
LDLIBS =  -rdynamic

BUILD := build
SOURCE_DIR := src

SRC = $(shell find $(SOURCE_DIR) -name "*.c" ! -name "main.c")
OBJ = $(SRC:%.c=$(BUILD)/%.o)

all: init main clear

# Create build directory
init: 
	$(shell mkdir -p $(BUILD))
	$(shell mkdir -p $(SRC:%.c=$(BUILD)/%))

# Compile all source files
main: $(OBJ)
	gcc -o $@ $(CFLAGS) $^ $(LDLFLAGS) $(LDLIBS)

# Clear build directory
clear:
	find . -type d -empty -delete

# Redirect output to build directory
$(BUILD)/%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LDLFLAGS) $(CPPFLAGS) $(LDLIBS)

# Format all files
format:
	find -name "*.[ch]" -exec clang-format --verbose -i {} \;

# Clean all trash files
clean:
	rm -rf $(BUILD)
	rm -f main
	clear