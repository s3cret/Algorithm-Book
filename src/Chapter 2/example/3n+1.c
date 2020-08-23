#include<stdio.h>
#include<time.h>

int main()
{
    int n;
    int count = 0;
    scanf("%d", &n);

    while (n > 1)
    {
        count += 1;
        if(n % 2 != 0) {
            n = 3 * n + 1;
        }else {
            n = n / 2;
        }
        
    }
    
    printf("%d\n", count);

    printf("Time used = %.2f\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}