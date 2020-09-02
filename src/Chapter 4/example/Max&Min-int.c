#include <stdio.h>
#include <math.h>

// when conver from float to int,
// if it is too big a float, then int will only be the max value
// if it is too small a float, then int will only be the min value

int main()
{
    int max = pow(2, 38);
    printf("max=%d\n\n", max * 1 - 1);

    int min = -pow(2, 38);
    float fmin = -pow(2, 31);
    printf("min=%d\n", min);
    printf("fmin=%f\n", fmin);

    int* p = 0;
    // *p = 1;
    printf("%p\n", &p);
    // printf("%d\n", *p);

    return 0;
}