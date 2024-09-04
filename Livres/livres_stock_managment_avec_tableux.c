#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_TITRE 50
#define MAX_AUTEUR 30


char titres[100][MAX_TITRE];
char auteurs[100][MAX_AUTEUR];
int lesPrix[100];
int lesQuantites[100];

int livresNombre = 0;



void afficherLesLivres(); // Afficher tout les livres
void ajouterUnLivre(); // Ajouter un livre en de stock
void metreAjourLaQuantiteDeLivre();
void metreAjourLaQuantite(int id, int quantite);
void supprimerUnLivre();

// Auxiliares
int estExiste(char titre[]); // Chercher le livre par titre

int main(){
    
    int run = 1;

    while (run)
    {
        puts("#### Management de stock des livres ####");
        puts("\n\t1. Afficher Tous les Livres Disponibles");
        puts("\t2. Ajoute Un Livre Au Stock");
        puts("\t3. Mettre a Jour La Quantite D'un Livre");
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
            puts("Choix invalide.");
            continue;
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
        if (lesQuantites[i] <= 0)
        {
            continue;
        }
        
       printf("\t%d => Titre: %s / Auteur: %s / Quantite: %d / Prix: %d\n",
       i + 1, titres[i], auteurs[i], lesQuantites[i], lesPrix[i]);
    }
}


void ajouterUnLivre(){
    char titre[MAX_TITRE];
    char auteur[MAX_AUTEUR];
    int quantite;
    int prix;

    printf("Entrer le titre de livre: ");
    scanf("%s", titres[livresNombre]);

    int siExiste = estExiste(titres[livresNombre]); // si livre exist, la valeur de variable est le id de livre
    if (siExiste != -1)
    {
        printf("Entrer la quantite ajouter: ");
        scanf("%d", &quantite);

        metreAjourLaQuantite(siExiste, quantite);
        return;
    }
    
    printf("Entrer le auteur de livre: ");
    scanf("%s", auteurs[livresNombre]);
    

    printf("Entrer la quantite de livre: ");
    scanf("%d", &lesQuantites[livresNombre]);

    printf("Entrer le prix de livre: ");
    scanf("%d", &lesPrix[livresNombre]);

    livresNombre++;

    puts("Le livre est ajoute avec succes.");
}

void metreAjourLaQuantiteDeLivre(){
    char titre[100];
    int quantite;

    printf("Entrer le titre de livre: ");
    scanf("%s", titre);
    
    int siExiste = estExiste(titre);

    if (siExiste == -1)
    {
        puts("Pas de livre avec cette titre.");
        return;
    }

    printf("Entrer la nouvelle quantite de livre: ");
    scanf("%d", &quantite);

    lesQuantites[siExiste] = quantite;

    puts("La quantite est modifie avec succes.");
}

void supprimerUnLivre(){
    char titre[100];
    
    printf("Entrer le titre de livre: ");
    scanf("%s", titre);

    int siExiste = estExiste(titre);

    if (siExiste == -1)
    {
        puts("Pas de livre avec cette titre.");
        return;
    }

    int index = siExiste;

    for (int i = index; i < livresNombre - 1; i++)
    {
        strcpy(titres[i], titres[i + 1]);
        strcpy(auteurs[i], auteurs[i + 1]);
        lesQuantites[i] = lesQuantites[i + 1];
        lesPrix[i] = lesPrix[i + 1];
    }

    livresNombre--;

    puts("Livre supprime avec succes");
}


// Auxiliers

void metreAjourLaQuantite(int i, int quantite){
    lesQuantites[i] += quantite;
}

int estExiste(char titre[]){
    for (int i = 0; i < livresNombre; i++)
    {
        if (strcmp(titre, titres[i]) == 0)
        {
            return i; // Existe
        }
    }
    return -1; // N'existe pas
}