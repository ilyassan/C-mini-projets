#include <stdio.h>

int main(){

    int nombre;
    printf("Entrer le nombre: ");
    scanf("%d", &nombre);

    puts("---------------------");
    for (int i = 10; i > 0; i--)
    {
        printf("%d x %d = %d\n", nombre, i, nombre * i);
    }
}