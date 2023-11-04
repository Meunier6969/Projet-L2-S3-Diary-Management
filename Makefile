CC = gcc
FLAGS = -Wall -lm

all: *.c
	$(CC) *.c $(FLAGS) -o "out"

clean:
	rm out
