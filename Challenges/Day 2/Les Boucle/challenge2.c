#include <stdio.h>

void printEtoilesLigne(int etoiles, int max);

int main(){

    int lignes;
    printf("Entrer le nombre des ligne dans le pyramide: ");
    scanf("%d", &lignes);

    puts("---------------------");

    int etoiles = 1;
    int maxEtoiles = lignes * 2 - 1;

    for (int i = 1; i <= lignes; i++)
    {
        printEtoilesLigne(etoiles, maxEtoiles);
        printf("\n");
        etoiles += 2;
    }
}


void printEtoilesLigne(int etoiles, int max){
    int demiPart = (max - etoiles) / 2;

    for (int i = 0; i < demiPart ; i++)
    {
        printf(" ");
    }

    for (int i = 0; i < etoiles; i++)
    {
        printf("*");
    }
    
    for (int i = 0; i < demiPart ; i++)
    {
        printf(" ");
    }
}