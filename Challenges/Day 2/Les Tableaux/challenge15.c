#include <stdio.h>


int main(){

    int len1;
    printf("Entrer le nombre des elements (Tableux 1): ");
    scanf("%d", &len1);

    int t1[len1];

    for (int i = 0; i < len1; i++)
    {
        printf("\nEntrer le %d numero: ", i + 1);
        scanf("%d", &t1[i]);
    }
    
    int len2;
    printf("Entrer le nombre des elements (Tableux 2): ");
    scanf("%d", &len2);

    int t2[len2];

    for (int i = 0; i < len2; i++)
    {
        printf("\nEntrer le %d numero: ", i + 1);
        scanf("%d", &t2[i]);
    }


    int t[len1 + len2];

    for (int i = 0; i < len1; i++)
    {
        t[i] = t1[i];
    }
    for (int i = 0; i < len2; i++)
    {
        t[i + len1] = t2[i];
    }
    
    

    for (int i = 0; i < len1 + len2; i++)
    {
        printf("=> %d ", t[i]);
    }
}