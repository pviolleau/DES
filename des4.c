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
  //on initialise le résultat et un bloc "tampon"
  uint64_t temporaire=0x0;
  uint64_t res=0x0;
  int i=0;
  int position=0;
  //On cherche a avoir un bloc de 56 bits à la fin
  for(;i<56;i++){
    //position sera la position du bit à aller chercher
    //dans le bloc passé en paramètre (en partant de la droite)
    position=64-PC1[i];
    //on décale jusqu'au bit voulu et on fait un et avec 0x01 pour n'obtenir que le bit voulu
    //on le redécale ensuite de 55 moins l'itération
    temporaire=((bloc64 >> position)&0x01)<<(55-i);
    //on fait un ou exclusif entre res et temporaire qui ne contient qu'un bit
    res=res^temporaire;
    temporaire=0x0;
    }
    //temporaire est rempli bit à bit en commencant par la gauche
    //on s'assure de renvoyer un bit de 56
    return res&0x00FFFFFFFFFFFFFF;
  }

uint64_t PermutationCle2(uint64_t bloc56){
  //même méthode que pour PermutationCle1 mais cette fois avec 48 bits
  uint64_t temporaire=0x0;
  uint64_t res=0x0;
  int i=0;
  int position=0;
  for(;i<48;i++){
    position=56-PC2[i];
    temporaire=((bloc56 >> position)&0x01)<<(47-i);
    res=res^temporaire;
    temporaire=0x0;
  }
  res=res&0x0000FFFFFFFFFFFF;
  return res;
}

uint64_t melangerclef(uint64_t clef56,int tour){
  //on décale de 4 pour obtenir les 56 bits au milieu
  uint64_t res=clef56<<4;
  //on sépare en 2
  uint32_t gauche = getLeftPart(res);
  uint32_t droite = getRightPart(res)>>4;
  uint32_t temporaire=0x0;
  // au tour 1,2,9 ou 16 on ne décale que de un
 if(tour==1||tour==2||tour==9||tour==16){
   //on récupère seulement le 5e bit (le 1er bit si l'on ne considère
   //pas les 4 0 devant)
   //on le shift de 27 pour le mettre en dernière position
   //on shift le bloc de 1 pour laisser place au bit que l'on
   //vient de récupérer
    temporaire=((gauche&0x08000000)>>27)^((gauche<<1)&0x0FFFFFFF);
    gauche=temporaire;
    temporaire=0x0;
    //même principe mais pour le côté droit
    temporaire=((droite&0x08000000)>>27)^((droite<<1)&0x0FFFFFFF);
    droite=temporaire;
    temporaire=0x0;
  }
  else
  {
    //même principe mais cette fois avec 2 bits
    temporaire=((gauche&0x0c000000)>>26)^((gauche<<2)&0x0FFFFFFF);
    gauche=temporaire;
    temporaire=0x0;
    temporaire=((droite&0x0c000000)>>26)^((droite<<2)&0x0FFFFFFF);
    droite=temporaire;
    temporaire=0x0;
  }
  //on reconcatene les 2 et on a 8 bits nuls et 56 bits qui forment la clef
  res=0x0;
  res=gauche;
  res=res<<28;
  res=res^droite;
  return res;
}

uint64_t melangerclefd(uint64_t clef56,int tour){
  //même principe mais au lieu de prendre le 1er ou 2e bit et
  //de les décaler vers la fin on prend le ou les 2 derniers
  //et on les décale au début
  //autre changement, le tour un est traiter comme les autres
  uint64_t res=clef56<<4;
  uint32_t gauche = getLeftPart(res);
  uint32_t droite = getRightPart(res)>>4;
  uint32_t temporaire=0x0;
 if(tour==2||tour==9||tour==16){
    temporaire=((gauche&0x00000001)<<27)^((gauche>>1)&0x07FFFFFF);
    gauche=temporaire;
    temporaire=0x0;
    temporaire=((droite&0x00000001)<<27)^((droite>>1)&0x07FFFFFF);
    droite=temporaire;
    temporaire=0x0;
  }
  else
  {
    temporaire=((gauche&0x00000003)<<26)^((gauche>>2)&0x03FFFFFF);
    gauche=temporaire;
    temporaire=0x0;
    temporaire=((droite&0x00000003)<<26)^((droite>>2)&0x03FFFFFF);
    droite=temporaire;
    temporaire=0x0;
  }
  res=0x0;
  res=gauche;
  res=res<<28;
  res=res^droite;
  return res;
}

