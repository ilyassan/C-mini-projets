#include <stdio.h>

void printTableux(int t[], int len);

int main(){
    
    int len;
    printf("Entrer le nombre des elements: ");
    scanf("%d", &len);

    int t[len];

    for (int i = 0; i < len; i++)
    {
        printf("\nEntrer le %d numero: ", i + 1);
        scanf("%d", &t[i]);
    }

    int target;
    printf("\nEntrer la valeur a remplacer: ");
    scanf("%d", &target);

    int nouvelleValeur;
    printf("\nEntrer nouvelle valeur: ");
    scanf("%d", &nouvelleValeur);

    puts("Avant:");
    printTableux(t, len);

    for (int i = 0; i < len; i++)
    {
        if (t[i] == target)
        {
            t[i] = nouvelleValeur;
        }
    }

    puts("\nApres:");
    printTableux(t, len);
}

void printTableux(int t[], int len){
    for (int i = 0; i < len; i++)
    {
        if (i + 1 == len)
        {
            printf("%d", t[i]);
            break;
        }
        printf("%d => ", t[i]);
    }
}