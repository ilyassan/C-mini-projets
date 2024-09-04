#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ALPHABETS 28
#define NUMS 10

int main(){

    char lesAlphabetsMiniscule[ALPHABETS];
    char lesAlphabetsMajiscule[ALPHABETS];

    for (int i = 0; i < ALPHABETS; i++)
    {
        lesAlphabetsMiniscule[i] = 'a' + i;
        lesAlphabetsMajiscule[i] = 'a' + i - 32;
    }

    char nums[NUMS];
    for (int i = 0; i < NUMS; i++)
    {
        nums[i] = '0' + i;
    }


    int passwordLen;
    printf("Entrer combien le long de mot de pass: ");
    scanf("%d", &passwordLen);

    int len = 0;

    srand(time(NULL)); 

    while (len < passwordLen)
    {
        int randNum = rand();
        
        int randomChoix = randNum % 3 + 1;

        switch (randomChoix)
        {
        case 1:
            printf("%c", lesAlphabetsMajiscule[randNum % ALPHABETS]);
            break;
        case 2:
            printf("%c", lesAlphabetsMiniscule[randNum % ALPHABETS]);
            break;
        case 3:
            printf("%c", nums[randNum % NUMS]);
            break;
        
        default:
            break;
        }

        len++;
    }

    return 0;
}