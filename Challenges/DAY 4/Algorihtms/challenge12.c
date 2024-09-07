#include <stdio.h>
#include <string.h>

int main(){

    char phrase[30];
    char sousPhrase[30];

    printf("Entrer la phrase principale: ");
    fgets(phrase, sizeof(phrase), stdin);
    phrase[strcspn(phrase, "\n")] = '\0';

    printf("Entrer la sous phrase: ");
    fgets(sousPhrase, sizeof(sousPhrase), stdin);
    sousPhrase[strcspn(sousPhrase, "\n")] = '\0';
    
    int len = strlen(phrase);
    int lenSousPhrase = strlen(sousPhrase);

    for (int i = 0; i < len; i++)
    {
        int j;

        for (j = 0; j < lenSousPhrase; j++)
        {
            if (phrase[i + j] != sousPhrase[j])
            {
                break;
            }
        }
        if (j == lenSousPhrase)
        {
            puts("Vrai, La sous-phrase existe dans la principale phrase.");
            return 0;
        }
    }

    puts("Faux, La sous-phrase n'existe pas dans la principale phrase.");

    return 0;
}