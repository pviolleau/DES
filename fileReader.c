#include "fileReader.h"

int getData(uint64_t** dataArray)
{
    struct stat st;
    int size = 0;
    FILE* file = NULL;

    file = fopen("test_final.txt", "r+");

    if(file == NULL)
    {
        printf("Ce ficier n'existe pas !\n");

        return 0;
    }
    else
    {
        stat("test_final.txt", &st);
        size = st.st_size;

        printf("taille : %d\n", size);

        *dataArray = malloc(sizeof(uint64_t) * size / 8);

        fread(*dataArray, 8, size / 8, file);

        return size;
    }
}

int main(int argc, char** argv)
{
    uint64_t* dataArray = NULL;
    int size = getData(&dataArray);
    int i;

    if(dataArray == NULL)
    {
        printf("Problème avec getData()\n");
    }
    else
    {
        printf("Affichage contenu avec des uint64_t : \n");

        for(i = 0; i < size; i++)
        {
            printf("%" PRIu64, dataArray[i]);
        }

        printf("\n");

        free(dataArray);
    }
}
