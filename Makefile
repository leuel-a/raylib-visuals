RAYLIB_INSTALL_PATH=/opt/raylib/lib
RAYLIB_H_INSTALL_PATH=/opt/raylib/include

CC=gcc
CFLAGS=\
       -Wall\
       -I$(RAYLIB_H_INSTALL_PATH)\
       -Werror\
       -Wextra\
       -pedantic
LIBS=\
      -L$(RAYLIB_INSTALL_PATH)\
      -lraylib\
      -lGL\
      -lm\
      -lpthread\
      -ldl\
      -lrt\
      -lX11
OUTPUT= main
INPUT= binary_tree.c main.c draw_binary_tree.c
HEADER_FILES = binary_tree.h main.h draw_binary_tree.h

.PHONY: all
all: $(OUTPUT)

$(OUTPUT): $(INPUT) $(HEADER_FILES)
	$(CC) $(CFLAGS) $(INPUT) -o $(OUTPUT) $(LIBS)
