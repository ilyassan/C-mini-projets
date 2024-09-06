#include <stdio.h>
#include <string.h>

typedef struct
{
    char titre[50];
    char auteur[50];
    char annee[5];
} Livre;

Livre creeLivre(){
    Livre livre;
    strcpy(livre.titre, "La boite a merveille");
    strcpy(livre.auteur, "Ahmed Sefrioui");
    strcpy(livre.annee, "1954");

    return livre;
}


int main(){

    Livre livre = creeLivre();
    
    printf("Titre: %s\nAuteur: %s\nAnnee: %s", livre.titre, livre.auteur, livre.annee);

    return 0;
}