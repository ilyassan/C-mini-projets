#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>


// Définir les constants
#define MAX_TITRE 32
#define MAX_DESCRIPTION 100

// Définir la structure de Tache
typedef struct {
    int jour;
    int mois;
    int annee;
} Deadline;

typedef struct
{
    int id;
    char titre[MAX_TITRE];
    char description[MAX_DESCRIPTION];
    int statut;
    Deadline deadline;
} Tache;

// Définir les global variables
Tache *taches = NULL;
int tachesLen = 0;

char fichier[] = "taches.txt";


// Définir les fonctions
void ajouteUnTache();
int insertionAvecOrderDeNom(char titre[], char description[]);


int rechercheBinaireParNom(char titre[], int len);

void scanString(char string[], int size);


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
            ajouteUnTache();
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


void ajouteUnTache(){
    char titre[MAX_TITRE];
    char description[MAX_DESCRIPTION];
    Deadline deadline;

    puts("Ajouter Un Tache: ");
    
    printf("\tEntrer le titre de tache: ");
    scanString(titre, sizeof(titre));

    if (rechercheBinaireParNom(titre, tachesLen) != -1)
    {
        puts("\nCette titre est deja existe.");
        return;
    }
    
    printf("\tEntrer la description de tache: ");
    scanString(description, sizeof(description));

    printf("\n");

    // insertion avec order
    if (insertionAvecOrderDeNom(titre, description))
    {
        puts("La Tache est ajoute avec succes.");
        return;
    }

    puts("Erreur lors de l'ajout d'un Tache.");
}

int insertionAvecOrderDeNom(char titre[], char description[]) {
    Tache *temp = (Tache*) realloc(taches, (tachesLen + 1) * sizeof(Tache));
    if (temp == NULL)
    {
        return 0;
    }
    // Allocation Succéss
    taches = temp;

    int indice = tachesLen;

    for (int i = 0; i < tachesLen; i++) {
        if (strcmp(titre, taches[i].titre) < 0) {
            indice = i;
            break;
        }
    }

    for (int i = tachesLen; i > indice; i--) {
        taches[i] = taches[i - 1];
    }

    strcpy(taches[indice].titre, titre);
    strcpy(taches[indice].description, description);

    tachesLen++;

    return 1;
}

int rechercheBinaireParNom(char titre[], int len){
    if (len == 0) return -1;
    
    int gauche = 0;
    int droit = len - 1;
    
    while (gauche <= droit)
    {
        int mid = (droit + gauche)/ 2;

        int comparaison = strcmp(titre, taches[mid].titre);

        if (comparaison > 0)
        {
            gauche = mid + 1;
        }
        else if (comparaison < 0)
        {
            droit = mid - 1;
        }
        else{
            return mid; // Tache trouve, retourner l'indice
        }
    }

    return -1; // Tache N'existe pas
}



void scanString(char string[], int size){
    if (fgets(string, size, stdin) != NULL) {
        string[strcspn(string, "\n")] = '\0';
    }
}