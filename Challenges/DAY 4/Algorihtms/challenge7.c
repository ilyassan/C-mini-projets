#include <stdio.h>


void printTableux(int t[], int len);
void triRapide(int t[], int debut, int fin);
int obtenuPivot(int t[], int debut, int fin);

int rechercheSousTableux(int t[], int sousT[], int len, int sousLen); 

int main(){

    int t[] = {3, 5, 3, 1, 8, 5};
    int len = sizeof(t) / sizeof(t[0]);

    puts("\nAvant:");
    printTableux(t, len);

    // Tri Rapide
    triRapide(t, 0, len - 1);

    puts("\nApres:");
    printTableux(t, len);

    int sousT[] = {3, 3, 5};
    int sousLen = sizeof(sousT) / sizeof(sousT[0]);

    puts("\nLe sous tableux:");

    int indice = rechercheSousTableux(t, sousT, len, sousLen);
    if (indice == -1)
    {
        printTableux(sousT, sousLen);
        puts("\nLe sous tableux n'est pas trouver");
        return 0;
    }    

    for (int i = 0; i < indice; i++)
    {
        printf("     ");
    }

    printTableux(sousT, sousLen);
    printf("\nLe sous tableux est trouver, il debut dans l'indice %d", indice);

    return 0;
}

void triRapide(int t[], int debut, int fin){
    if (debut >= fin) return;
    
    int pivot = obtenuPivot(t, debut, fin);

    triRapide(t, debut, pivot - 1);
    triRapide(t, pivot + 1, fin);
}

int obtenuPivot(int t[], int debut, int fin){
    int pivot = t[fin];

    int i = debut - 1;
    for (int j = debut; j <= fin - 1; j++)
    {
        if (t[j] < pivot)
        {
            i++;
            int temp = t[i];
            t[i] = t[j];
            t[j] = temp;
        }
    }
    i++;
    int temp = t[i];
    t[i] = t[fin];
    t[fin] = temp;

    return i;
}

int rechercheSousTableux(int t[], int sousT[], int len, int sousLen){
    
    if (sousLen > len) return -1;

    int g = 0;
    int d = len - 1;
    int target = sousT[0];

    int indice = -1;

    while (g <= d)
    {
        int mid = (g + d) / 2;

        if (t[mid] == target)
        {
            indice = mid;
            break;
        }
        else if (target > t[mid])
        {
            g = mid + 1;
        }
        else{
            d = mid - 1;
        }
    }
    
    while (t[indice - 1] == t[indice] && indice != 0)
    {
        indice--;
    }
    
    for (int i = indice; i < len - sousLen + 1; i++)
    {
        int trouver = 1;
        for (int j = 0; j < sousLen; j++)
        {
            if (t[j + i] != sousT[j])
            {
                trouver = 0;
                break;
            }
        }
        
        if (trouver)
        {
            return i;
        }
    }
    
    return -1;
}

void printTableux(int t[], int len){
    for (int i = 0; i < len; i++)
    {
        printf("=> %d ", t[i]);
    }
}