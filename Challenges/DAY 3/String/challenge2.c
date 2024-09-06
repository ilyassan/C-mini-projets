#include <stdio.h>
#include <string.h>

int main(){

    char phrase[30];

    printf("Entrer la phrase: ");
    fgets(phrase, sizeof(phrase), stdin);
    phrase[strcspn(phrase, "\n")] = '\0';

    int charachters = 0;

    for (int i = 0; i < sizeof(phrase) && phrase[i] != '\0'; i++)
    {
        charachters++;
    }
    
    

    printf("La longeur de phrase est %d\n", charachters);

    return 0;
}