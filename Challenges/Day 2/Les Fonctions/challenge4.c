#include <stdio.h>

int min(int num1, int num2);

int main(){

    int num1;
    printf("Entrer le premier nombre: ");
    scanf("%d", &num1);

    int num2;
    printf("Entrer le deuxieme nombre: ");
    scanf("%d", &num2);


    int resultat = min(num1, num2);

    printf("Le maximum des deux nombre est: %d", resultat);

    return 0;
}


int min(int num1, int num2){
    return num1 < num2 ? num1 : num2;
}