all: main

des.o: des.h des.c
        gcc -c des.c

main: des.o main.c
        gcc -o main des.o
				
clean:
        rm *.o main
