#include<stdio.h>

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        int chicken = i;
        int rabbit = n - i;
        
        if ( 2 * chicken + 4 * rabbit == m)
        {
            printf("%d %d\n", chicken, rabbit);
            return 0;
        }
        
    }

    printf("No Anwser\n");

    return 0;
}

