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
    
    int min = __INT16_MAX__;

    for (int i = 0; i < len; i++)
    {
        if (t[i] < min)
        {
            min = t[i];
        }
    }

    printf("\nLa minimum valeur est: %d\n", min);
}