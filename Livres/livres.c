#include <stdio.h>
#include <stdlib.h>

#define TAUX_TVA 0.15
#define MAX_TITRE 50
#define MAX_AUTEUR 30


typedef struct {
    char auteur[MAX_AUTEUR];
    char titre[MAX_TITRE];
    int quantite;
    float prix;
} Livre;

Livre *livres = NULL;


int main(){
    
    printf("#### Management de stock des livres ####");
    
    while (1)
    {
        puts("1. Afficher Tous les Livres Disponibles");
        puts("2. Ajoute Un Livre Au Stock");
        puts("3. Mettre à Jour La Quantite D'un Livre");
        puts("4. Supprimer Un Livre");
        puts("5. Afficher Le Nombre Des Produits");
        puts("6. Quitter Le Program");

        // Validation de la valeur entrer
        int choix;

        if (scanf("%d", &choix) == -1) continue;
        

        switch (choix)
        {
        case 1:
            /* code */
            break;
        
        default:
            break;
        }
    }
    
    return 0;
}
