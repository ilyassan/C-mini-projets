#include <stdio.h>

int main(){

    int n;
    printf("La somme des nombres entre 1 - n, entrer n: ");
    scanf("%d", &n);

    int somme = 0;

    // Method 1:
    // somme = n * (n + 1) / 2;
    // printf("La somme est: %d", somme);

    // Method 2 (Avec les boucles) :
    for (int i = 1; i <= n; i++)
    {
        somme += i;
    }
    
    printf("La somme est: %d", somme);

    return 0;
}