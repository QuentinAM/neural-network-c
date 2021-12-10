CC = gcc -Iinclude/

CPPFLAGS = -MMD -D__NO_INLINE__
CFLAGS = -Wall -Wextra -std=c99 -O1 -g -fsanitize=address -Wno-unknown-pragmas
LDLFLAGS = -lm -lpthread
LDLIBS =  -rdynamic

BUILD := build
SOURCE_DIR := src

SRC = $(shell find $(SOURCE_DIR) -name "*.c" ! -name "main.c")
OBJ = $(SRC:%.c=$(BUILD)/%.o)
DEP = $(SRC:%.c=$(BUILD)/%.d)

all: init main clear

clear:
	find . -type d -empty -delete

init: 
	$(shell mkdir -p $(BUILD))
	$(shell mkdir -p $(SRC:%.c=$(BUILD)/%))

main: $(OBJ)
	gcc -o $@ $(CFLAGS) $^ $(LDLFLAGS) $(LDLIBS)

$(BUILD)/%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LDLFLAGS) $(CPPFLAGS) $(LDLIBS)

# Format all files
format:
	find -name "*.[ch]" -exec clang-format --verbose -i {} \;

# Clean all trash files
clean:
	rm -rf $(BUILD)
	rm main
	clear