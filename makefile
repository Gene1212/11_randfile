all: main.o generator.o
	gcc -o test main.o generator.o

main.o: main.c generator.h
	gcc -c main.c

generator.o: generator.c generator.h
	gcc -c generator.c

run:
	./test