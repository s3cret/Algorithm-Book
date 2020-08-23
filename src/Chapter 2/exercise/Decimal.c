#include<stdio.h>

int main()
{
    int kase = 0;
    int a, b, c;
    while(scanf("%d%d%d", &a, &b, &c) == 3 && !(a == b && a == c && a == 0)) {

        double output = (double)a / b;
        printf("Case %d: %.*f\n", ++kase, c, output);

    }

    return 0;
}