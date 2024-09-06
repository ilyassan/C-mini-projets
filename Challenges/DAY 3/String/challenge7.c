#include <stdio.h>
#include <string.h>

int main(){

    char phrase[30];

    printf("Entrer la phrase en Miniscule: ");
    scanf("%s", phrase);
    int len = strlen(phrase);

    
    for (int i = 0; i < len; i++)
    {
        if (phrase[i] >= 97 && phrase[i] <= 122)
        {
            phrase[i] -= 32;
        }
        
    }

    printf("La phrase en Majiscule: \'%s\'", phrase);

    return 0;
}