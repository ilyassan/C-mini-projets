#include <stdio.h>

void trouverMin(int t[], int len, int *min, int *indice);

int main(){

    int t[] = {5, 6, 3, 8, 1, 10};
    int len = sizeof(t) / sizeof(t[0]);

    int min = t[0];
    int indice = 0;

    trouverMin(t, len, &min, &indice);

    printf("L'element minimum est %d dans l'indice  %d", min, indice);

    return 0;
}


void trouverMin(int t[], int len, int *min, int *indice){
    for (int i = 1; i < len; i++)
    {
        if (t[i] < *min)
        {
            *min = t[i];
            *indice = i;
        }
        
    }
}