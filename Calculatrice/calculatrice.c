#include <stdio.h>
#include <stdlib.h>

void listeOperations();
int treatmentLeChoix(int choix, double input, double *pResultat);

int main(){
    
    double resultat = 0;

    int i = 1;
    while (1)
    {
        
        printf("Entrer le %d numero: ", i);

        double input;
        while (scanf("%lf", &input) == -1)
        {
            printf("Entrer le %d numero: ", i);
        }
        
        
        listeOperations();
        
        int choix;
        scanf("%d", &choix);
        while (getchar() != '\n');

        if (treatmentLeChoix(choix, input, &resultat) == -1) break;

        i++;
    }

    printf("Le resultat obtenu est %.2lf");
    
    return 0;
}

void listeOperations(){

    char lesChoix[] = {'+', '-', '*', '/'};

    for (size_t i = 0; i < sizeof(lesChoix) ; i++)
    {
        printf("\t%zu -> \'%c\'\n", i + 1, lesChoix[i]);
    }
    printf("\t%d -> Obtenir la resultat\n", sizeof(lesChoix) + 1);

    printf("Choisir l'operation (1 - 5): ");
}

int treatmentLeChoix(int choix, double input, double *pResultat){
    
    switch (choix)
    {
    case 1:
        *pResultat += input;
        break;
    case 2:
        *pResultat -= input;
        break;
    case 3:
        *pResultat *= input;
        break;
    case 4:
        if (input == 0){
            puts("Impossible de division par zero!");
            exit(1);
        }
        *pResultat /= input;
        break;
    case 5:
        return -1;
    default:
        break;
    }

    return 1;
}



// validation des inputs
// choix range validation