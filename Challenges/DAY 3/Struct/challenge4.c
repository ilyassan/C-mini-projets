#include <stdio.h>

typedef struct
{
    int x;
    int y;
} Point;


int main(){

    Point *point;

    (*point).x = 10;
    (*point).y = 8;

    // OU

    point->x = 10;
    point->y = 8;
    
    printf("x: %d / y: %d", point->x, point->y);

    return 0;
}