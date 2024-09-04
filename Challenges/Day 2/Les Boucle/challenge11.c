#include <stdio.h>

int main(){

    int t[] = {2, 5, 4, 6, 0};
    int len = sizeof(t) / sizeof(t[0]);

    float somme = 0;
    int zeros = 0;

    for (int i = 0; i < len; i++)
    {
        if (t[i] != 0)
        {
            somme += t[i];
            continue;
        }
        zeros++;
    }

    float moyenne = somme / (len - zeros);

    printf("Le moyenne est: %.2f", moyenne);
    
    return 0;
}