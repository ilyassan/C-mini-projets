#include <stdio.h>
#include <string.h>

int main(){

    char phrase1[30];
    char phrase2[30];

    printf("Entrer la premier phrase: ");
    fgets(phrase1, sizeof(phrase1), stdin);
    phrase1[strcspn(phrase1, "\n")] = '\0';

    printf("Entrer la deuxieme phrase: ");
    fgets(phrase2, sizeof(phrase2), stdin);
    phrase2[strcspn(phrase2, "\n")] = '\0';

    int len1 = strlen(phrase1);
    int len2 = strlen(phrase2);

    char concat[len1 + len2];

    for (int i = 0; i < len1; i++)
    {
        concat[i] = phrase1[i];
    }
    for (int i = 0; i < len2; i++)
    {
        concat[len1 + i] = phrase2[i];
    }
    
    
    printf("Le concat chaine est \'%s\'", concat);

    return 0;
}