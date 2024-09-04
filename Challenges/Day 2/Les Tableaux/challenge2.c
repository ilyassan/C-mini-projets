#include <stdio.h>


int main(){
    int t[5];
    int len = sizeof(t) / sizeof(t[0]);

    for (int i = 0; i < len; i++)
    {
        printf("\nEntrer le %d numero: ", i + 1);
        scanf("%d", &t[i]);
    }
    
    for (int i = 0; i < len; i++)
    {
        if (i + 1 == len)
        {
            printf("%d", t[i]);
            break;
        }
        printf("%d => ", t[i]);
    }
    
    return 0;
}