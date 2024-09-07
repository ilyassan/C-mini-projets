#include <stdio.h>

int rechercheLinear(int t[], int len, int target);

int main(){

    int t[] = {3, 5, 9, 1, 6};
    int len = sizeof(t) / sizeof(t[0]);

    int target;
    printf("Entrer le nombre rechercher: ");
    scanf("%d", &target);

    int indice = rechercheLinear(t, len, target);

    if (indice == -1)
    {
        puts("L'element n\'est pas trouver.");
        return 0;
    }

    puts("L'element trouver.");

    return 0;
}


int rechercheLinear(int t[], int len, int target){
    for (int i = 0; i < len; i++)
    {
        if (t[i] == target)
        {
            return i;
        }
    }
    
    return -1;
}