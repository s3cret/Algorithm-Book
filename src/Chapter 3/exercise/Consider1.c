#include <stdio.h>
#define INF 1000000

int main()
{
    int n, count = 0, sum = 0;
    int max = -INF, min = INF;
    while (scanf("%d", &n) == 1)
    {
        count += 1;
        sum += n;

        if (max < n)
        {
            max = n;
        }

        if (min > n)
        {
            min = n;
        }
    }
    // printf("%d\n", count);
    printf("Min=%d, Max=%d, Average=%.3f\n", min, max, (float)sum / count);

    return 0;
}