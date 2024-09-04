#include <stdio.h>

int somme(int num1, int num2);

int main(){

    int num1;
    printf("Entrer le premier nombre: ");
    scanf("%d", &num1);

    int num2;
    printf("Entrer le deuxieme nombre: ");
    scanf("%d", &num2);


    int resultat = somme(num1, num2);

    printf("La somme des deux nombre est: %d", resultat);

    return 0;
}


int somme(int num1, int num2){
    return num1 + num2;
}