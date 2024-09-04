#include <stdio.h>

void printTableux(int t[], int len);

int main(){

    int t[] = { 2, 4, 6, 1};
    int len = sizeof(t) / sizeof(t[0]);

    puts("Avant:");
    printTableux(t, len);

    int left = 0;
    int right = len - 1;

    while (left < right)
    {
        int temp = t[left];
        t[left] = t[right];
        t[right] = temp;

        left++;
        right--;
    }
    
    puts("\nApres:");
    printTableux(t, len);
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
}