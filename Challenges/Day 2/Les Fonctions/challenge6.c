#include <stdio.h>

long long int fib(int n);

int main(){

    long long int num;
    printf("Entrer un nombre pour donner le fibonacci: ");
    scanf("%lld", &num);

    long long int resultat = fib(num);

    
    printf("Le fibonacci de %lld est %lld", num, resultat);

    return 0;
}


long long int fib(int n){
    if (n == 0 || n == 1)
    {
        return n;
    }

    return fib(n - 1) + fib(n - 2);
}