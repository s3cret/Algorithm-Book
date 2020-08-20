#include<stdio.h>


void swap(int *, int *);

int main()
{
    int x = 985;
    int y = 211;
    printf("x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("x = %d, y = %d\n", x, y);

    return 0;
}

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
    printf("a = %d, b = %d\n", *a, *b);
}
