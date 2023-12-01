CC = gcc
FLAGS = -Wall -lm

all: src/*.c
	$(CC) src/*.c $(FLAGS) -o "out.exe"
	./out.exe

clean:
	rm out.exe log.txt
