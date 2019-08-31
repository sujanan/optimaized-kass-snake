CC=gcc
CFLAG=-g
LIBS=-lm
PROG=main

all: $(PROG)

main: main.o snake.o image.o util.o
	$(CC) $(CFLAG) -o main main.o snake.o image.o util.o $(LIBS)

snake.o: snake.h
image.o: image.h
util.o: util.h

clean:
	rm -f *.o $(PROG)
	
