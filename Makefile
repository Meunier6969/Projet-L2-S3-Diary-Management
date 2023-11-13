CC = gcc
FLAGS = -Wall -lm

all: *.c
	$(CC) include/*.c $(FLAGS) -o "out.exe"

clean:
	rm out.exe log.txt
