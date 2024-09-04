#include <stdio.h>

int main(){

    int n;
    printf("La factorial de n, entrer n: ");
    scanf("%d", &n);

    int factorial = n;
    for (int i = n - 1; i > 1; i--)
    {
        factorial *= i ;
    }
    
    printf("Le factorial de %d est: %d", n, factorial);
}