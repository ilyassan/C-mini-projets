#include <stdio.h>


int main(){
    int t[] = {1, 2, 3, 4, 6};
    int len = sizeof(t) / sizeof(t[0]);

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