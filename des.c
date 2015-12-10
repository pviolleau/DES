//ctrl+shift+h
#include "des.h"

char* subArray(char* array, int index, int length)
{
    char* res = malloc(sizeof(char) * length);
    int i;

    for(i = 0; i <= length; i++)
    {
        res[i + length] = array[index + i];
    }

    return res;
}
