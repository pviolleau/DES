#include <stdio.h>
#include <stdlib.h>

#define bytes unsigned int
#define getFirstPart(number) { return number & 0xFFFFFFFF; }
#define getSecondPart(number) { return number & 0xFFFFFFFF00000000; }

unsigned char* subArray(unsigned char* array, int index, int length);
unsigned char* expansionArray(unsigned char* array);
unsigned char* f(unsigned char* array);
