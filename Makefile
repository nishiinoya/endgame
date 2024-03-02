CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

BINARY = endgame

HEADERFILES = ./inc
SRCFILES = ./src

all: $(BINARY)

$(BINARY): $(SRCFILES) | $(HEADERFILES)
	$(CC) $(CFLAGS) $^/*.c -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer -lm -o $@ -I $(HEADERFILES)

uninstall:
	rm -rf $(BINARY)

clean:
	rm -rf $(BINARY)

reinstall: uninstall all
