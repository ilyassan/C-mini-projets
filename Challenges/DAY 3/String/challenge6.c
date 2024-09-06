#include <stdio.h>
#include <string.h>

int main(){

    char phrase[30];
    char target;

    printf("Entrer la phrase: ");
    fgets(phrase, sizeof(phrase), stdin);
    printf("Entrer le characters rechercher: ");
    scanf("%c", &target);

    int len = strlen(phrase);

    int count = 0;

    for (int i = 0; i < len; i++)
    {
        if (phrase[i] == target)
        {
            count++;
        }
        
    }

    printf("Le charachter trouver %d fois dans la phrase.", count);

    return 0;
}