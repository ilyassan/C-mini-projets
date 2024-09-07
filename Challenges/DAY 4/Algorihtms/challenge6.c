#include <stdio.h>


void printTableux(int t[], int len);
void triParComptage(int t[], int len, int output[]);

int main(){

    int t[] = {3, 5, 3, 1, 8, 5};
    int len = sizeof(t) / sizeof(t[0]);
    int output[len];

    puts("Avant");
    printTableux(t, len);
    
    // Tri Rapide
    triParComptage(t, len, output);

    puts("\nApres");
    printTableux(output, len);

    return 0;
}

void triParComptage(int t[], int len, int output[]){
    if (len <= 1) return;
    
    int max = t[0];
    for (int i = 1; i < len; i++)
    {
        if (t[i] > max)
        {
            max = t[i];
        }
    }

    int countT[max + 1];
    int countTLen = max + 1;

    for (int i = 0; i < countTLen; i++)
    {
        countT[i] = 0;
    }

    for (int i = 0; i < len; i++)
    {
        countT[ t[i] ]++;
    }

    for (int i = 1; i < countTLen; i++)
    {
        countT[i] += countT[i - 1];
    }
    
    for (int i = len - 1; i >= 0; i--)
    {
        output[--countT[ t[i] ]] = t[i];
    }
    
}


void printTableux(int t[], int len){
    for (int i = 0; i < len; i++)
    {
        printf("=> %d ", t[i]);
    }
}