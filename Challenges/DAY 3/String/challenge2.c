#include <stdio.h>

int main(){

    char phrase[30];

    printf("Entrer la phrase: ");
    scanf("%s", phrase);

    int charachters = 0;

    for (int i = 0; i < sizeof(phrase) && phrase[i] != '\0'; i++)
    {
        charachters++;
    }
    
    

    printf("La longeur de phrase est %d\n", charachters);

    return 0;
}