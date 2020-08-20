#include<stdio.h>
#include<math.h>

int main()
{
    int n;
    scanf("%d", &n);

    if (n >= 0 && n < 360)
    {
        double s = sin(n);
        double c = cos(n);
        printf("%.3f\n%.3f\n", s, c);
    }
    

    return 0;
}