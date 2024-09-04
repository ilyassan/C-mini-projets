#include <stdio.h>

int main(){

    int n;
    printf("Tous les premiers nombres entre 1 et: ");
    scanf("%d", &n);

    for (int i = 1; i < n; i++)
    {
        int premier = 1;
        
        if (i <= 1) {
            premier = 0;
        }

        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                premier = 0;
            }
        }
        
        if (premier)
        {
            printf("=> %d ", i);
        }  
    }
}