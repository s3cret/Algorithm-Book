#include<stdio.h>

/*  b
*   a(%d) = *b(%d)
*/

int main()
{
    int a = 10;
    int *b = &a;
    int *c = b;
    // int *c = &b;
    int *d = c;
    // int *d = &c;

    printf(" a - value  : %d\n", a);
    printf(" a - address: %p\n\n", &a);

    printf("*b - value  : %d\n", b);
    printf(" b - address: %p\n", &b);
    printf(" b - pointer: %p\n\n", b);

    printf("*c - value  : %d\n", *c);
    printf(" c - address: %p\n", &c);
    printf(" c - pointer: %p\n\n", c);

    printf("*d - value  : %d\n", *d);
    printf(" d - address: %p\n", &d);
    printf(" d - pointer: %p\n\n", d);
    
    return 0;
}