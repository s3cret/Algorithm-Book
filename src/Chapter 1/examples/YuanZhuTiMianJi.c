#include<stdio.h>
#include<math.h>

int main()
{
    const double pi = acos(-1.0);
    double r, h;
    scanf("%lf%lf", &r, &h);
    double sTop, sSide, s;
    sTop = pi * r * r;
    sSide = 2.0 * pi * r * h;
    s = sTop * 2.0 + sSide;
    printf("This is your answer %.3lf\n", s);
    return 0;
}