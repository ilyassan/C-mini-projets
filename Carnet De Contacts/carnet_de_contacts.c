#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h> 


// Définir les constants
#define MAX_NOM 100
#define MAX_TELEPHONE 10
#define MAX_EMAIL 30

// Définir la structure de Contact
typedef struct
{
    char nom[MAX_NOM];
    char telephone[MAX_TELEPHONE];
    char email[MAX_EMAIL];
} Contact;

// Définir les global variables
Contact *contacts = NULL;
int contactsLen = 0;

char fichier[] = "contacts.txt";


// Définir les fonctions

void ajouteUnContact();
int insertionAvecOrderDeNom(char nom[], char telephone[], char email[], int len);

void afficherTousLesContact();

void modifierUnContact();

void supprimerUnContact();
int supprimerUnContactParIndice(int indice);

void afficherUnContact();

int rechercheDichotomiqueParNom(char nom[], int len);

void enregistrerLesContacts();
void chargerLesContacts();

void nettoyageEtQuitter(int signal);
void finProgram();


int main(){

    // Charger les contacts et call la fonction nettoyage si le programme interrompu.
    chargerLesContacts();
    signal(SIGINT, nettoyageEtQuitter);

    int travail = 1;

    // La menu principale
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
            afficherUnContact();
            break;
        case 6:
            travail = 0;
            break;
        
        default:
            break;
        }

        // Pour retour au menu principal
        choix = 0;
        while (choix != 1 && travail != 0) {
            puts("\n###############");
            puts("1. Retour");
            printf("Entrez votre choix: ");
            scanf("%d", &choix);
        }
    }
    
    // Les opérations de fin de programme
    finProgram();

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

    if (rechercheDichotomiqueParNom(nom, contactsLen) != -1)
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

    // insertion avec order
    if (insertionAvecOrderDeNom(nom, telephone, email, contactsLen))
    {
        puts("Le contact est ajoute avec succes.");
        return;
    }
    puts("Erreur lors de l'ajout d'un contact.");
}

int insertionAvecOrderDeNom(char nom[], char telephone[], char email[], int len) {
    Contact *temp = (Contact*) realloc(contacts, (contactsLen + 1) * sizeof(Contact));
    if (temp == NULL)
    {
        return 0;
    }
    // Allocation Succéss
    contacts = temp;

    int indice = len;

    for (int i = 0; i < len; i++) {
        if (strcmp(nom, contacts[i].nom) < 0) {
            indice = i;
            break;
        }
    }

    for (int i = len; i > indice; i--) {
        contacts[i] = contacts[i - 1];
    }

    strcpy(contacts[indice].nom, nom);
    strcpy(contacts[indice].telephone, telephone);
    strcpy(contacts[indice].email, email);

    contactsLen++;

    return 1;
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

    int indice = rechercheDichotomiqueParNom(nom, contactsLen);
    if (indice == -1)
    {
        puts("Le contact n'existe pas.");
        return;
    }
    
    char nouvelleNom[MAX_NOM];
    char nouvelleTelephone[MAX_TELEPHONE];
    char nouvelleEmail[MAX_EMAIL];

    printf("\tEntrer le nouvelle nom de contact: ");
    scanf("%s", nouvelleNom);
    while (getchar() != '\n')break;

    if (rechercheDichotomiqueParNom(nouvelleNom, contactsLen) != -1)
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

    if (strcmp(nom, nouvelleNom) != 0
        &&
        supprimerUnContactParIndice(indice)
        && 
        insertionAvecOrderDeNom(nouvelleNom, nouvelleTelephone, nouvelleEmail, contactsLen)
        )
    {
        puts("Le contact est modifie avec succes.");
        return;
    }

    puts("Erreur lors de modifie le contact.");

}

void supprimerUnContact(){
    char nom[MAX_NOM];
    puts("Supprimer Un Contact: ");

    printf("\tEntrer le nom de contact: ");
    scanf("%s", nom);

    int indice = rechercheDichotomiqueParNom(nom, contactsLen);
    if (indice == -1)
    {
        puts("Le contact n'existe pas.");
        return;
    }
    

    if (supprimerUnContactParIndice(indice))
    {
        puts("Contact supprime avec succes");
        return;
    }
    puts("Probleme lors de supprimer le contact.");
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
        return 0;
    }
    // Allocation Succéss
    contacts = temp;
    
    return 1;
}

void afficherUnContact(){
    char nom[MAX_NOM];

    puts("Afficher Un Contact: ");

    printf("\tEntrer le nom de contact: ");
    scanf("%s", nom);
    while (getchar() != '\n')break;

    int indice = rechercheDichotomiqueParNom(nom, contactsLen);
    if (indice == -1)
    {
        puts("Le contact n'existe pas.");
        return;
    }

    Contact contact = contacts[indice];

    printf("\tLe Nom: %s\n", contact.nom);
    printf("\tLe Telephone: %s\n", contact.telephone);
    printf("\tL'email: %s\n", contact.email);
}


int rechercheDichotomiqueParNom(char nom[], int len){
    if (len == 0) return -1;
    
    int gauche = 0;
    int droit = len - 1;
    
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


// --------- Les Fonctions De Fin De Programme ---------
void nettoyageEtQuitter(int signal) {
    // Effectuer les opérations de nettoyage
    finProgram();

    puts("\nProgramme interrompu. Contacts enregistrées.");
    exit(0);
}

void finProgram(){
    enregistrerLesContacts();
    free(contacts);
}

// --------- Entregistrer Les Contacts ---------
void enregistrerLesContacts(){
    FILE *file = fopen(fichier, "w");
    if (file == NULL) {
        return;
    }

    fprintf(file, "%d\n", contactsLen);

    for (int i = 0; i < contactsLen; i++) {
        fprintf(file, "%s\n", contacts[i].nom);
        fprintf(file, "%s\n", contacts[i].telephone);
        fprintf(file, "%s\n", contacts[i].email);
    }

    fclose(file);
    puts("Les contacts enregistre avec succes.");
}

// --------- Charger Les Contacts ---------
void chargerLesContacts() {
    FILE *file = fopen(fichier, "r");
    if (file == NULL) {
        return;
    }

    fscanf(file, "%d", &contactsLen);
    fgetc(file);

    contacts = (Contact*)malloc(contactsLen * sizeof(Contact));
    if (contacts == NULL) {
        fclose(file);
        return;
    }
    
    
    for (int i = 0; i < contactsLen; i++) {
        char nom[MAX_NOM];
        char telephone[MAX_TELEPHONE];
        char email[MAX_EMAIL];

        if (fgets(nom, sizeof(nom), file) == NULL) break;
        if (fgets(telephone, sizeof(telephone), file) == NULL) break;
        if (fgets(email, sizeof(email), file) == NULL) break;

        nom[strcspn(nom, "\n")] = '\0';
        telephone[strcspn(telephone, "\n")] = '\0';
        email[strcspn(email, "\n")] = '\0';

        strcpy(contacts[i].nom, nom);
        strcpy(contacts[i].telephone, telephone);
        strcpy(contacts[i].email, email);
    }
    
    fclose(file);
    puts("\nLes contacts charges avec succes.");
}