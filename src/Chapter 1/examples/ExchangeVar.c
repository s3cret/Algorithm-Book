/*
    It's not allowed to change the address of variables,
    but can change the content of the address;

    int *a;

    type(a): pointer;
    type(*a): int;

*/

#include<stdio.h>

void swap(int *, int *);

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    swap(&a, &b);
    printf("%d %d\n", a, b);

    return 0;
}

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}