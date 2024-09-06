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
    
    if (strcmp(phrase1, phrase2) == 0)
    {
        puts("Les phrases sont le meme.");
        return 0;
    }
    
    puts("Les phrases sont differents.");

    return 0;
}