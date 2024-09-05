#include <stdio.h>

long long int factorial(int n);

int main(){

    long long int num;
    printf("Entrer un nombre pour donner le factorial: ");
    scanf("%lld", &num);

    long long int resultat = factorial(num);

    
    printf("Le factorial de %lld est %lld", num, resultat);

    return 0;
}


long long int factorial(int n){
    if (n == 0 || n == 1)
    {
        return 1;
    }
    

    return n * factorial(n - 1);
}