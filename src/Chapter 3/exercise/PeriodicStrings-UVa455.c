#include <stdio.h>
#include <string.h>

int main()

{
    int count;
    scanf("%d", &count);

    while (count--)
    {

        char input[100];
        scanf("%s", input);
        int n = strlen(input);
        if (n > 80) return 0;
        int period = 0;

        for (int i = 1; i <= n; i++)
        {
            if (n % i != 0)
            {
                continue;
            }

            char pattern[i + 1];
            strncpy(pattern, input, i);

            int times = n / i;
            char tmp[n];
            strcpy(tmp, "");

            for (int j = 0; j < times; j++)
            {
                strcat(tmp, pattern);
            }

            if (strcmp(tmp, input) == 0 || i == n)
            {
                period = i;
                break;
            }
        }

        if (count)
        {
            printf("%d\n\n", period);
        }
        else{
            printf("%d\n", period);
        }
    }
    return 0;
}