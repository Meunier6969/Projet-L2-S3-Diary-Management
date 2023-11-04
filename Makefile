CC = gcc
FLAGS = -Wall

all: *.c
	$(CC) $(FLAGS) *.c -o "out"

clean:
	rm out
