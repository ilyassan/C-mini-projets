#include <stdio.h>

int main(){

    int t[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = 10;

    int target;
    printf("Entrer la valeur rechercher entre (1-10): ");
    scanf("%d", &target);

    int etaps = 0;

    int gauche = 0;
    int droit = len - 1;
    

    while (gauche <= droit)
    {
        int mid = (droit + gauche)/ 2;
        etaps++;

        if (target > t[mid] )
        {
            gauche = mid + 1;
        }
        else if (target < t[mid])
        {
            droit = mid - 1;
        }
        else{
            printf("La valeur trouver // les etaps: %d\n", etaps);
            return 0;
        }
    }

    printf("La valeur n'est pas trouver");

    return 0;
}