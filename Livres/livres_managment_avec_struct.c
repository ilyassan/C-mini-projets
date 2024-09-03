#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAUX_TVA 0.15
#define MAX_TITRE 50
#define MAX_AUTEUR 30


typedef struct {
    int id;
    char auteur[MAX_AUTEUR];
    char titre[MAX_TITRE];
    int quantite;
    float prix;
} Livre;

Livre *livres = NULL;
int debutDeId = 1;
int livresNombre = 0;


void ajouterUnLivre(); // Ajouter un livre en de stock
void metreAjourLaQuantiteDeLivre(int id, int quantite);

// Auxiliares
int estExiste(char titre[]); // Chercher le livre par titre

int main(){
    
    printf("#### Management de stock des livres ####");
    
    while (1)
    {
        puts("\n\t1. Afficher Tous les Livres Disponibles");
        puts("\t2. Ajoute Un Livre Au Stock");
        puts("\t3. Mettre à Jour La Quantite D'un Livre");
        puts("\t4. Supprimer Un Livre");
        puts("\t5. Afficher Le Nombre Des Produits");
        puts("\t6. Quitter Le Program");

        // Validation de la valeur entrer
        int choix;

        if (scanf("%d", &choix) == -1) continue;
        

        switch (choix)
        {
        case 1:
            ajouterUnLivre();
            break;
        
        default:
            break;
        }
    }
    
    return 0;
}


void ajouterUnLivre(){
    char titre[MAX_TITRE];
    char auteur[MAX_AUTEUR];
    int quantite;
    int prix;

    printf("Entrer le titre de livre: ");
    scanf("%s", titre);

    int siExiste = estExiste(titre); // si livre exist, la valeur de variable est le id de livre
    if (siExiste)
    {
        printf("Entrer la quantite ajouter: ");
        scanf("%d", &quantite);

        metreAjourLaQuantiteDeLivre(siExiste, quantite);
        return;
    }

    printf("Entrer le auteur de livre: ");
    scanf("%s", auteur);

    printf("Entrer la quantite de livre: ");
    scanf("%d", quantite);

    printf("Entrer le prix de livre: ");
    scanf("%d", prix);

    // utilise temp pour eviter les perde des données ou cas la realloc fail
    Livre *temp = (Livre*) realloc(livres, (livresNombre + 1) * sizeof(Livre));

    if (temp == NULL)
    {
        puts("Erreur lors de l'ajout d'un produit");
        return;
    }
    // Succéss

    livres = temp;
    puts("Le livre est ajoute avec succéss.");
}


void metreAjourLaQuantiteDeLivre(int id, int quantite){
    livres[id - 1].quantite += quantite;  // id - 1 car le id est commencer à partir de 1
}


int estExiste(char titre[]){
    for (int i = 0; i < livresNombre; i++)
    {
        if (strcmp(titre, livres[i].titre))
        {
            return livres[i].id; // Existe
        }
    }
    
    return 0; // N'existe pas
}