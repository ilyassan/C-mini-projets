#include <stdio.h>


void printTableux(int t[], int len);

int main(){

    int t[] = {3, 5, 3, 1, 8, 5};
    int len = sizeof(t) / sizeof(t[0]);

    puts("Avant");
    printTableux(t, len);

    // Tri par Sélection
    for (int i = 0; i < len; i++)
    {
        int min = i + 1;
        for (int j = i + 1; j < len; j++)
        {
            if (t[j] < t[min])
            {
                min = j;
            }
        }
        
        if (min != i)
        {
            int temp = t[i];
            t[i] = t[min];
            t[min] = temp;
        }
        
    }
    
    puts("\nApres");
    printTableux(t, len);

    return 0;
}


void printTableux(int t[], int len){
    for (int i = 0; i < len; i++)
    {
        printf("=> %d ", t[i]);
    }
}