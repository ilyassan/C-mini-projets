#include <stdio.h>
#include <string.h>

int main(){

    char nom[30];

    printf("Entrer le nom: ");
    fgets(nom, sizeof(nom), stdin);
    nom[strcspn(nom, "\n")] = '\0';
    

    printf("Le nom est %s\n", nom);

    return 0;
}