uint64_t permutation(uint64_t bloc64){
  //même principe que les autres permutations
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
  //même principe que permutation mais avec une autre matrice
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
  //toujours le même principe
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
  //même principe que les permutations sauf que cette fois ci
  //on passe d'un bloc de 32bits à un bloc de 48 en copiant
  //certains bits
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
  //on initialise les données
  uint32_t res=0x0;
  uint8_t position=0x0;
  uint32_t temporaire=0x0;
  int i=1;
  //on sépare le bloc de 48 bits en 8 blocs de 6
  for(;i<9;i++){
    //on récupère le ième groupe de 6 bits
    position=((bloc48)>>(48-6*i)) & 0x3F;
    //le numéro de la colonne est égale aux bits 2,3,4 et 5
    //on le shift de 1 pour tout avoir sur 4 bits
    int colonne=(int)((position&0x1e)>>1);
    //pour la ligne ce sont les 1er et 6e bits, on les regroupe
    int ligne=(int)((position&0x02)>>4)^(position&0x01);
    //on cherche les valeurs correspondantes dans les S_box
    temporaire=SBOX[i-1][ligne][colonne];
    //on décale au bon endroit
    temporaire=temporaire<<(32-4*i);
    res=res^temporaire;
    temporaire=0x0;
  }
  return res;
}

uint32_t f(uint32_t blocGauche, uint32_t blocDroit, int i){
  //la fonction f qui regroupe toute les autres fonctions
  uint32_t res;
  int j=1;
  //on permute la clef K
  uint64_t clef=PermutationCle1(K);
  //on la mélange pour obtenir la clef correspondant au bon tour
  for(;j<i+1;j++){
    //on appelle la fonction mélanger
    clef=(melangerclef(clef,j));}
    //on la permute une dernière fois
  clef=PermutationCle2(clef);
  //le résultat est le ou exclusif du bloc gauche et de
  //la permutation final du résultat obtenu avec le ou exclusif
  //entre les s_box et la clef (pour utiliser la fonction s_box
  //on expanse d'abord le bloc droit)
  res=(permutationf(s_box((expansion(blocDroit))^clef)))^blocGauche;
  return res;
}

uint32_t fd(uint32_t blocGauche, uint32_t blocDroit, int i){
  //la fonction f qui permet de décoder seul le mélange change
  uint32_t res;
  int j=1;
  uint64_t clef=PermutationCle1(K);
  for(;j<i+1;j++){
    clef=(melangerclefd(clef,j));}
  clef=PermutationCle2(clef);
  res=(permutationf(s_box((expansion(blocDroit))^clef)))^blocGauche;
  printf("res: %lx\n", res);
  return res;
}

uint64_t DES_codage(uint64_t bloc64){
  //la fonction des
   int j=1;
   uint32_t temporaire=0x0;
   uint64_t res;
   for(;j<17;j++){
     //la partie droite du résultat final partie gauche, droite et tour
     temporaire =f(getLeftPart(res),getRightPart(res),j);
     //le bloc de droite se retrouve à gauche
     res = res << 32;
     // on ajoute le bloc droit
     res=res^(temporaire);
     printf("res: %lx\n", res);
     temporaire=0x0;
   }
   return res;
}

uint64_t DES_decodage(uint64_t bloc64){
//meme chose que DES_codage mais pour décoder
int j=1;
uint64_t res;
uint32_t temporaire=0x0;
for(;j<17;j++){
  temporaire =fd(getLeftPart(res),getRightPart(res),j);
  res = res << 32;
  res=res^(temporaire);
  printf("res: %lx\n", res);
  temporaire=0x0;
}
return res;
}


void main(){
  uint64_t mot=0x0123456789abcdef;
  printf("mot: %lx\n", mot);
  mot=permutation(mot);
  printf("mot permuté: %lx\n", mot);
  mot=DES_codage(mot);
  printf("mot codé: %lx\n", mot);
  mot=permutationInv(mot);
  printf("mot final: %lx\n", mot);
}
