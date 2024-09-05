#include <stdio.h>

void inverseTableux(char t[], int len);

int main(){

    char t[] = {'a', 'b', 'c', 'z'};
    int len = sizeof(t) / sizeof(t[0]);

    inverseTableux(t, len);

    
    for (int i = 0; i < len; i++)
    {
        printf("=> %c ", t[i]);
    }

    return 0;
}


void inverseTableux(char t[], int len){
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
}