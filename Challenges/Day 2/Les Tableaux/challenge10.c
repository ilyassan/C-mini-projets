#include <stdio.h>

int main(){

    int len;
    printf("Entrer le nombre des elements: ");
    scanf("%d", &len);

    int t[len];

    for (int i = 0; i < len; i++)
    {
        printf("\nEntrer le %d numero: ", i + 1);
        scanf("%d", &t[i]);
    }

    int target;
    printf("\nEntrer l'element rechercher: ");
    scanf("%d", &target);

    for (int i = 0; i < len; i++)
    {
        if (t[i] == target)
        {
            puts("\n L'element Trouve.");
            return 0;
        }
    }

    puts("\nL'element n'est pas trouve.");

}