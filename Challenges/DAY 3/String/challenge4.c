#include <stdio.h>
#include <string.h>

int main(){

    char phrase1[30];
    char phrase2[30];

    printf("Entrer la premier phrase: ");
    scanf("%s", phrase1);
    printf("Entrer la deuxieme phrase: ");
    scanf("%s", phrase2);
    
    if (strcmp(phrase1, phrase2) == 0)
    {
        puts("Les phrases sont le meme.");
        return 0;
    }
    
    puts("Les phrases sont differents.");

    return 0;
}