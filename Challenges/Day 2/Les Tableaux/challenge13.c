#include <stdio.h>

int main(){

    int len;
    printf("Entrer le nombre des elements: ");
    scanf("%d", &len);

    int t[len];

    for (int i = 0; i < len; i++)
    {
        printf("\nEntrer le %d numero: ", i + 1);
        scanf("%d", &t[i]);
    }

    for (int i = 0; i < len; i++)
    {
        if (t[i] % 2 == 1)
        {
            printf("=> %d ", t[i]);
        }
    }

    return 0;
}