#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>


// Définir les constants
#define MAX_TITRE 32
#define MAX_DESCRIPTION 100

// Définir la structure de Contact
typedef struct
{
    int id;
    char titre[MAX_TITRE];
    char description[MAX_DESCRIPTION];
    int statut;
    struct {
        int jour;
        int mois;
        int annee;
    } DeadLine;
} Tache;

// Définir les global variables
Tache *taches = NULL;
int tachesLen = 0;

char fichier[] = "taches.txt";


// Définir les fonctions



// --------- Le Main Fonction ---------
int main(){

    int travail = 1;

    // La menu principale
    while (travail)
    {
        puts("#### Gestion des Taches ####");
        puts("\n\t1. Ajoute Un Tache");
        puts("\t2. Afficher Tous Les Taches");
        puts("\t3. Modifier Un Tache");
        puts("\t4. Supprimer Un Tache");
        puts("\t5. Rechercher Un Tache");
        puts("\t6. Quitter Le Program");

        printf("\nEntrer votre choix: ");
        int choix;
        scanf("%d", &choix);
        while (getchar() != '\n');

        switch (choix)
        {
        case 1:
        
            break;
        case 2:
        
            continue;
        case 3:
        
            break;
        case 4:
        
            break;
        case 5:
        
            break;
        case 6:
            travail = 0;
            break;
        
        default:
            puts("Choix invalid.");
        }

        // Pour retour au menu principal
        choix = 0;
        while (choix != 1 && travail != 0) {
            puts("\n----------------");
            puts("1. Retour");
            printf("Entrez votre choix: ");
            scanf("%d", &choix);
            while (getchar() != '\n');
        }
    }

    return 0;
}