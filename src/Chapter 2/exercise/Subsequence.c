#include<stdio.h>

int main()
{
    int n, m, kase = 0;
    while (scanf("%d%d", &n, &m) == 2 && !(n == m && n == 0))
    {
        double result = 0;
        for (int i = n; i <= m; i++)
        {
            result += 1.0 / i / i;
        }
        printf("Case %d: %.5lf\n", kase, result);
        
    }
    
    

    return 0;
}