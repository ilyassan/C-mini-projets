#include <stdio.h>

void printTableux(int t[], int len);

int main(){

    int t[] = { 2, 4, 6, 1};
    int len = sizeof(t) / sizeof(t[0]);

    int copyT[len];

    for (int i = 0; i < len; i++)
    {
        copyT[i] = t[i];
    }

    printTableux(t, len);
    printf("\n");
    printTableux(copyT, len);
}


void printTableux(int t[], int len){
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