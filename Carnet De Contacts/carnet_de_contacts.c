#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

Contact *contacts = NULL;
int contactsLen = 0;


void ajouteUnContact();
void insertionAvecOrderDeNom(char nom[], char telephone[], char email[]);
int rechercheDichotomiqueParNom(char nom[]);
void afficherTousLesContact();
void modifierUnContact();
void supprimerUnContact();
int supprimerUnContactParIndice(int indice);



int main(){

    int travail = 1;

    while (travail)
    {
        puts("#### Carnet des contact ####");
        puts("\n\t1. Ajoute Un Contact");
        puts("\t2. Afficher Tous Les Contact");
        puts("\t3. Modifier Un Contact");
        puts("\t4. Supprimer Un Contact");
        puts("\t5. Rechercher Un Contact");
        puts("\t6. Quitter Le Program");

        printf("Entrer votre choix: ");
        int choix;
        scanf("%d", &choix);
        while (getchar() != '\n')break;

        switch (choix)
        {
        case 1:
            ajouteUnContact();
            break;
        case 2:
            afficherTousLesContact();
            break;
        case 3:
            modifierUnContact();
            break;
        case 4:
            supprimerUnContact();
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



void ajouteUnContact(){
    char nom[MAX_NOM];
    char telephone[MAX_TELEPHONE];
    char email[MAX_EMAIL];

    puts("Ajouter Un Contact: ");
    
    printf("\tEntrer le nom de contact: ");
    scanf("%s", nom);
    while (getchar() != '\n')break;

    if (rechercheDichotomiqueParNom(nom) != -1)
    {
        puts("Cette nom est deja existe.");
        return;
    }
    
    printf("\tEntrer le telephone de contact: ");
    scanf("%s", telephone);
    while (getchar() != '\n')break;

    printf("\tEntrer l'email de contact: ");
    scanf("%s", email);
    while (getchar() != '\n')break;


    Contact *temp = (Contact*) realloc(contacts, (contactsLen + 1) * sizeof(Contact));
    if (temp == NULL)
    {
        puts("Erreur lors de l'ajout d'un contact.");
        return;
    }
    // Allocation Succéss
    contacts = temp;

    // insertion avec order
    insertionAvecOrderDeNom(nom, telephone, email);

    contactsLen++;

    puts("Le contact est ajoute avec succes.");
}
void insertionAvecOrderDeNom(char nom[], char telephone[], char email[]){

    int indice = 0;

    int gauche = 0;
    int droit = contactsLen;
    
    while (gauche < droit)
    {
        int mid = (droit + gauche)/ 2;

        int comparaison = strcmp(nom, contacts[mid].nom);

        if (comparaison > 0)
        {
            gauche = mid + 1;
        }
        else if (comparaison < 0)
        {
            droit = mid - 1;
        }

        indice = mid;
    }
    

    for (int i = contactsLen; i != indice; i--)
    {
        Contact temp = contacts[i];
        contacts[i] = contacts[i - 1];
        contacts[i - 1] = temp;
    }

    strcpy(contacts[indice].nom, nom);
    strcpy(contacts[indice].telephone, telephone);
    strcpy(contacts[indice].email, email);
}

void afficherTousLesContact(){
    puts("Tous Les Contacts: ");

    if (contactsLen == 0)
    {
        puts("\tN'existe pas des contact pour afficher");
        return;
    }
    
    for (int i = 0; i < contactsLen; i++)
    {
        printf("\t%d => Le Nom: %s / Le Telephone: %s / L'email: %s\n",
            i + 1, contacts[i].nom, contacts[i].telephone, contacts[i].email
        );
    }
    
}

void modifierUnContact(){
    char nom[MAX_NOM];

    puts("Modifier Un Contact: ");

    printf("\tEntrer le nom de contact: ");
    scanf("%s", nom);
    while (getchar() != '\n')break;

    int indice = rechercheDichotomiqueParNom(nom);
    if (indice == -1)
    {
        puts("\tLe contact n'existe pas.");
        return;
    }
    
    char nouvelleNom[MAX_NOM];
    char nouvelleTelephone[MAX_TELEPHONE];
    char nouvelleEmail[MAX_EMAIL];

    printf("\tEntrer le nouvelle nom de contact: ");
    scanf("%s", nouvelleNom);
    while (getchar() != '\n')break;

    if (rechercheDichotomiqueParNom(nouvelleNom) != -1)
    {
        puts("\tCette nom est deja existe.");
        return;
    }
    
    printf("\tEntrer le nouvelle telephone de contact: ");
    scanf("%s", nouvelleTelephone);
    while (getchar() != '\n')break;

    printf("\tEntrer le nouvelle email de contact: ");
    scanf("%s", nouvelleEmail);
    while (getchar() != '\n')break;

    // Supprimer l'ancient contact et apres ajouter le nouveux (Pour l'order etre a-z)

    strcpy(contacts[indice].nom, nouvelleNom);
    strcpy(contacts[indice].telephone, nouvelleTelephone);
    strcpy(contacts[indice].email, nouvelleEmail);

    puts("Le contact est modifie avec succes");
}

void supprimerUnContact(){
    char nom[MAX_NOM];
    puts("Supprimer Un Contact: ");

    printf("\tEntrer le nom de contact: ");
    scanf("%s", nom);

    int indice = rechercheDichotomiqueParNom(nom);
    if (indice == -1)
    {
        puts("Le contact n'existe pas.");
        return;
    }
    

    if (supprimerUnContactParIndice(indice))
    {
        puts("Contact supprime avec succes");
    }
}
int supprimerUnContactParIndice(int indice){
    for (int i = indice; i < contactsLen - 1; i++)
    {
        contacts[i] = contacts[i + 1];
    }

    contactsLen--;

    if (contactsLen == 0)
    {
        contacts = NULL;
        return 1;
    }

    Contact *temp = (Contact*) realloc(contacts, contactsLen * sizeof(Contact));

    if (temp == NULL)
    {
        puts("Probleme lors de supprimer le contact.");
        return 0;
    }
    // Allocation Succéss
    contacts = temp;
    
    return 1;
}


int rechercheDichotomiqueParNom(char nom[]){
    int gauche = 0;
    int droit = contactsLen - 1;
    
    while (gauche <= droit)
    {
        int mid = (droit + gauche)/ 2;

        int comparaison = strcmp(nom, contacts[mid].nom);

        if (comparaison > 0)
        {
            gauche = mid + 1;
        }
        else if (comparaison < 0)
        {
            droit = mid - 1;
        }
        else{
            return mid; // Contact trouve, retourner l'indice
        }
    }

    return -1; // Contact N'existe pas
}
