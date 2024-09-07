#include <stdio.h>
#include <time.h>


void printTableux(int t[], int len);
void triFusion(int t[], int len);
void fusion(int tableuxGauche[], int tableuxDroit[], int t[], int len);

int main(){

    int t[] = {3, 5, 3, 1, 8, 5};
    int len = sizeof(t) / sizeof(t[0]);

    puts("Avant");
    printTableux(t, len);
    
    // Tri Fusion
    triFusion(t, len);

    puts("\nApres");
    printTableux(t, len);

    return 0;
}

void triFusion(int t[], int len){
    
    if (len <= 1) return; // cas de base
    
    int middle = len / 2;

    int tableuxGauche[middle];
    int tableuxDroit[len - middle];

    for (int i = 0; i < middle; i++)
    {
        tableuxGauche[i] = t[i];
    }
    for (int i = 0; i < len - middle; i++)
    {
        tableuxDroit[i] = t[i + middle];
    }
    
    triFusion(tableuxGauche, middle);
    triFusion(tableuxDroit, len - middle);
    fusion(tableuxGauche, tableuxDroit, t, len);
}

void fusion(int tableuxGauche[], int tableuxDroit[], int t[], int len){
    int lenGauche = len / 2;
    int lenDroit = len - lenGauche;

    int i = 0, g = 0, d = 0; // les indices

    while (g < lenGauche && d < lenDroit)
    {
        if (tableuxGauche[g] < tableuxDroit[d])
        {
            t[i] = tableuxGauche[g];
            i++;
            g++;
        }
        else{
            t[i] = tableuxDroit[d];
            i++;
            d++;
        }
    }

    while (g < lenGauche)
    {
        t[i] = tableuxGauche[g];
        i++;
        g++;
    }
    while (d < lenDroit)
    {
        t[i] = tableuxDroit[d];
        i++;
        d++;
    }
    
}



void printTableux(int t[], int len){
    for (int i = 0; i < len; i++)
    {
        printf("=> %d ", t[i]);
    }
}