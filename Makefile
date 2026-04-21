CC = gcc

# Compiler flags:
CFLAGS = -Wall -Wextra -g -Iinclude

# The final executable name
TARGET = bin/debloater

SRCS = $(wildcard src/*.c)

# Object files: Convert src/filename.c -> obj/filename.o
OBJS = $(patsubst src/%.c, obj/%.o, $(SRCS))


# Default rule: Build the target
all: $(TARGET)

# Link: Create the executable from object files
$(TARGET): $(OBJS)
	@mkdir -p bin
	$(CC) $(CFLAGS) $^ -o $@
	@echo "Build successful: $@"

# Compile: Create object files from source files
obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

git:
	git add .
	git commit -s -m "$(commit)"
	git push

clean:
	rm -rf obj bin

run: all
	./$(TARGET)

# Phony targets (not actual files)
.PHONY: all clean run
