#include<stdio.h>

int main()
{
    int a, b, c, kase = 0;

    while(scanf("%d%d%d", &a, &b, &c) == 3) {
        
        int output = 0;

        for (int i = 10; i <= 100; i++) {
            if (i % 3 == a && i % 5 == b && i % 7 == c)
            {
                output = i;
                printf("Case %d: %d\n", ++kase, i);
            }
        }

        if(output == 0) printf("Case %d: No answer\n", ++ kase);
    }

    return 0;
}