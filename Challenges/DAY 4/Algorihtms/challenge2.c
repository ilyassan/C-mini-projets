#include <stdio.h>


void printTableux(int t[], int len);

int main(){

    int t[] = {3, 5, 3, 1, 8, 5};
    int len = sizeof(t) / sizeof(t[0]);

    puts("Avant");
    printTableux(t, len);

    // Tri par Insertion
    for (int i = 0; i < len; i++)
    {
        int j = i;
        while (j > 0 && t[j - 1] > t[j])
        {
            int temp = t[j];
            t[j] = t[j - 1];
            t[j - 1] = temp;
            
            j--;
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