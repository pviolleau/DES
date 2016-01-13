#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int SBOX[8][4][16] = {
    {
        {14,  4, 13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7},
        { 0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8},
        { 4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0},
        {15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13},
    },

    {
        {15,  1,  8, 14,  6, 11,  3,  4,  9,  7,  2, 13, 12,  0,  5, 10},
        { 3, 13,  4,  7, 15,  2,  8, 14, 12,  0,  1, 10,  6,  9, 11,  5},
        { 0, 14,  7, 11, 10,  4, 13,  1,  5,  8, 12,  6,  9,  3,  2, 15},
        {13,  8, 10,  1,  3, 15,  4,  2, 11,  6,  7, 12,  0,  5, 14,  9},
    },

    {
        {10,  0,  9, 14,  6,  3, 15,  5,  1, 13, 12,  7, 11,  4,  2,  8},
        {13,  7,  0,  9,  3,  4,  6, 10,  2,  8,  5, 14, 12, 11, 15,  1},
        {13,  6,  4,  9,  8, 15,  3,  0, 11,  1,  2, 12,  5, 10, 14,  7},
        { 1, 10, 13,  0,  6,  9,  8,  7,  4, 15, 14,  3, 11,  5,  2, 12},
    },

    {
        { 7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15},
        {13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9},
        {10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4},
        { 3, 15,  0,  6, 10,  1, 13,  8,  9,  4,  5, 11, 12,  7,  2, 14},
    },

    {
        { 2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9},
        {14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6},
        { 4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14},
        {11,  8, 12,  7,  1, 14,  2, 13,  6, 15,  0,  9, 10,  4,  5,  3},
    },

    {
        {12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11},
        {10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8},
        { 9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6},
        { 4,  3,  2, 12,  9,  5, 15, 10, 11, 14,  1,  7,  6,  0,  8, 13},
    },

    {
        { 4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1},
        {13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6},
        { 1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2},
        { 6, 11, 13,  8,  1,  4, 10,  7,  9,  5,  0, 15, 14,  2,  3, 12},
    },

    {
        {13,  2,  8,  4,  6, 15, 11,  1, 10,  9,  3, 14,  5,  0, 12,  7},
        { 1, 15, 13,  8, 10,  3,  7,  4, 12,  5,  6, 11,  0, 14,  9,  2},
        { 7, 11,  4,  1,  9, 12, 14,  2,  0,  6, 10, 13, 15,  3,  5,  8},
        { 2,  1, 14,  7,  4, 10,  8, 13, 15, 12,  9,  0,  3,  5,  6, 11},
    },
    };

int matrice_expansion[48] = {
  32,1,2,3,4,5,
  4,5,6,7,8,9,
  8,9,10,11,12,13,
  12,13,14,15,16,17,
  16,17,18,19,20,21,
  20,21,22,23,24,25,
  24,25,26,27,28,29,
  28,29,30,31,32,1};

int PI[64] = {
    58,50,42,34,26,18,10,2,
    60,52,44,36,28,20,12,4,
    62,54,46,38,30,22,14,6,
    64,56,48,40,32,24,16,8,
    57,49,41,33,25,17,9,1,
    59,51,43,35,27,19,11,3,
    61,53,45,37,29,21,13,5,
    63,55,47,39,31,23,15,7};

int PI_INV[64] = {
    40,8,48,16,56,24,64,32,
    39,7,47,15,55,23,63,31,
    38,6,46,14,54,22,62,30,
    37,5,45,13,53,21,61,29,
    36,4,44,12,52,20,60,28,
    35,3,43,11,51,19,59,27,
    34,2,42,10,50,18,58,26,
    33,1,41,9,49,17,57,25};

int PC1[56] = {
    57,49,41,33,25,17,9,1,58,50,42,34,26,18,
    10,2,59,51,43,35,27,19,11,3,60,52,44,36,
    63,55,47,39,31,23,15,7,62,54,46,38,30,22,
    14,6,61,53,45,37,29,21,13,5,28,20,12,4};

int PC2[48]={
    14,17,11,24,1,5,
    3,28,15,6,21,10,
    23,19,12,4,26,8,
    16,7,27,20,13,2,
    41,52,31,37,47,55,
    30,40,51,45,33,48,
    44,49,39,56,34,53,
    46,42,50,36,29,32};

