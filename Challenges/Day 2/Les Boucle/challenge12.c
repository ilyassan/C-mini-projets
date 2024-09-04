#include <stdio.h>

void printerTableux(int t[], int len);


int main(){

    int len;
    printf("Entrer le nombre des elements pour tri: ");
    scanf("%d", &len);

    int t[len];

    for (int i = 0; i < len; i++)
    {
        printf("\nEntrer le %d numero: ", i + 1);
        scanf("%d", &t[i]);
    }

    puts("Avant:");
    printerTableux(t, len);

    // Bubble sort
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - 1; j++)
        {
            if (t[j] > t[j + 1])
            {
                int temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
            
        }
    }

    puts("\nApres:");
    printerTableux(t, len);
}



void printerTableux(int t[], int len){
    for (int i = 0; i < len; i++)
    {
        if (i + 1 == len)
        {
            printf("%d", t[i]);
            break;
        }
        printf("%d => ", t[i]);
    }
}