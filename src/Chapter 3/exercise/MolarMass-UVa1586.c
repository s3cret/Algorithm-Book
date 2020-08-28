#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define size 105

float GetMassByElement(char element);

int main()
{
    int T;
    scanf("%d", &T);

    while(T--)
    {
        char input[size];
        float mass = 0;
        scanf("%s", input);

        char last;
        for (int i = 0; i < strlen(input); i++)
        {
            int count = 0;

            if (isalpha(input[i]))
            {
                last = input[i];
                if (isalpha(input[i + 1]) || i == strlen(input) - 1)
                {
                    count = 1;
                }
            }

            while (isdigit(input[i]))
            {
                int s = input[i] - '0';
                count = count * 10 + s;

                if (!isdigit(input[i + 1]))
                {
                    break;
                }

                i++;

            }


            if (count != 0)
            {
                mass += GetMassByElement(last) * count;
            }
        }
        printf("%.3f\n", mass);

    }

    return 0;
}

float GetMassByElement(char element)
{
    switch (element)
    {
    case 'C':
        return 12.01;

    case 'H':
        return 1.008;

    case 'O':
        return 16.00;

    case 'N':
        return 14.01;
    }

    return 0;
}
