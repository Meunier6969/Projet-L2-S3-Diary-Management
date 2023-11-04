CC = gcc
FLAGS = -Wall -lm

all: *.c
	$(CC) *.c $(FLAGS) -o "out.exe"

clean:
	rm out.exe
