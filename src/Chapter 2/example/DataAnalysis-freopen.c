// #define LOCAL

#include<stdio.h>

#define INF 1000000000


int main()
{
#ifdef LOCAL
    freopen("DataAnalysis.in", "r", stdin);
    freopen("DataAnalysis.out", "w", stdout);
#endif

    int n = 0, x, min = INF, max = -INF, s = 0;
    while (scanf("%d", &x) == 1)
    {
        s += x;
        if(x < min) min = x;
        if(x > max) max = x;
        n ++;
    }
    printf("min=%d max=%d averange=%.3f\n", min, max, (float)s / n);

    return 0;
}