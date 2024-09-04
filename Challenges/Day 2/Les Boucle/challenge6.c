#include <stdio.h>

int main(){

    int n;
    printf("Entrer un nombre pour donner leur facteurs: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            printf("=> %d ", i);
        }
        
    }
}