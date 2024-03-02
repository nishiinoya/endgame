BINARY = endgame

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

SDL = -F resources/framework -I resources/framework/SDL2.framework/SDL2 -I resources/framework/SDL2_image.framework/SDL2_image

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC_FILES:%.c=%.o)))

INC_FILES = $(wildcard $(INC_DIR)/*.h)

CC = clang

CFLAGS = -std=c11 $(addprefix -W, all extra error pedantic) -g \

SDL_FLAGS = -rpath resources/framework -framework SDL2 \
		-framework SDL2_image \
		-I resources/framework/SDL2_image.framework/Headers \
		-framework SDL2_mixer \
		-I resources/framework/SDL2_mixer.framework/Headers \
		-framework SDL2_ttf \
		-I resources/framework/SDL2_ttf.framework/Headers \

AR = ar

AFLAGS = rcs

MKDIR = mkdir -p
RM = rm -rf

all: $(BINARY)

$(BINARY): $(OBJ_FILES)
	@$(CC) $(CFLAGS) $^ -o $@ -I $(INC_DIR) $(SDL_FLAGS) $(SDL)
	@printf "\r\33[2K$@\t \033[32;1mcreated\033[0m\n"

$(OBJ_FILES): | $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_FILES)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR) $(SDL)
	@printf "\r\33[2K$(BINARY)\033[33;1m\t compile \033[0m$(<:$(SRC_DIR)/%.c=%)\r"

$(OBJ_DIR):
	@$(MKDIR) $@

clean:
	@$(RM) $(OBJ_DIR)
	@printf "$(OBJ_DIR) in $(BINARY)\t \033[31;1mdeleted\033[0m\n"

uninstall:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(BINARY)
	@@printf "$(BINARY)\t \033[31;1muninstalled\033[0m\n"

reinstall: uninstall all

.PHONY: all uninstall clean reinstall
