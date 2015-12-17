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

bytes expansionArray(bytes array)
{
    bytes res = 0;
    int i;

    for(i = 0; i <= 48; i++)
    {
        setByteAtPos(res, i, getByteAtPos(array, expansion[i] - 1));
    }

    return res;
}

bytes f(bytes array)
{
  bytes res = 0;
  bytes expandedArray = expansionArray(array);
  // comparaison avec la clé
  bytes arrayGauche = getLeftPart64(expandedArray);
  bytes arrayDroite = getRightPart64(expandedArray);
  // S-box
  // concaténation
  // permutation finale
  return res;
}



bytes getLeftPart64(bytes number) { return number & 0xFFFFFFFF00000000; }
bytes getRightPart64(bytes number) { return number & 0xFFFFFFFF; }

bytes getByteAtPos(bytes number, int pos) { return (number >> pos) & 0xFF; }
bytes setByteAtPos(bytes number, int pos, bytes value) { return number & (value << pos); }
