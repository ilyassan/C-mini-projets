#include <stdio.h>
#include <string.h>

int main(){

    char text[100] = "Lorem sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. molit anim id est laborum.";
    char mot[15];

    printf("Entrer le mot rechercher: ");
    fgets(mot, sizeof(mot), stdin);
    mot[strcspn(mot, "\n")] = '\0';
    
    int len = strlen(text);
    int motLen = strlen(mot);

    for (int i = 0; i < len; i++)
    {
        int j;

        for (j = 0; j < motLen; j++)
        {
            if (text[i + j] != mot[j])
            {
                break;
            }
        }
        if (j == motLen)
        {
            printf("Vrai, Le mot existe dans le text dans la position %d.", i);
            return 0;
        }
    }

    puts("Faux, Le mot n'existe pas dans le text.");

    return 0;
}