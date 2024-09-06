#include <stdio.h>
#include <string.h>

int main(){

    char phrase[30];

    printf("Entrer la phrase: ");
    fgets(phrase, sizeof(phrase), stdin);
    phrase[strcspn(phrase, "\n")] = '\0';
    
    int len = strlen(phrase);


    int spaces = 0;

    for (int i = 0; i < len; i++)
    {
        if (phrase[i] == ' ')
        {
            spaces++;
        }
    }


    int i = 0;
    int j = 0;
    char cpy[len - spaces];
    do
    {
        while (phrase[j] == ' ')
        {
            j++;
        }
        
    } while (cpy[i++] = phrase[j++]);
    
    
    printf("La phrase avec supprime tous les espaces: \'%s\'", cpy);

    return 0;
}