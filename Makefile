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

.PHONY: all clean build-deb

all: directories $(EXEC)

$(EXEC): $(OBJ)
	@mkdir -p bin
	$(CC) -o $@ $(OBJ) $(LDFLAGS)
	@echo "Build completed: $(EXEC)"

build/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $< -> $@"

build-deb: all
	@mkdir -p debian/usr/local/bin
	cp bin/secure-note debian/usr/local/bin/
	@mkdir -p debian/usr/local/share/secure-note
	cp LICENSE debian/usr/local/share/secure-note/
	dpkg-deb --build debian
	@mkdir -p dist/
	mv debian.deb dist/secure-note-1.0.deb
	@echo "Package created: secure-note-1.0.deb"

directories:
	@mkdir -p build/main build/gui build/crypto build/utils

clean:
	rm -rf build/ bin/ dist/ debian/usr/local/bin/ debian/usr/local/share/secure-note/
	@echo "Clean completed."
