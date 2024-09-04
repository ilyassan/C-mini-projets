#include <stdio.h>

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
    
    int facteur;
    printf("\nViellez entrer le facteur: ");
    scanf("%d", &facteur);

    for (int i = 0; i < len; i++)
    {
        t[i] = facteur * t[i];
    }


    for (int i = 0; i < len; i++)
    {
        if (i + 1 == len)
        {
            printf("%d", t[i]);
            break;
        }
        printf("%d => ", t[i]);
    }

    return 0;
}