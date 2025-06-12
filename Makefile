CC = gcc
CFLAGS = -Wall -Wextra -g -I./src
LDFLAGS = 
SRC_DIR = src
BIN_DIR = bin

SOURCES = $(SRC_DIR)/main.c $(SRC_DIR)/bitset/bitset.c $(SRC_DIR)/output/output.c
OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(BIN_DIR)/%.o,$(SOURCES))
TARGET = $(BIN_DIR)/bitset_program

.PHONY: all clean run test

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BIN_DIR)

run: $(TARGET)
	@./$(TARGET)

test: $(TARGET)
	@echo "Running tests..."
	@./$(TARGET)