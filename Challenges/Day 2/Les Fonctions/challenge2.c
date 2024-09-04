#include <stdio.h>

int multiplication(int num1, int num2);

int main(){

    int num1;
    printf("Entrer le premier nombre: ");
    scanf("%d", &num1);

    int num2;
    printf("Entrer le deuxieme nombre: ");
    scanf("%d", &num2);


    int resultat = multiplication(num1, num2);

    printf("Le produit des deux nombre est: %d", resultat);

    return 0;
}


int multiplication(int num1, int num2){
    return num1 * num2;
}