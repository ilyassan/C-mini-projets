#include <stdio.h>


void printTableux(int t[], int len);
void triRapide(int t[], int debut, int fin);
int obtenuPivot(int t[], int debut, int fin);

int main(){

    int t[] = {3, 5, 3, 1, 8, 5};
    int len = sizeof(t) / sizeof(t[0]);

    puts("Avant");
    printTableux(t, len);

    // Tri Rapide
    triRapide(t, 0, len - 1);

    puts("\nApres");
    printTableux(t, len);

    return 0;
}

void triRapide(int t[], int debut, int fin){
    if (debut >= fin) return;
    
    int pivot = obtenuPivot(t, debut, fin);

    triRapide(t, debut, pivot - 1);
    triRapide(t, pivot + 1, fin);
}

int obtenuPivot(int t[], int debut, int fin){
    int pivot = t[fin];

    int i = debut - 1;
    for (int j = debut; j <= fin - 1; j++)
    {
        if (t[j] < pivot)
        {
            i++;
            int temp = t[i];
            t[i] = t[j];
            t[j] = temp;
        }
    }
    i++;
    int temp = t[i];
    t[i] = t[fin];
    t[fin] = temp;

    return i;
}


void printTableux(int t[], int len){
    for (int i = 0; i < len; i++)
    {
        printf("=> %d ", t[i]);
    }
}




// void triRapide(int t[], int debut, int fin){
//     if (debut >= fin) return;
    
//     int pivot = obtenuPivot(t, debut, fin);
//     triRapide(t, debut, pivot - 1);
//     triRapide(t, pivot + 1, fin);
// }

// int obtenuPivot(int t[], int debut, int fin){
//     int pivot = t[fin];

//     int i = debut - 1;
//     for (int j = debut; j < fin - 1; j++)
//     {
//         if (t[j] < t[pivot])
//         {
//             i++;
//             int temp = t[i];
//             t[i] = t[j];
//             t[j] = temp;
//         }   
//     }
//     i++;
//     int temp = t[i];
//     t[i] = t[fin];
//     t[fin] = temp;
    
//     return i;
// }