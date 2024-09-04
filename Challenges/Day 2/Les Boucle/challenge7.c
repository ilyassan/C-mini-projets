#include <stdio.h>

int main(){

    int n;
    printf("La somme fibanoci de 1 - n (Entrer n): ");
    scanf("%d", &n);

    int somme = 0;
    for (int i = 1; i <= n; i++)
    {
        somme += i;
    }

    printf("La somme de fibanoci est: %d", somme);

    return 0;
}