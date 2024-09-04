#include <stdio.h>


int main(){

    char jours[][10] = {"Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi", "Dimanche"};

    for (int i = 0; i < 7; i++)
    {
        printf("%d => %s\n", i + 1, jours[i]);
    }

    int choix;
    printf("Choisir un jour (1 - 7): ");
    scanf("%d", &choix);

    for (int i = choix - 1, j = 1; i < 7; i++, j++)
    {
        printf("%d => %s\n", j, jours[i]);
    }
    
    return 0;
}