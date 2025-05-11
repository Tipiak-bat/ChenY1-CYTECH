# Variables
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRC = main.c menu.c sauvegarde.c fonctionnalite.c
OBJ = $(SRC:.c=.o)
EXEC = chenY1


exec: $(EXEC)

all: clean mrproper init exec

$(EXEC): $(OBJ)
	$(CC) -o $@ $^

init:
	mkdir -p animaux
	touch animaux/animal.txt

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

mrproper: clean
	rm -f $(EXEC)


.PHONY: exec all clean mrproper init
