#include<stdio.h>
#include<math.h>
#include<time.h>

int main()
{
    for (int i = 100; i < 1000; i++)
    {
        // abc stands for the 3-digital number
        int a = i / 100;
        int b = (i / 10) % 10;
        int c = i % 10;

        double res = pow(a, 3) + pow(b, 3) + pow(c, 3);
        if(res == i) printf("%d\n", (int)res);

    }
    
    printf("Time used = %.8f\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}