CC = gcc
CFLAGS = -Wall -g `pkg-config --cflags gtk+-3.0`
LDFLAGS = `pkg-config --libs gtk+-3.0` -lcrypto

SRC = src/main.c src/gui.c src/crypto.c
OBJ = $(SRC:src/%.c=build/%.o)
EXEC = bin/secure-note

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJ)
	@mkdir -p bin
	$(CC) -o $@ $(OBJ) $(LDFLAGS)
	@echo "Build completed: $(EXEC)"

build/%.o: src/%.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $< -> $@"

clean:
	rm -rf build/ bin/
	@echo "Clean completed."
