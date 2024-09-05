#include <stdio.h>

// Etaps
// 1-Ajouter un contact 
// 2-Modifier un contact
// 3-Supprimer un contact
// 4-Afficher tous les contact
// 5-Recherche un contact

// Des idées
// 1-Binrary search
// 2-Sauvegarder les contacts dans une exterieur fichier
// 3-Charger les contacts sauvegarder en le debut de program
// 4-Validation des inputs

#define MAX_NOM 100
#define MAX_TELEPHONE 10
#define MAX_EMAIL 30

typedef struct
{
    char nom[MAX_NOM];
    char telephone[MAX_TELEPHONE];
    char email[MAX_EMAIL];
} Contact;



int main(){

    int travail = 1;

    while (travail)
    {
        puts("#### Carnet des contact ####");
        puts("\n\t1. Afficher Tous Les Contact");
        puts("\t2. Ajoute Un Contact");
        puts("\t3. Modifier Un Contact");
        puts("\t4. Supprimer Un Contact");
        puts("\t5. Rechercher Un Contact");
        puts("\t6. Quitter Le Program");

        printf("Entrer votre choix: ");
        int choix;
        scanf("%d", &choix);

                switch (choix)
        {
        case 1:
        
            break;
        case 2:
        
            break;
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
            break;
        }

        // Retour au menu principal
        choix = 0;
        while (choix != 1 && travail != 0) {
            puts("\n###############");
            puts("1. Retour");
            printf("Entrez votre choix: ");
            scanf("%d", &choix);
        }
    }
    
    return 0;
}