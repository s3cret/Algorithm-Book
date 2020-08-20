/* only use %lf to scanf a double
   cannot use the %f to scanf a double */

#include <stdio.h>

int main()
{
    double a;

    scanf("%lf", &a);
    printf("%.2f\n", a);

    return 0;
}