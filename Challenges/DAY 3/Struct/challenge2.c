#include <stdio.h>

typedef struct
{
    char nom[30];
    char prenom[30];
    int notes[10];
} Etudient;


int main(){

    Etudient etudient;

    printf("Entrer le nom: ");
    scanf("%s", etudient.nom);

    printf("Entrer le prenom: ");
    scanf("%s", etudient.prenom);

    for (int i = 0; i < sizeof(etudient.notes) / sizeof(etudient.notes[0]); i++)
    {
        printf("Entrer la %d note: ", i + 1);
        scanf("%d", &etudient.notes[i]);
    }
    
    

    printf("Le nom est %s\n", etudient.nom);
    printf("Le prenom est %s\n", etudient.prenom);
    
    printf("Les notes ");
    for (int i = 0; i < sizeof(etudient.notes) / sizeof(etudient.notes[0]); i++)
    {
        printf("=> %d ", etudient.notes[i]);
    }
    

    return 0;
}