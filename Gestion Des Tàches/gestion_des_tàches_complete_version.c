#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <time.h>


// Définir les constants
#define MAX_TITRE 32
#define MAX_DESCRIPTION 100

// Définir la structure de Tache
typedef struct {
    int jour;
    int mois;
    int annee;
    time_t timestamp;
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
Tache taches[100];
int tachesLen = 0;

char nomDeFichier[] = "taches.txt";


// Définir les fonctions
void afficherSousMenuDesOptionsDeAjoute();
void ajouteDesTaches(int n);

void afficherSousMenuDeAffichageDesTaches();
void afficherTousLesTaches(Tache triTaches[], int croissante);
void triEtAfficherLesTachesParTitre(int croissante);
void triEtAfficherLesTachesParDeadline(int croissante);
void afficherLesTachesUrgent();

void afficherSousMenuDeManipulation();
void modifierUnTache();
void markerUnTacheCommeCompleter();
void supprimerUnTache();

void afficherSousMenuDeRecherche();
void afficherUnTacheParId();
void afficherUnTacheParTitre();

void afficherLesOptionDesStatistiques();
void afficherLesTachesParStatut(Tache triTaches[], int statut);

void printLesColonnes();
void printUnTacheLigne(Tache tache);
void printUnTache(Tache tache);
void printNexistePas();

void scanString(char string[], int size);
int rechercheParTitre(char titre[MAX_TITRE]);
long long int obtenirTimestamp(Deadline deadline);
int differenceDesJours(Deadline deadline, time_t currentTime);

void enregistrerLesTaches();
void chargerLesTaches();

// --------- Le Main Fonction ---------
int main(){

    chargerLesTaches();

    int travail = 1;

    // La menu principale
    while (travail)
    {
        puts("#### Gestion des Taches ####");
        puts("\n\t1. Ajouter Des Tache");
        puts("\t2. Afficher Tous Les Taches");
        puts("\t3. Manipulation D'un Tache");
        puts("\t4. Rechercher Un Tache");
        puts("\t5. Statistiques");
        puts("\t6. Quitter Le Program");

        printf("\nEntrer votre choix: ");
        int choix;
        scanf("%d", &choix);
        while (getchar() != '\n');

        switch (choix)
        {
        case 1:
            afficherSousMenuDesOptionsDeAjoute();
            continue;
        case 2:
            afficherSousMenuDeAffichageDesTaches();
            continue;
        case 3:
            afficherSousMenuDeManipulation();
            continue;
        case 4:
            afficherSousMenuDeRecherche();
            continue;
        case 5:
            afficherLesOptionDesStatistiques();
            continue;;
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

    enregistrerLesTaches();
    return 0;
}


// --------- Les Fonction D'Ajoutation ---------
void afficherSousMenuDesOptionsDeAjoute(){
    int choix;

    while (1) {
        
        puts("\n\t1. Ajoute Un Tache");
        puts("\t2. Ajoute Multiple Des Taches");
        puts("\t3. Retour au menu principal");
        
        printf("\nEntrer votre choix: ");
        scanf("%d", &choix);
        while (getchar() != '\n');

        switch (choix) {
            case 1:
                ajouteDesTaches(1);
                break;
            case 2:
                ajouteDesTaches(0);
                break;
            case 3:
                return; // Retourne au menu principal
            default:
                puts("Choix invalid.");
        }

        // Retour au menu principal
        choix = 0;
        while (choix != 1) {
            puts("\n----------------");
            puts("1. Retour");
            printf("Entrez votre choix: ");
            scanf("%d", &choix);
            while (getchar() != '\n');
        }
    }
}
void ajouteDesTaches(int n){
    char titre[MAX_TITRE];
    char description[MAX_DESCRIPTION];
    Deadline deadline;

    if (n == 0)
    {
        printf("Combien des taches tu veux entrer: ");
        scanf("%d", &n);
        while (getchar() != '\n');
    }
    

    if (n == 1)
    {
        puts("Ajouter Un Tache: ");
    }
    else if (n > 1){
        puts("Ajouter Multiple Taches: ");
    }
    else
    {
        return;
    }
    
    
    for (int i = 0; i < n; i++)
    {
        if (n > 1)
        {
            printf("\n\t--------- Entrer Le %d Tache ----------\n", i + 1);
        }
        
        printf("\tEntrer le titre de tache: ");
        scanString(titre, sizeof(titre));

        for (int i = 0; i < tachesLen; i++)
        {
            if (strcmp(titre, taches[i].titre) == 0)
            {
                puts("\nCette titre est deja existe.");
                return;
            }
            
        }
        
        printf("\tEntrer la description de tache: ");
        scanString(description, sizeof(description));

        printf("\tEntrer l'annee de deadline: ");
        scanf("%d", &deadline.annee);

        printf("\tEntrer le mois de deadline: ");
        scanf("%d", &deadline.mois);

        printf("\tEntrer le jour de deadline: ");
        scanf("%d", &deadline.jour);
        while (getchar() != '\n');

        printf("\n");

        taches[tachesLen].id = tachesLen + 1;
        strcpy(taches[tachesLen].titre, titre);
        strcpy(taches[tachesLen].description, description);
        taches[tachesLen].statut = 0;

        deadline.timestamp = obtenirTimestamp(deadline);

        taches[tachesLen].deadline = deadline;

        tachesLen++;
    }
    
    if (n == 1)
    {
        puts("Le Tache ajoutee avec succes.");
    }
    else
    {
        puts("Les Taches sont ajoutee avec succes.");
    }
}

// --------- Les Fonction D'Affichage et de tri ---------
void afficherSousMenuDeAffichageDesTaches() {
    int choix;

    while (1) {
        
        puts("\n\t1. Selon l'ordre de titre (croissante)");
        puts("\t2. Selon l'ordre de titre (decroissante)");
        puts("\t3. Selon l'ordre de deadline (croissante)");
        puts("\t4. Selon l'ordre de deadline (decroissante)");
        puts("\t5. Afficher les taches urgent ( < 3 jours)");
        puts("\t6. Retour au menu principal");
        
        printf("\nEntrer votre choix: ");
        scanf("%d", &choix);
        while (getchar() != '\n');

        switch (choix) {
            case 1:
                triEtAfficherLesTachesParTitre(1); // croissante
                break;
            case 2:
                triEtAfficherLesTachesParTitre(0); // decroissante
                break;
            case 3:
                triEtAfficherLesTachesParDeadline(1); // croissante
                break;
            case 4:
                triEtAfficherLesTachesParDeadline(0); // decroissante
                break;
            case 5:
                afficherLesTachesUrgent();
                break;
            case 6:
                return; // Retourne au menu principal
            default:
                puts("Choix invalid.");
        }

        // Retour au menu principal
        choix = 0;
        while (choix != 1) {
            puts("\n----------------");
            puts("1. Retour");
            printf("Entrez votre choix: ");
            scanf("%d", &choix);
            while (getchar() != '\n');
        }
    }
}
void afficherTousLesTaches(Tache triTaches[], int croissante){
    puts("Les Taches: \n");

    // Afficher les colonnes
    printLesColonnes();
    
    if (tachesLen == 0)
    {
        printNexistePas();
    }

    // Afficher les lignes
    for (int i = 0; i < tachesLen; i++)
    {
        int indice = croissante ? i : tachesLen - 1 - i;
        printUnTacheLigne(triTaches[indice]);
    }
}
void triEtAfficherLesTachesParTitre(int croissante){
    Tache cpy[100];
    memcpy(cpy, taches, tachesLen * sizeof(Tache));

    // Tri á bulles
    for (int i = 0; i < tachesLen; i++)
    {
        for (int j = 0; j < tachesLen - 1; j++)
        {
            if (strcmp(cpy[j].titre, cpy[j + 1].titre) > 0)
            {
                Tache temp = cpy[j];
                cpy[j] = cpy[j + 1];
                cpy[j + 1] = temp;
            }
        } 
    }

    afficherTousLesTaches(cpy, croissante);
}
void triEtAfficherLesTachesParDeadline(int croissante){
    Tache cpy[100];
    memcpy(cpy, taches, tachesLen * sizeof(Tache));

    // Tri á bulles
    for (int i = 0; i < tachesLen; i++)
    {
        for (int j = 0; j < tachesLen - 1; j++)
        {
            if (cpy[j].deadline.timestamp > cpy[j + 1].deadline.timestamp)
            {
                Tache temp = cpy[j];
                cpy[j] = cpy[j + 1];
                cpy[j + 1] = temp;
            }
        } 
    }

    afficherTousLesTaches(cpy, croissante);
}
void afficherLesTachesUrgent(){
    puts("Les Taches: \n");

    // Afficher les colonnes
    printLesColonnes();
    
    const int tachesAvecDeadlineInferieureA = 3;

    int count = 0;

    time_t currentTime = time(NULL);
    for (int i = 0; i < tachesLen; i++) {
        Deadline deadline = taches[i].deadline;
        
        int diff_jours = differenceDesJours(deadline, currentTime);

        if (diff_jours <= tachesAvecDeadlineInferieureA && diff_jours >= 0) {
            count++;
            printUnTacheLigne(taches[i]);
        }
    }

    if (count == 0)
    {
        printNexistePas();
    }
}

// --------- Les Fonction De Manipulation ---------
void afficherSousMenuDeManipulation(){
    int choix;

    while (1) {
        
        puts("\n\t1. Marker Un Tache Comme Completer");
        puts("\t2. Modifier Un Tache");
        puts("\t3. Supprimer Un Tache");
        puts("\t4. Retour au menu principal");
        
        printf("\nEntrer votre choix: ");
        scanf("%d", &choix);
        while (getchar() != '\n');

        switch (choix) {
            case 1:
                markerUnTacheCommeCompleter();
                break;
            case 2:
                modifierUnTache();
                break;
            case 3:
                supprimerUnTache();
                break;
            case 4:
                return; // Retourne au menu principal
            default:
                puts("Choix invalid.");
        }

        // Retour au menu principal
        choix = 0;
        while (choix != 1) {
            puts("\n----------------");
            puts("1. Retour");
            printf("Entrez votre choix: ");
            scanf("%d", &choix);
            while (getchar() != '\n');
        }
    }
}
void modifierUnTache(){
    char titre[MAX_TITRE];

    puts("Modifier Un Taches: \n");

    printf("\tEntrer le titre de tache: ");
    scanString(titre, sizeof(titre));

    int indice = rechercheParTitre(titre);

    if (indice == -1)
    {
        puts("\nCette tache n'existe pas.");
        return;
    }
    
    char nouvelleTitre[MAX_TITRE];
    char nouvelleDescription[MAX_DESCRIPTION];
    Deadline deadline;

    printf("\tEntrer la nouvelle titre de tache: ");
    scanString(nouvelleTitre, sizeof(nouvelleTitre));

    indice = rechercheParTitre(nouvelleTitre);

    if (indice == -1)
    {
        puts("\nCette titre est deja existe.");
        return;
    }
    
    printf("\tEntrer la nouvelle description de tache: ");
    scanString(nouvelleDescription, sizeof(nouvelleDescription));

    
    printf("\tEntrer l'annee de deadline: ");
    scanf("%d", &deadline.annee);

    printf("\tEntrer le mois de deadline: ");
    scanf("%d", &deadline.mois);

    printf("\tEntrer le jour de deadline: ");
    scanf("%d", &deadline.jour);

    strcpy(taches[indice].titre, nouvelleTitre);
    strcpy(taches[indice].description, nouvelleDescription);
    taches[indice].deadline = deadline;
    
    puts("\nLe tache est modifie avec succes.");
}
void markerUnTacheCommeCompleter(){
    char titre[MAX_TITRE];

    puts("Modifier Un Taches: \n");

    printf("\tEntrer le titre de tache: ");
    scanString(titre, sizeof(titre));

    int indice = rechercheParTitre(titre);

    if (indice == -1)
    {
        puts("\nCette tache n'existe pas.");
        return;
    }

    taches[indice].statut = 1;
    
    puts("\nLe tache est Marker avec succes.");
}
void supprimerUnTache(){
    char titre[MAX_TITRE];
    char confirmation[4];

    puts("Supprimer Un Tache: \n");

    printf("\tEntrer le titre de Tache: ");
    scanString(titre, sizeof(titre));

    int indice = rechercheParTitre(titre);

    if (indice == -1)
    {
        puts("\nCette tache n'existe pas.");
        return;
    }
    
    printf("\tVoulez-vous vraiment supprimer cette tache ? (oui/non): ");
    scanString(confirmation, sizeof(confirmation));

    printf("\n");

    if (strcmp(confirmation, "oui") != 0) {
        puts("Suppression annulée.");
        return;
    }

    for (int i = indice; i < tachesLen - 1; i++)
    {
        taches[i] = taches[i + 1];
    }

    tachesLen--;

    puts("Tache supprime avec succes.");
}


// --------- Les Fonction De Recherche ---------
void afficherSousMenuDeRecherche(){
    int choix;

    while (1) {
        
        puts("\n\t1. Rechercher avec ID");
        puts("\t2. Rechercher avec titre");
        puts("\t3. Retour au menu principal");
        
        printf("\nEntrer votre choix: ");
        scanf("%d", &choix);
        while (getchar() != '\n');

        switch (choix) {
            case 1:
                afficherUnTacheParId();
                break;
            case 2:
                afficherUnTacheParTitre();
                break;
            case 3:
                return; // Retourne au menu principal
            default:
                puts("Choix invalid.");
        }

        // Retour au menu principal
        choix = 0;
        while (choix != 1) {
            puts("\n----------------");
            puts("1. Retour");
            printf("Entrez votre choix: ");
            scanf("%d", &choix);
            while (getchar() != '\n');
        }
    }
}
void afficherUnTacheParId(){
    int id;

    puts("Afficher Un Tache:\n");

    printf("\tEntrer le ID de tache: ");
    scanf("%d", &id);

    printf("\n");

    int g = 0;
    int d = tachesLen - 1;

    // Recherche Binaire
    while (g <= d) {
        int mid = (d + g) / 2;

        if (taches[mid].id == id) {
            Tache tache = taches[mid];

            printUnTache(tache);

            return;
        }
        else if (id > taches[mid].id) {
            g = mid + 1;
        } else {
            d = mid - 1;
        }
    }

    puts("N'existe pas une tache avec cet ID.");
}
void afficherUnTacheParTitre(){
    char titre[MAX_TITRE];

    puts("Afficher Un Tache:\n");

    printf("\tEntrer le titre de tache: ");
    scanString(titre, sizeof(titre));

    printf("\n");

    int indice = rechercheParTitre(titre);
    if (indice == -1)
    {
        puts("N'existe pas un tache avec cette titre.");
        return;
    }

    Tache tache = taches[indice];

    printUnTache(tache);
}

// --------- Les Fonction De Statistiques ---------
void afficherLesOptionDesStatistiques(){
    int choix;

    while (1) {
        
        puts("\n\t1. Les taches a realiser");
        puts("\t2. Les taches finalisee");
        puts("\t3. Retour au menu principal");
        
        printf("\nEntrer votre choix: ");
        scanf("%d", &choix);
        while (getchar() != '\n');

        switch (choix) {
            case 1:
                afficherLesTachesParStatut(taches, 0); 
                break;
            case 2:
                afficherLesTachesParStatut(taches, 1); 
                break;
            case 3:
                return; // Retourne au menu principal
            default:
                puts("Choix invalid.");
        }

        // Retour au menu principal
        choix = 0;
        while (choix != 1) {
            puts("\n----------------");
            puts("1. Retour");
            printf("Entrez votre choix: ");
            scanf("%d", &choix);
            while (getchar() != '\n');
        }
    }
}
void afficherLesTachesParStatut(Tache triTaches[], int statut){
    puts("Les Taches: \n");

    // Afficher les colonnes
    printLesColonnes();

    int count = 0;

    for (int i = 0; i < tachesLen; i++)
    {
        if (triTaches[i].statut == statut)
        {
            count++;
            printUnTacheLigne(triTaches[i]);
        }
    }

    if (count == 0)
    {
        printNexistePas();
    }

    printf("\tNombre Total: %d", count);
}


// --------- Des Fonction Auxiliares ---------
void scanString(char string[], int size){
    if (fgets(string, size, stdin) != NULL) {
        string[strcspn(string, "\n")] = '\0';
    }
}

void printLesColonnes(){
    printf("\t+-----+--------------------------------+--------------------------------+------------+------------+\n");
    printf("\t| %-3s | %-30s | %-30s | %-10s | %-10s |\n", "ID", "Titre", "Description", "Statut", "DeadLine");
    printf("\t+-----+--------------------------------+--------------------------------+------------+------------+\n");
}
void printUnTacheLigne(Tache tache){
    printf("\t| %-3d | %-30s | %-30s | %-10s | %02d/%02d/%4d |\n",
        tache.id, tache.titre, tache.description, tache.statut ? "Finalisee" : "A realiser",
        tache.deadline.jour, tache.deadline.mois, tache.deadline.annee 
    );
    printf("\t+-----+--------------------------------+--------------------------------+------------+------------+\n");
}  
void printUnTache(Tache tache){
    printf("\tLe ID: %d\n", tache.id);
    printf("\tLe Titre: %s\n", tache.titre);
    printf("\tLe Description: %s\n", tache.description);
    printf("\tLa Statut: %s\n", tache.statut ? "Finalisee" : "A realiser");

    Deadline deadline = tache.deadline;
    printf("\tLa Deadline: %02d/%02d/%4d\n", deadline.jour, deadline.mois, deadline.annee);
}
void printNexistePas(){
    printf("\t|                             ");
    printf("%-40s", "N'existe pas des taches pour afficher.");
    printf("                            |\n");
    printf("\t+-----+--------------------------------+--------------------------------+------------+------------+\n");
}

int rechercheParTitre(char titre[MAX_TITRE]){
    for (int i = 0; i < tachesLen; i++)
    {
        if (strcmp(titre, taches[i].titre) == 0)
        {
            return i;
        }
    }

    return -1;
}

long long int obtenirTimestamp(Deadline deadline){
    struct tm deadline_tm;
    deadline_tm.tm_year = deadline.annee - 1900;
    deadline_tm.tm_mon = deadline.mois - 1; 
    deadline_tm.tm_mday = deadline.jour;
    deadline_tm.tm_hour = 0;
    deadline_tm.tm_min = 0;
    deadline_tm.tm_sec = 0; 
    deadline_tm.tm_isdst = -1;

    return mktime(&deadline_tm);
}
int differenceDesJours(Deadline deadline, time_t currentTime){
    struct tm deadline_tm = *localtime(&deadline.timestamp);
    struct tm current_tm = *localtime(&currentTime);

    int diff_jours = (deadline_tm.tm_year - current_tm.tm_year) * 365 +
                    (deadline_tm.tm_mon - current_tm.tm_mon) * 30 +
                    (deadline_tm.tm_mday - current_tm.tm_mday);

    return diff_jours;
}

// --------- Entregistrer Les Taches ---------
void enregistrerLesTaches(){
    FILE *fichier = fopen(nomDeFichier, "w");
    if (fichier == NULL) {
        return;
    }


    fprintf(fichier, "%d\n", tachesLen);

    for (int i = 0; i < tachesLen; i++) {
        fprintf(fichier, "%d\n", taches[i].id);
        fprintf(fichier, "%s\n", taches[i].titre);
        fprintf(fichier, "%s\n", taches[i].description);
        fprintf(fichier, "%d\n", taches[i].statut);
        fprintf(fichier, "%d\n", taches[i].deadline.jour);
        fprintf(fichier, "%d\n", taches[i].deadline.mois);
        fprintf(fichier, "%d\n", taches[i].deadline.annee);
        fprintf(fichier, "%ld\n", taches[i].deadline.timestamp);
    }

    fclose(fichier);
    puts("\nLes taches enregistre avec succes.");
}

// --------- Charger Les Taches ---------
void chargerLesTaches() {
    FILE *file = fopen(nomDeFichier, "r");
    if (file == NULL) {
        return;
    }

    fscanf(file, "%d", &tachesLen);
    fgetc(file);
    
    for (int i = 0; i < tachesLen; i++) {
        char titre[MAX_TITRE];
        char description[MAX_DESCRIPTION];
        int id, statut;
        Deadline deadline;

        fscanf(file, "%d", &id);
        fgetc(file);

        if (fgets(titre, sizeof(titre), file) == NULL) break;
        if (fgets(description, sizeof(description), file) == NULL) break;

        titre[strcspn(titre, "\n")] = '\0';
        description[strcspn(description, "\n")] = '\0';
        
        fscanf(file, "%d", &statut);
        fgetc(file);
        fscanf(file, "%d", &deadline.jour);
        fgetc(file);
        fscanf(file, "%d", &deadline.mois);
        fgetc(file);
        fscanf(file, "%d", &deadline.annee);
        fgetc(file);
        fscanf(file, "%ld", &deadline.timestamp);
        fgetc(file);

        taches[i].id = id;
        strcpy(taches[i].titre, titre);
        strcpy(taches[i].description, description);
        taches[i].statut = statut;
        taches[i].deadline = deadline;
    }
    
    fclose(file);
    puts("\nLes taches charges avec succes.\n");
}