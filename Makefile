CC = gcc
FLAGS = -Wall -lm

all: *.c
	$(CC) *.c timer/*.c $(FLAGS) -o "out.exe"

clean:
	rm out.exe log.txt
