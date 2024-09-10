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


void afficherLesLivres(Livre livresTrier[]); // Afficher tous les livres
void afficherSousMenu();
int afficherLesOptionOrder();
void afficherLesLivresTrierParTitre();
void afficherLesLivresTrierParAuteur();
void afficherLesLivresTrierParQuantite();
void afficherLesLivresTrierParPrix();


void ajouterUnLivre(); // Ajouter un livre en  stock
void metreAjourLaQuantiteDeLivre();
void supprimerUnLivre();

void ajouteLaQuantite(int i, int quantite);


// Auxiliares
void scanString(char string[], int size);
int estExiste(char titre[]); // Chercher le livre par titre

int main(){
    
    int travail = 1;
    
    while (travail)
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
            afficherSousMenu();
            continue;
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


void afficherLesLivres(Livre livresTrier[]){
    printf("\n");
    if (livresNombre == 0)
    {
        puts("N'existe pas des livres pour afficher.");
        return;
    }

    int croissante = afficherLesOptionOrder();
    
    puts("Tous les livres en le stock:\n");
    for (int i = 0; i < livresNombre; i++)
    {
        int indice = croissante ? i : livresNombre - 1 - i;
       printf("\t%d => Titre: %s / Auteur: %s / Quantite: %d / Prix: %.2f\n",
       i + 1, livresTrier[indice].titre, livresTrier[indice].auteur, livresTrier[indice].quantite, livresTrier[indice].prix);
    }

    return;
}

void afficherSousMenu() {
    int choix;

    while (1) {
        
        puts("\n\t1. Selon l'ordre d\'ajoutation");
        puts("\t2. Selon l'ordre alphabetique de titre");
        puts("\t3. Selon l'ordre alphabetique d'auteur");
        puts("\t4. Selon l'ordre de quantite");
        puts("\t5. Selon l'ordre de prix");
        puts("\t6. Retour au menu principal");
        
        printf("\nEntrer votre choix: ");
        scanf("%d", &choix);
        while (getchar() != '\n');

        switch (choix) {
            case 1:
                afficherLesLivres(livres);
                break;
            case 2:
                afficherLesLivresTrierParTitre();
                break;
            case 3:
                afficherLesLivresTrierParAuteur();
                break;
            case 4:
                afficherLesLivresTrierParQuantite();
                break;
            case 5:
                afficherLesLivresTrierParPrix();
                break;
            case 6:
                return; // Retourne au menu principal
            default:
                puts("Choix invalid.");
        }

        // Retour au menu principal
        choix = 0;
        while (choix != 1) {
            puts("\n###############");
            puts("1. Retour");
            printf("Entrez votre choix: ");
            scanf("%d", &choix);
            while (getchar() != '\n');
        }
    }
}

int afficherLesOptionOrder(){
    int choix;

    while (1) {
        
        puts("\t1. Selon l'ordre croissante");
        puts("\t2. Selon l'ordre decroissante");
        
        printf("\nEntrer votre choix: ");
        scanf("%d", &choix);
        while (getchar() != '\n');

        switch (choix) {
            case 1:
                return 1; // croissante
            case 2:
                return 0;// décroissante
            default:
                puts("Choix invalid.");
        }

        // Retour au menu principal
        choix = 0;
        while (choix != 1) {
            puts("\n###############");
            puts("1. Retour");
            printf("Entrez votre choix: ");
            scanf("%d", &choix);
            while (getchar() != '\n');
        }
    }
}

void afficherLesLivresTrierParTitre(){
    Livre *cpy = (Livre*) malloc(livresNombre * sizeof(Livre));
    memcpy(cpy, livres, livresNombre * sizeof(Livre));

    // Tri á bulles
    for (int i = 0; i < livresNombre; i++)
    {
        for (int j = 0; j < livresNombre - 1; j++)
        {
            if (strcmp(cpy[j].titre, cpy[j + 1].titre) > 0)
            {
                Livre temp = cpy[j];
                cpy[j] = cpy[j + 1];
                cpy[j + 1] = temp;
            }
        } 
    }

    afficherLesLivres(cpy);
    free(cpy);
}

void afficherLesLivresTrierParAuteur(){
    Livre *cpy = (Livre*) malloc(livresNombre * sizeof(Livre));
    memcpy(cpy, livres, livresNombre * sizeof(Livre));

    // Tri á bulles
    for (int i = 0; i < livresNombre; i++)
    {
        for (int j = 0; j < livresNombre - 1; j++)
        {
            if (strcmp(cpy[j].auteur, cpy[j + 1].auteur) > 0)
            {
                Livre temp = cpy[j];
                cpy[j] = cpy[j + 1];
                cpy[j + 1] = temp;
            }
        } 
    }

    afficherLesLivres(cpy);
    free(cpy);
}

void afficherLesLivresTrierParQuantite(){
    Livre *cpy = (Livre*) malloc(livresNombre * sizeof(Livre));
    memcpy(cpy, livres, livresNombre * sizeof(Livre));

    // Tri á bulles
    for (int i = 0; i < livresNombre; i++)
    {
        for (int j = 0; j < livresNombre - 1; j++)
        {
            if (cpy[j].quantite > cpy[j + 1].quantite)
            {
                Livre temp = cpy[j];
                cpy[j] = cpy[j + 1];
                cpy[j + 1] = temp;
            }
        } 
    }

    afficherLesLivres(cpy);
    free(cpy);
}

void afficherLesLivresTrierParPrix(){
    Livre *cpy = (Livre*) malloc(livresNombre * sizeof(Livre));
    memcpy(cpy, livres, livresNombre * sizeof(Livre));

    // Tri á bulles
    for (int i = 0; i < livresNombre; i++)
    {
        for (int j = 0; j < livresNombre - 1; j++)
        {
            if (cpy[j].prix > cpy[j + 1].prix)
            {
                Livre temp = cpy[j];
                cpy[j] = cpy[j + 1];
                cpy[j + 1] = temp;
            }
        } 
    }

    afficherLesLivres(cpy);
    free(cpy);
}

void ajouterUnLivre(){
    char titre[MAX_TITRE];
    char auteur[MAX_AUTEUR];
    int quantite;
    int prix;

    printf("\tEntrer le titre de livre: ");
    scanString(titre, sizeof(titre));

    int siExiste = estExiste(titre); // si livre exist, la valeur de variable est le id de livre
    if (siExiste != -1)
    {
        printf("\tEntrer la quantite ajouter: ");
        scanf("%d", &quantite);

        ajouteLaQuantite(siExiste, quantite);
        return;
    }

    printf("\tEntrer le auteur de livre: ");
    scanString(auteur, sizeof(auteur));

    printf("\tEntrer la quantite de livre: ");
    scanf("%d", &quantite);

    if (quantite <= 0)
    {
        puts("Erreur lors de l'ajout d'un livre.");
        return;
    }
    

    printf("\tEntrer le prix de livre: ");
    scanf("%d", &prix);

    // utilise temp pour eviter les perde des données ou cas la realloc fail
    Livre *temp = (Livre*) realloc(livres, (livresNombre + 1) * sizeof(Livre));

    if (temp == NULL)
    {
        puts("Erreur lors de l'ajout d'un livre.");
        return;
    }
    // Allocation Succéss

    livres = temp;

    strcpy(livres[livresNombre].titre, titre);
    strcpy(livres[livresNombre].auteur, auteur);
    livres[livresNombre].quantite = quantite;
    livres[livresNombre].prix = prix;

    livresNombre++;

    puts("Le livre est ajoute avec succes.");
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

void scanString(char string[], int size){
    if (fgets(string, size, stdin) != NULL) {
        string[strcspn(string, "\n")] = '\0';
    }
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