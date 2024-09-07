#include <stdio.h>


int main(){

    int t[] = {3, 5, 1, 8, 5};
    int len = sizeof(t) / sizeof(t[0]);

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
    
    for (int i = 0; i < len - 1; i++)
    {
        if (t[i] == t[i + 1])
        {
            puts("Il y a un doublons.");
            return 0;
        }
    }
    
    puts("Les elements sont unique.");
    return 0;
}