int P[32]={
    16,7,20,21,29,12,28,17,
    1,15,23,26,5,18,31,10,
    2,8,24,14,32,27,3,9,
    19,13,30,6,22,11,4,25};

    /*int CLEF[56] = {
        0,1,2,3,4,5,6,8,
        9,10,11,12,13,14,16,17,
        18,19,20,21,22,24,25,26,
        27,28,29,30,32,33,34,35,
        36,37,38,40,41,42,43,44,
        45,46,48,49,50,51,52,53,
        54,56,57,58,59,60,61,62};*/


uint64_t K = 0x0123456789abcdef;

uint32_t getLeftPart(uint64_t number) {return number >>32; }
uint32_t getRightPart(uint64_t number) {return number; }
uint32_t getByteAtPos(uint32_t number, int pos) { return (number >> pos * 8) & 0xFF; }
uint32_t setByteAtPos(uint32_t number, int pos, uint8_t value) { return number & (value << pos * 8); }

uint64_t PermutationCle1(uint64_t bloc64){
  uint64_t temporaire=0x0;
  uint64_t res=0x0;
  int i=0;
  int position=0;
  for(;i<56;i++){
    position=64-PC1[i];
    //printf("position: %lx\n", position);
    temporaire=((bloc64 >> position)&0x01)<<(55-i);
    //printf("temporaire: %lx\n", temporaire);
    res=res^temporaire;
    //printf("res: %lx\n", res);
    temporaire=0x0;
    }
    printf("res: %lx\n", res);
    return res;
  }

uint64_t PermutationCle2(uint64_t bloc56){
  uint64_t temporaire=0x0;
  uint64_t res=0x0;
  int i=0;
  int position=0;
  for(;i<48;i++){
    position=56-PC2[i];
    //printf("position: %lx\n", position);
    temporaire=((bloc56 >> position)&0x01)<<(47-i);
    //printf("temporaire: %lx\n", temporaire);
    res=res^temporaire;
    //printf("res: %lx\n", res);
    temporaire=0x0;
  }
  res=res^0x0000FFFFFFFFFFFF;
  //printf("res: %lx\n", res);
  return res;
}

uint64_t melangerclef(uint64_t clef56,int tour){
  uint64_t res=clef56<<4;
  //printf("clef: %lx\n", res);
  uint32_t gauche = getLeftPart(res);
  //printf("gauche: %lx\n", gauche);
  uint32_t droite = getRightPart(res)>>4;
  //printf("droite: %lx\n", droite);
  uint32_t temporaire=0x0;
 if(tour==1||tour==2||tour==9||tour==16 ||tour==17 ||tour==18 ||tour ==25 ||tour==32){
    temporaire=((gauche&0x08000000)>>27)^((gauche<<1)&0x0FFFFFFF);
    //printf("gauche&0x080000: %lx\n", (gauche&0x08000000)>>27);
    gauche=temporaire;
    //printf("gauche: %lx\n", gauche);
    temporaire=0x0;
    temporaire=((droite&0x08000000)>>27)^((droite<<1)&0x0FFFFFFF);
    //printf("droite&0x080000: %lx\n", (droite&0x08000000)>>27);
    droite=temporaire;
    //printf("droite: %lx\n", droite);
    temporaire=0x0;
  }
  else
  {
    temporaire=((gauche&0x0c000000)>>26)^((gauche<<2)&0x0FFFFFFF);
    //printf("gauche&0x0c0000: %lx\n", (gauche&0x0c000000)>>26);
    gauche=temporaire;
    //printf("gauche: %lx\n", gauche);
    temporaire=0x0;
    temporaire=((droite&0x0c000000)>>26)^((droite<<2)&0x0FFFFFFF);
    //printf("droite&0x0c0000: %lx\n", (droite&0x0c000000)>>26);
    droite=temporaire;
    //printf("droite: %lx\n", droite);
    temporaire=0x0;
  }
  res=0x0;
  res=gauche;
  res=res<<28;
  res=res^droite;
  //printf("%i:res: %lx\n",tour, res);
  //printf("res: %lx\n", res);
  return res;
}

/*uint64_t vrai_cle(uint64_t bloc64){
  uint64_t temporaire=0x0;
  uint64_t res=0x0;
  int i=0;
  int position=0;
  for(;i<56;i++){
    position=64-CLEF[i];
    temporaire=(bloc64 >> position);
    temporaire=temporaire&0x01;
    temporaire=temporaire<<(55-i);
    res=res^temporaire;
    temporaire=0x0;
  }
  return res;
}*/

