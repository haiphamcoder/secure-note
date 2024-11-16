CC = gcc
CFLAGS = -Wall -g `pkg-config --cflags gtk+-3.0` -I./src/gui -I./src/crypto
LDFLAGS = `pkg-config --libs gtk+-3.0` -lcrypto

SRC_MAIN = src/main/main.c
SRC_GUI = src/gui/gui.c
SRC_CRYPTO = src/crypto/crypto.c
SRC_UTILS = $(wildcard src/utils/*.c)
SRC = $(SRC_MAIN) $(SRC_GUI) $(SRC_CRYPTO) $(SRC_UTILS)

OBJ = $(SRC:src/%.c=build/%.o)
EXEC = bin/secure-note

.PHONY: all clean

all: directories $(EXEC)

$(EXEC): $(OBJ)
	@mkdir -p bin
	$(CC) -o $@ $(OBJ) $(LDFLAGS)
	@echo "Build completed: $(EXEC)"

build/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $< -> $@"

directories:
	@mkdir -p build/main build/gui build/crypto build/utils

clean:
	rm -rf build/ bin/
	@echo "Clean completed."
