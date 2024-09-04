#include <stdio.h>

int main(){

    long long int num;
    printf("Entrer un nombre: ");
    scanf("%lld", &num);

    int puiss;
    printf("Entrer la puissance: ");
    scanf("%d", &puiss);

    long long int resultat = num;

    for (int i = 1; i < puiss; i++)
    {
        resultat *= num;
    }

    printf("%lld a la puissance de %d est: %lld", num, puiss, resultat);
}