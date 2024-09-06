#include <stdio.h>

typedef struct
{
    int longueur;
    int largeur;
} Rectangle;


int air(Rectangle rectangle){
    return rectangle.largeur * rectangle.longueur;
}

int main(){

    Rectangle rectangle;

    rectangle.largeur = 10;
    rectangle.longueur = 8;
    
    printf("L'aire: %d", air(rectangle));

    return 0;
}