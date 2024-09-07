#include <stdio.h>

int rechercheBinaire(int t[], int len, int target);

int main(){

    int t[] = {1, 3, 5, 6, 8, 10};
    int len = sizeof(t) / sizeof(t[0]);

    int target;
    printf("Entrer le nombre rechercher: ");
    scanf("%d", &target);

    int indice = rechercheBinaire(t, len, target);

    if (indice == -1)
    {
        puts("L'element n\'est pas trouver.");
        return 0;
    }

    printf("L'element trouver, dans l'indice  %d", indice);

    return 0;
}


int rechercheBinaire(int t[], int len, int target){
    
    int g = 0;
    int d = len - 1;

    while (g <= d)
    {
        int mid = (g + d) / 2;

        if (t[mid] == target)
        {
            return mid;
        }
        else if (target > t[mid])
        {
            g = mid + 1;
        }
        else{
            d = mid - 1;
        }
    }
    
    return -1;
}