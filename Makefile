#WIN
# gcc -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format -g3  *.c -o printf.out.exe

# Makefile

# Specify the name of the binary file to generate
TARGET = printf.out

# Specify the source directory
SRC_DIR = .

# Retrieve all the source and header files
SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
HEADER_FILES := $(wildcard $(SRC_DIR)/*.h)

# Specify the compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=gnu89 -Wno-format -fshort-enums
#GTKFLAGS = `pkg-config --cflags --libs gtk+-3.0`

# Generate the object files by replacing the .c extension with .o
#OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(SRC_DIR)/%.o, $(SRC_FILES))

# Default target, which builds the binary file
all: $(TARGET)

# Rule to build the binary file
$(TARGET): $(SRC_FILES)
	$(CC) $(CFLAGS) $^ -o $@

# Rule to build object files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER_FILES)
	$(CC) -c $(CFLAGS) $< -o $@.o

# Clean generated files
clean:
	rm -rf $(TARGET)

# Remove and recompile all files
rebuild:
	clean all

always:
	mkdir -p bin

# Phony targets (do not represent actual files)
.PHONY: all clean rebuild always
