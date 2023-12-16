# Makefile for the 'play' program

CC = gcc
CFLAGS = -Wall
SRC = main.c GestionJeu.c foret.c cellules.c grille.c
TARGET = play

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all clean