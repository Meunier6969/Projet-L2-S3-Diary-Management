CC = gcc
FLAGS = -Wall -lm

all: *.c
	$(CC) src/*.c $(FLAGS) -o "out.exe"

clean:
	rm out.exe log.txt
