#include <stdio.h>

typedef struct
{
    char nom[30];
    char prenom[30];
    int age;
} Personne;


int main(){

    Personne personne;

    printf("Entrer le nom: ");
    scanf("%s", personne.nom);

    printf("Entrer le prenom: ");
    scanf("%s", personne.prenom);

    printf("Entrer l'age: ");
    scanf("%d", &personne.age);
    

    printf("Le nom est %s\n", personne.nom);
    printf("Le prenom est %s\n", personne.prenom);
    printf("L'age est %d ans\n", personne.age);

    return 0;
}