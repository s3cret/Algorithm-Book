#include <stdio.h>

int f(int a)
{
    return a == 0 ? 1 : f(a - 1) * a;
}

int main()
{
    if (1)
        printf("%d\n", f(3));

    return 0;
}