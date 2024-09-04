#include <stdio.h>

int main(){

    int n;
    printf("Entrer un entier pour reverser: ");
    scanf("%d", &n);

    int rev = 0;
    while (n)
    {
        rev = (rev * 10) + (n % 10);
        n /= 10;
    }

    printf("La resultat est: %d", rev);

    return 0;
}