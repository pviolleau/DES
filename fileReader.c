#include "fileReader.h"

int getData(uint64_t** dataArray)
{
    struct stat st;
    int size = 0;
    int nbBlocs = 0;
    FILE* file = NULL;

    file = fopen("test_final.txt", "r+");

    if(file == NULL)
    {
        printf("Ce ficier n'existe pas !\n");
    }
    else
    {
        stat("test_final.txt", &st);
        size = st.st_size;

        printf("taille : %d\n", size);

        nbBlocs = size / 8;

        if(size % 8 > 0)
            nbBlocs++;

        *dataArray = malloc(sizeof(uint64_t) * nbBlocs);

        fread(*dataArray, 8, nbBlocs, file);
    }

    return nbBlocs;
}

void printData(uint64_t** dataArray, int nbBlocs)
{
    FILE* file = NULL;

    file = fopen("test_final_res.txt", "w+");

    if(file == NULL)
    {
        printf("Ce ficier n'existe pas !\n");
    }
    else
    {
        fwrite(*dataArray, 8, nbBlocs, file);
    }
}

int main(int argc, char** argv)
{
    uint64_t* dataArray = NULL;
    int nbBlocs = getData(&dataArray);
    int i;

    if(dataArray == NULL)
    {
        printf("Problème avec getData()\n");
    }
    else
    {
        printf("Affichage contenu avec des uint64_t : \n");

        for(i = 0; i < nbBlocs; i++)
        {
            printf("%" PRIu64, dataArray[i]);
        }

        printf("\n");

        printData(&dataArray, nbBlocs);

        free(dataArray);
    }
}
