#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_TITRE 50
#define MAX_AUTEUR 30


typedef struct {
    char auteur[MAX_AUTEUR];
    char titre[MAX_TITRE];
    int quantite;
    float prix;
} Livre;

Livre *livres = NULL;
int livresNombre = 0;


void afficherLesLivres(); // Afficher tous les livres
void ajouterUnLivre(); // Ajouter un livre en  stock
void metreAjourLaQuantiteDeLivre();
void supprimerUnLivre();

void ajouteLaQuantite(int i, int quantite);


// Auxiliares
int estExiste(char titre[]); // Chercher le livre par titre

int main(){
    
    int run = 1;
    
    while (run)
    {
        puts("#### Management de stock des livres ####");
        puts("\n\t1. Afficher Tous les Livres Disponibles");
        puts("\t2. Ajoute Un Livre Au Stock");
        puts("\t3. Mettre à Jour La Quantite D'un Livre");
        puts("\t4. Supprimer Un Livre");
        puts("\t5. Afficher Le Nombre Des Livres");
        puts("\t6. Quitter Le Program");

        printf("Entrer votre choix: ");
        // Validation de la valeur entrer
        int choix;

        if (scanf("%d", &choix) == -1) continue;
        while (getchar() != '\n');
        
        
        switch (choix)
        {
        case 1:
            afficherLesLivres();
            break;
        case 2:
            ajouterUnLivre();
            break;
        case 3:
            metreAjourLaQuantiteDeLivre();
            break;
        case 4:
            supprimerUnLivre();
            break;
        case 5:
            printf("Le nombre des livres: %d", livresNombre);
            break;
        case 6:
            run = 0;
            break;
        
        default:
            break;
        }

        // Retour au menu principal
        choix = 0;
        while (choix != 1 && run != 0) {
            puts("\n###############");
            puts("1. Retour");
            printf("Entrez votre choix: ");
            scanf("%d", &choix);
        }
    }
    
    return 0;
}


void afficherLesLivres(){
    if (livresNombre == 0)
    {
        puts("Pas des livres pour afficher.");
        return;
    }
    
    puts("Tous les livres en le stock:");
    for (int i = 0; i < livresNombre; i++)
    {
       printf("\t%d => Titre: %s / Auteur: %s / Quantite: %d / Prix: %.2f\n",
       i + 1, livres[i].titre, livres[i].auteur, livres[i].quantite, livres[i].prix);
    }
}

void ajouterUnLivre(){
    char titre[MAX_TITRE];
    char auteur[MAX_AUTEUR];
    int quantite;
    int prix;

    printf("Entrer le titre de livre: ");
    scanf("%s", titre);

    int siExiste = estExiste(titre); // si livre exist, la valeur de variable est le id de livre
    if (siExiste != -1)
    {
        printf("Entrer la quantite ajouter: ");
        scanf("%d", &quantite);

        ajouteLaQuantite(siExiste, quantite);
        return;
    }

    printf("Entrer le auteur de livre: ");
    scanf("%s", auteur);

    printf("Entrer la quantite de livre: ");
    scanf("%d", &quantite);

    if (quantite <= 0)
    {
        puts("Erreur lors de l'ajout d'un livre");
        return;
    }
    

    printf("Entrer le prix de livre: ");
    scanf("%d", &prix);

    // utilise temp pour eviter les perde des données ou cas la realloc fail
    Livre *temp = (Livre*) realloc(livres, (livresNombre + 1) * sizeof(Livre));

    if (temp == NULL)
    {
        puts("Erreur lors de l'ajout d'un livre");
        return;
    }
    // Allocation Succéss

    livres = temp;

    strcpy(livres[livresNombre].titre, titre);
    strcpy(livres[livresNombre].auteur, auteur);
    livres[livresNombre].quantite = quantite;
    livres[livresNombre].prix = prix;

    livresNombre++;

    puts("Le livre est ajoute avec succéss.");
}

void metreAjourLaQuantiteDeLivre(){
    char titre[MAX_TITRE];
    printf("Entrer le titre de livre: ");
    scanf("%s", titre);

    int siExiste = estExiste(titre); // si livre exist, la valeur de variable est le id de livre
    if (siExiste == -1)
    {
        puts("Pas de livre avec cette titre.");
        return;
    }
    int i = siExiste;
    int quantite;

    printf("Entrer la nouvelle quantite de livre: ");
    scanf("%d", &quantite);

    livres[i].quantite = quantite;

    puts("La quantite est modifie avec succes");
}

void supprimerUnLivre(){
    char titre[MAX_TITRE];
    printf("Entrer le titre de livre: ");
    scanf("%s", titre);

    int siExiste = estExiste(titre); // si livre exist, la valeur de variable est le id de livre
    if (siExiste == -1)
    {
        puts("Pas de livre avec cette titre.");
        return;
    }

    for (int i = siExiste; i < livresNombre - 1; i++)
    {
        livres[i] = livres[i + 1];
    }

    livresNombre--;

    // utilise temp pour eviter les perde des données ou cas la realloc fail
    Livre *temp = (Livre*) realloc(livres, livresNombre * sizeof(Livre));

    if (temp == NULL)
    {
        puts("Probleme lors de supprimer le livre");
        return;
    }
    // Allocation Succéss
    livres = temp;

    puts("Livre supprimé avec succès.");
}


void ajouteLaQuantite(int i, int quantite){
    livres[i].quantite += quantite;
}

int estExiste(char titre[]){
    for (int i = 0; i < livresNombre; i++)
    {
        if (strcmp(titre, livres[i].titre) == 0)
        {
            return i; // Existe
        }
    }
    
    return -1; // N'existe pas
}