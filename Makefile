CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
LINKS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRC = binary_tree.c main.c
HEADER_FILES = binary_tree.h main.h
OUTPUT = main 

.PHONY: all

all: $(OUTPUT)

$(OUTPUT): $(SRC) $(HEADER_FILES)
	$(CC) $(CFLAGS) $(SRC) -o $(OUTPUT) $(LINKS)

