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
    
    float somme = 0;

    for (int i = 0; i < len; i++)
    {
        somme += t[i];
    }

    printf("\nLa moyenne des elements est: %.2f\n", somme / len);
}