//ctrl+shift+h
#include "des.h"
int expansion[48] = {
  32,1,2,3,4,5,
  4,5,6,7,8,9,
  8,9,10,11,12,13,
  12,13,14,15,16,17,
  16,17,18,19,20,21,
  20,21,22,23,24,25,
  24,25,26,27,28,29,
  28,29,30,31,32,1};

unsigned char* subArray(unsigned char* array, int index, int length)
{
    unsigned char* res = malloc(sizeof(char) * length);
    int i;

    for(i = 0; i <= length; i++)
    {
        res[i + length] = array[index + i];
    }

    return res;
}

unsigned char* expansionArray(unsigned char* array)
{
    unsigned char* res = malloc(sizeof(unsigned char) * 48);
    int i;

    for(i = 0; i <= 48; i++)
    {
        res[i] = array[expansion[i]-1];
    }

    return res;
}

unsigned char* f(unsigned char* array)
{
  unsigned char* res=malloc(sizeof(unsigned char) * 48);
  unsigned char* expandedArray;
  expandedArray=expansionArray(array);
  // comparaison avec la clé
  unsigned char* ArrayGauche=subArray(expandedArray, 0, 32);
  unsigned char* ArrayDroite=subArray(expandedArray, 32, 32);
  // S-box
  // concaténation
  // permutation finale
  return res;
}
