#include <stdio.h>

void printerTableux(int t[], int len);


int main(){

    int n;
    printf("Entrer un nombre pour donner le tableux de multiplication: ");
    scanf("%d", &n);

    int somme = 0;
    for (int i = 1; i <= 10; i++)
    {
        somme += n * i;
        printf("%d * %d = %d\n", n, i, n * i);
    }
    
    printf("Et la somme des produits est: %d", somme);
}