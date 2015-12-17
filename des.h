#include <stdio.h>
#include <stdlib.h>

#define bytes long unsigned int

bytes getLeftPart64(bytes number);
bytes getRightPart64(bytes number);

bytes getByteAtPos(bytes number, int pos);
bytes setByteAtPos(bytes number, int pos, bytes value);


bytes expansionArray(bytes array);
bytes f(bytes array);
