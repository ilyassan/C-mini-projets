#include <stdio.h>

void trouverMax(int t[], int len, int *max, int *indice);

int main(){

    int t[] = {5, 6, 3, 8, 1, 10};
    int len = sizeof(t) / sizeof(t[0]);

    int max = t[0];
    int indice = 0;

    trouverMax(t, len, &max, &indice);

    printf("L'element maximum est %d dans l'indice  %d", max, indice);

    return 0;
}


void trouverMax(int t[], int len, int *max, int *indice){
    for (int i = 1; i < len; i++)
    {
        if (t[i] > *max)
        {
            *max = t[i];
            *indice = i;
        }
        
    }
}