uint64_t permutation(uint64_t bloc64){
  uint64_t temporaire=0x0;
  uint64_t res=0x0;
  int i=0;
  int position=0;
  for(;i<64;i++){
    position=64-PI[i];
    temporaire=((bloc64 >> position)&0x01)<<(63-i);
    res=res^temporaire;
    temporaire=0x0;
  }
  return res;
}

uint64_t permutationInv(uint64_t bloc64){
  uint64_t temporaire=0x0;
  uint64_t res=0x0;
  int i=0;
  int position=0;
  for(;i<64;i++){
    position=64-PI_INV[i];
    temporaire=((bloc64 >> position)&0x01)<<(63-i);
    res=res^temporaire;
    temporaire=0x0;
  }
  return res;
}

uint32_t permutationf(uint32_t bloc32){
  uint64_t temporaire=0x0;
  uint64_t res=0x0;
  int i=0;
  int position=0;
  for(;i<32;i++){
    position=32-P[i];
    temporaire=((bloc32 >> position)&0x01)<<(31-i);
    res=res^temporaire;
    temporaire=0x0;
  }
  return res;
}

uint64_t expansion(uint32_t bloc32){
  uint64_t temporaire=0x0;
  uint64_t res=0x0;
  int i=0;
  int position=0;
  for(;i<48;i++){
    position=32-matrice_expansion[i];
    temporaire=((bloc32 >> position)&0x01);
    temporaire=temporaire<<(47-i);
    res=res^temporaire;
    temporaire=0x0;
  }
  return res;
}

uint32_t s_box(uint64_t bloc48){
  uint32_t res=0x0;
  uint8_t position=0x0;
  uint32_t temporaire=0x0;
  int i=1;
  for(;i<9;i++){
    position=((bloc48)>>(48-6*i)) & 0xFF;

    //printf("position %lx\n", position);

    int colonne=(int)((position&0x1e)>>1);
    int ligne=(int)((position>>4)&0x21);
    ligne =(ligne^(ligne>>4))^0x03;

    //printf("colonne: %lx\n", colonne);
    //printf("ligne: %lx\n", ligne);

    temporaire=SBOX[i-1][ligne][colonne];

    //printf("temporaire %lx\n", temporaire);
    temporaire=temporaire<<(32-4*i);

    //printf("temporaire %lx\n", temporaire);
    res=res^temporaire;

    //printf("res %lx\n", res);

    temporaire=0x0;
  }
  return res;
}

uint32_t f(uint32_t bloc32, int i){
  printf("i: %lx\n", i);
  uint32_t res;
  uint32_t clef=PermutationCle2(K);
  int j=0;
  for(;j<i+1;j++){
    clef=PermutationCle2(clef);
    printf("clef: %lx\n", clef);
  }
  printf("cleff: %lx\n", clef);
  res=permutationf(s_box(expansion(bloc32)^clef));
  return res;
}

uint64_t DES_codage(uint64_t bloc64){
   int j=0;
   uint64_t res=bloc64;
   uint32_t gauche;
   for(;j<16;j++){
     gauche=getLeftPart(res);
     gauche=f(gauche,j);
     res = res << 32;
     res=res^(gauche);
     printf("res: %lx\n", res);
   }
   gauche=getLeftPart(res);
   res = res << 32;
   res=res^(gauche);
   return res;
}

uint64_t DES_decodage(uint64_t bloc64){
   int j=15;
   uint64_t res=bloc64;
   uint32_t gauche;
   for(;j>0;j--){
     gauche=getLeftPart(res);
     gauche=f(gauche,j);
     res = res << 32;
     res=res^gauche;
     printf("res: %lx\n", res);
   }
   /*gauche=getLeftPart(res);
   res = res << 32;
   res=res^(gauche);*/
   return res;
}


void main(){
  uint64_t u=0x0123456789abcdef;
  u=(PermutationCle1(u));
  printf("u: %lx\n", u);
  int i = 1;
  for(;i<16;i++){
  u=(melangerclef(u,i));
  printf("%i:u: %lx\n",i, PermutationCle2(melangerclef(u,i)));
}
}
