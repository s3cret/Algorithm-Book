#include <stdio.h>
#include <string.h>

int main()
{
    int t; 
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int output[10];
        memset(output, 0, sizeof(output));

        for (int i = 1; i <= n; i++)
        {
            char tmp[6];
            sprintf(tmp, "%d", i);

            for (int i = 0; i < strlen(tmp); i++)
            {
                int x = tmp[i] - '0';
                output[x] += 1;
            }
        }

        for (int i = 0; i < 9; i++)
        {
            printf("%d ", output[i]);
        }
        printf("%d", output[9]);
        printf("\n");

    }

    return 0;
}