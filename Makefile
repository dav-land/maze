# Variables
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -pedantic -g
LDLIBS = -lm
PROG = test_maze
SRC = $(PROG).c maze.c
HDR = maze.h
OBJ = $(SRC:.c=.o)

# Targets
$(PROG): $(OBJ)
$(OBJ): $(HDR)
TAGS: $(SRC) $(HDR)
	etags $^
.PHONY: clean
clean:
	$(RM) $(PROG) $(OBJ)

