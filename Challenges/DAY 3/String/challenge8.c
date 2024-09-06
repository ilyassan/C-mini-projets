#include <stdio.h>
#include <string.h>

int main(){

    char phrase[30];

    printf("Entrer la phrase en Majiscule: ");
    scanf("%s", phrase);
    int len = strlen(phrase);

    
    for (int i = 0; i < len; i++)
    {
        if (phrase[i] >= 65 && phrase[i] <= 90)
        {
            phrase[i] += 32;
        }
        
    }

    printf("La phrase en Miniscule: \'%s\'", phrase);

    return 0;
}