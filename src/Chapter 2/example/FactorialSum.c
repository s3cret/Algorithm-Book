#include<stdio.h>
#include<time.h>

int main()
{
    // const int MOD = 1000000;
    const int MOD = 276447232;
    int n, S = 0;
    scanf("%d", &n);
    int factorial = 1;
    
    for (int i = 1; i <= n; i++)
    {
        factorial = (factorial * i) % MOD;
        S = (S + factorial) % MOD;
    }
    printf("%d\n", S);
    
    printf("Time used = %.8f\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}