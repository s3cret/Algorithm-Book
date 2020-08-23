#include<stdio.h>
#include<time.h>
#include<math.h>

int main()
{
    for (int a = 1; a < 9; a++)
    {
        for (int b = 0; b < 9; b++)
        {
            int n = a * 1100 + b * 11;
            // int m = floor(sqrt(n));
            int m = floor(sqrt(n) + 0.5);
            if(m * m == n) {
                printf("%d\n", n);
            }
        }
        
    }
    

    printf("Time used = %.8f\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}