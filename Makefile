CC=gcc

RAYLIB_INSTALL_PATH=/opt/raylib/lib
RAYLIB_H_INSTALL_PATH=/opt/raylib/include

CFLAGS=\
       -Wall\
       -I$(RAYLIB_H_INSTALL_PATH)\
       -Werror\
       -Wextra\
       -pedantic\

LINKS=\
      -L$(RAYLIB_INSTALL_PATH)\
      -lraylib\
      -lGL\
      -lm\
      -lpthread\
      -ldl\
      -lrt\
      -lX11\

OUTPUT= main 

INPUT= binary_tree.c main.c

HEADER_FILES = binary_tree.h main.h

.PHONY: all

all: $(OUTPUT)

$(OUTPUT): $(INPUT) $(HEADER_FILES)
	$(CC) $(CFLAGS) $(INPUT) -o $(OUTPUT) $(LINKS)
