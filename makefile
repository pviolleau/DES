all: main

des.o: des.h des.c
	gcc -c des.c

main: des.o main.c
	gcc des.o main.c -o main

clean:
	rm *.o main
