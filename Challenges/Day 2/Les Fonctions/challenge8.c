#include <stdio.h>

int pairOuImpair(int num);

int main(){

    int num;
    printf("Entrer un nombre: ");
    scanf("%d", &num);

    if (pairOuImpair(num) == 1)
    {
        printf("Le nombre est pair");
        return 0;
    }
    
    printf("Le nombre est impair");

    return 0;
}


int pairOuImpair(int num){
    return num % 2 == 0 ? 1 : 0;
}