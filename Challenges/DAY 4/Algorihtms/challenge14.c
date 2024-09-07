#include <stdio.h>


int main(){

    char t[] = "acefhxyz";
    int len = sizeof(t) / sizeof(t[0]);

    char target;
    printf("Entrer le charachter rechercher: ");
    scanf("%c", &target);

    int g = 0;
    int d = len - 1;
    while (g <= d)
    {
        int mid = (g + d) / 2;

        if (target > t[mid])
        {
            g = mid + 1;
        }
        else if (target < t[mid])
        {
            d = mid - 1;
        }
        else
        {
            printf("Le charachter est trouver dans l'indice %d.", mid);
            return 0;
        }
        
    }

    printf("Le charachter n'est pas trouver.");
    return 0;
}