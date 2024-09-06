#include <stdio.h>
#include <string.h>

int main(){

    char phrase[30];

    printf("Entrer la phrase pour inverser: ");
    scanf("%s", phrase);
    int len = strlen(phrase);

    
    int gauche = 0;
    int droit = len - 1;

    while (gauche < droit)
    {
        int temp = phrase[gauche];
        phrase[gauche] = phrase[droit];
        phrase[droit] = temp;

        gauche++;
        droit--;
    }
    
    printf("La phrase inverser: %s", phrase);

    return 0;
}