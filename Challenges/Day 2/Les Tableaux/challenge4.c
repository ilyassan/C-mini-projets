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
    
    int max = -__INT16_MAX__;

    for (int i = 0; i < len; i++)
    {
        if (t[i] > max)
        {
            max = t[i];
        }
    }

    printf("\nLa maximum valeur est: %d\n", max);

    return 0;
}