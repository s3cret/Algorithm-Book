#include <stdio.h>
#include <math.h>
#ifdef LOCAL
#include <util.h>
#endif

#define min(a, b) fmin(a, b)

int main()
{
    FILE *fin = stdin;
#ifdef LOCAL
    fin = GetFileInput(__FILE__);
#endif

    int n, kase;
    while (fscanf(fin, "%d", &n) == 1 && n)
    {
        printf("Game %d:\n", ++kase);

        int answer[n], guess[n];
        for (int i = 0; i < n; i++)
        {
            fscanf(fin, "%d", &answer[i]);
        }

        for (;;)
        {
            int A = 0, B = 0;

            for (int i = 0; i < n; i++)
            {
                fscanf(fin, "%d", &guess[i]);
                if (guess[i] == answer[i])
                {
                    A++;
                }
            }
            if (guess[0] == 0)
                break;

            for (int d = 1; d <= 9; d++)
            {
                int c1 = 0, c2 = 0;
                for (int i = 0; i < n; i++)
                {
                    if (answer[i] == d)
                    {
                        c1++;
                    }

                    if (guess[i] == d)
                    {
                        c2++;
                    }
                }
                // printf("d = %d, c1 = %d, c2 = %d\n", d, c1, c2);
                if (c1 <= c2)
                {
                    B += c1;
                }
                else
                {
                    B += c2;
                }
            }
            printf("    (%d,%d)\n", A, B - A);
        }
    }

    return 0;
}