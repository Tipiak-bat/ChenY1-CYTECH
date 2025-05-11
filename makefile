# Variables
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRC = main.c menu.c sauvegarde.c fonctionnalite.c
OBJ = $(SRC:.c=.o)
EXEC = chenY1

all: $(EXEC) setup_animaux

$(EXEC): $(OBJ)
	$(CC) -o $@ $^

setup_animaux:
	mkdir -p animaux
	touch animaux/animal.txt

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

mrproper: clean
	rm -f $(EXEC)

.PHONY: all clean mrproper setup_animaux
